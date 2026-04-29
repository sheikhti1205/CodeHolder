from __future__ import annotations

import argparse
import hashlib
import json
import os
import subprocess
import sys
import time
import traceback
import urllib.error
import urllib.request
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from typing import Any

import config

try:
    import config_private
except ImportError:  # pragma: no cover - normal for synced copies.
    config_private = None


VERSION = "0.1.0"
GROQ_CHAT_URL = "https://api.groq.com/openai/v1/chat/completions"


class ProviderAPIError(RuntimeError):
    def __init__(self, status: int | None, detail: str):
        super().__init__(detail)
        self.status = status
        self.detail = detail


def setting(name: str, default: Any = None) -> Any:
    private_value = getattr(config_private, name, None) if config_private else None
    public_value = getattr(config, name, None)
    return os.getenv(name) or private_value or public_value or default


def default_model() -> str:
    return str(setting("GROQ_MODEL", "groq/compound-mini"))


def embedding_model() -> str:
    return "nomic-embed-text:latest"


def embedding_dimensions() -> int:
    return int(setting("EMBEDDING_DIMENSIONS", 768))


def web_search_enabled() -> bool:
    value = setting("ENABLE_WEB_SEARCH", False)
    if isinstance(value, str):
        return value.strip().lower() in {"1", "true", "yes", "on"}
    return bool(value)


def fallback_models() -> list[str]:
    value = setting("GROQ_FALLBACK_MODELS", [])
    if isinstance(value, str):
        return [item.strip() for item in value.split(",") if item.strip()]
    if isinstance(value, list):
        return [str(item) for item in value if str(item).strip()]
    return []


def api_key() -> str:
    return str(setting("GROQ_API_KEY", "")).strip()


def node_runtime_path() -> str:
    return str(
        setting(
            "NODE_RUNTIME_PATH",
            "C:/Users/sheik/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/bin/node.exe",
        )
    )


def utc_now() -> str:
    return time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime())


def resolve_model(model: str | None) -> str:
    if not model:
        return default_model()
    aliases = {
        "groq": default_model(),
        "groq:latest": default_model(),
        "groq/compound-mini": "groq/compound-mini",
        "groq/compound": "groq/compound",
        "llama3.1:latest": "llama-3.1-8b-instant",
        "nomic-embed-text": embedding_model(),
        "nomic-embed-text:latest": embedding_model(),
    }
    return aliases.get(model, model)


def model_tag(name: str, size: int = 1) -> dict[str, Any]:
    return {
        "name": name,
        "model": name,
        "modified_at": "2026-04-29T00:00:00Z",
        "size": size,
        "digest": name.replace(":", "-"),
        "details": {
            "parent_model": "",
            "format": "groq",
            "family": "groq",
            "families": ["groq"],
            "parameter_size": "online",
            "quantization_level": "none",
        },
    }


def ollama_tags() -> dict[str, Any]:
    primary = default_model()
    names = [
        "groq:latest",
        "groq/compound-mini",
        "groq/compound",
        "llama3.1:latest",
        "openai/gpt-oss-20b",
        "openai/gpt-oss-120b",
        "llama3.1:latest",
        "nomic-embed-text",
        "nomic-embed-text:latest",
        primary,
    ]
    return {"models": [model_tag(name) for name in dict.fromkeys(names)]}


def extract_groq_text(result: dict[str, Any]) -> str:
    text = result.get("choices", [{}])[0].get("message", {}).get("content", "")
    if isinstance(text, list):
        text = "".join(str(item.get("text", item)) if isinstance(item, dict) else str(item) for item in text)
    text = str(text).strip()
    if text:
        return text
    return json.dumps(result, ensure_ascii=False)


def extract_groq_sources(result: dict[str, Any]) -> list[dict[str, str]]:
    sources: list[dict[str, str]] = []
    tools = result.get("choices", [{}])[0].get("message", {}).get("executed_tools", [])
    for tool in tools if isinstance(tools, list) else []:
        search_results = tool.get("search_results", {}) if isinstance(tool, dict) else {}
        results = search_results.get("results", []) if isinstance(search_results, dict) else []
        for item in results:
            title = str(item.get("title", "")).strip()
            uri = str(item.get("url", "")).strip()
            if uri and not any(source["uri"] == uri for source in sources):
                sources.append({"title": title or uri, "uri": uri})
    return sources


def add_sources_to_text(text: str, sources: list[dict[str, str]]) -> str:
    if not sources:
        return text
    lines = ["", "Sources:"]
    for index, source in enumerate(sources[:8], 1):
        lines.append(f"{index}. {source['title']} - {source['uri']}")
    return text.rstrip() + "\n" + "\n".join(lines)


def normalize_chat_messages(messages: list[dict[str, Any]]) -> list[dict[str, Any]]:
    normalized = []
    for message in messages:
        role = message.get("role", "user")
        if role not in {"system", "user", "assistant"}:
            role = "user"

        content = message.get("content", "")
        if isinstance(content, list):
            parts = []
            for item in content:
                if isinstance(item, dict):
                    parts.append(str(item.get("text") or item.get("content") or ""))
                else:
                    parts.append(str(item))
            content = "\n".join(part for part in parts if part)

        normalized.append({"role": role, "content": str(content)})
    return normalized or [{"role": "user", "content": ""}]


def extract_system_messages(messages: list[dict[str, Any]]) -> str:
    parts = []
    for message in messages:
        if message.get("role") == "system":
            content = message.get("content", "")
            if isinstance(content, list):
                content = "\n".join(str(item.get("text", item)) if isinstance(item, dict) else str(item) for item in content)
            if content:
                parts.append(str(content))
    return "\n\n".join(parts)


def deterministic_embedding(text: str, dimensions: int) -> list[float]:
    values = []
    seed = text.encode("utf-8")
    counter = 0
    while len(values) < dimensions:
        digest = hashlib.sha256(seed + counter.to_bytes(4, "big")).digest()
        for index in range(0, len(digest), 4):
            integer = int.from_bytes(digest[index : index + 4], "big")
            values.append((integer / 0xFFFFFFFF) * 2 - 1)
            if len(values) >= dimensions:
                break
        counter += 1
    return values


class GroqClient:
    def __init__(self, key: str | None = None):
        self.key = key if key is not None else api_key()

    def _post(self, payload: dict[str, Any]) -> dict[str, Any]:
        if not self.key:
            raise RuntimeError("GROQ_API_KEY is missing. Add it to config_private.py.")
        script = """
const https = require('https');
const [url, key, payloadJson] = process.argv.slice(1);
const data = Buffer.from(payloadJson, 'utf8');
const req = https.request(url, {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': `Bearer ${key}`,
    'Content-Length': data.length,
  },
}, (res) => {
  let body = '';
  res.on('data', chunk => body += chunk);
  res.on('end', () => {
    process.stdout.write(JSON.stringify({ status: res.statusCode || 0, body }));
  });
});
req.on('error', (err) => {
  process.stdout.write(JSON.stringify({ status: 0, error: String(err) }));
});
req.write(data);
req.end();
""".strip()
        try:
            completed = subprocess.run(
                [node_runtime_path(), "-e", script, GROQ_CHAT_URL, self.key, json.dumps(payload)],
                capture_output=True,
                timeout=180,
                check=False,
            )
        except FileNotFoundError as exc:
            raise RuntimeError(f"Node runtime not found at {node_runtime_path()}") from exc
        except subprocess.TimeoutExpired as exc:
            raise ProviderAPIError(None, "Groq request timed out via Node transport.") from exc

        stdout_text = completed.stdout.decode("utf-8", errors="replace") if completed.stdout else ""
        stderr_text = completed.stderr.decode("utf-8", errors="replace") if completed.stderr else ""

        if completed.returncode != 0:
            detail = stderr_text.strip() or stdout_text.strip() or f"exit code {completed.returncode}"
            raise ProviderAPIError(None, f"Groq Node transport failed: {detail}")

        try:
            wrapper = json.loads(stdout_text)
        except json.JSONDecodeError as exc:
            raise ProviderAPIError(None, f"Groq Node transport returned invalid JSON: {stdout_text[:500]}") from exc

        status = int(wrapper.get("status", 0) or 0)
        if status and 200 <= status < 300:
            return json.loads(wrapper.get("body", "{}"))

        if status:
            raise ProviderAPIError(status, f"Groq API HTTP {status}: {wrapper.get('body', '')}")
        raise ProviderAPIError(None, wrapper.get("error", "Could not reach Groq API."))

    def _chat_completion(self, messages: list[dict[str, str]], model: str | None = None, system: str | None = None) -> str:
        if system:
            messages = [{"role": "system", "content": system}, *messages]

        models = [resolve_model(model), *fallback_models()]

        last_error: Exception | None = None
        for candidate_model in dict.fromkeys(models):
            try:
                result = self._post(
                    {
                        "model": candidate_model,
                        "messages": messages,
                        "temperature": 0.7,
                    }
                )
                print(f"[{utc_now()}] groq model={candidate_model}", file=sys.stderr)
                return add_sources_to_text(extract_groq_text(result), extract_groq_sources(result))
            except ProviderAPIError as exc:
                last_error = exc
                if exc.status not in {429, 503}:
                    break

        if last_error:
            raise last_error
        raise RuntimeError("Groq API call failed.")

    def generate(self, prompt: str, model: str | None = None, system: str | None = None) -> str:
        return self._chat_completion([{"role": "user", "content": prompt}], model=model, system=system)

    def chat(self, messages: list[dict[str, Any]], model: str | None = None) -> str:
        return self._chat_completion(normalize_chat_messages(messages), model=model)

    def embed(self, text: str) -> list[float]:
        return deterministic_embedding(text, embedding_dimensions())


class ProxyHandler(BaseHTTPRequestHandler):
    server_version = "AppFlowyGeminiProxy/0.1"

    @property
    def client(self) -> GroqClient:
        return self.server.gemini_client  # type: ignore[attr-defined]

    def log_message(self, fmt: str, *args: Any) -> None:
        sys.stderr.write("[%s] %s\n" % (utc_now(), fmt % args))

    def _read_json(self) -> dict[str, Any]:
        length = int(self.headers.get("Content-Length", "0") or "0")
        if length <= 0:
            return {}
        raw = self.rfile.read(length)
        if not raw:
            return {}
        return json.loads(raw.decode("utf-8"))

    def _send_headers(self, status: int = 200, content_type: str = "application/json") -> None:
        self.send_response(status)
        self.send_header("Content-Type", content_type)
        self.send_header("Access-Control-Allow-Origin", "*")
        self.send_header("Access-Control-Allow-Headers", "content-type, authorization")
        self.send_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS")
        self.end_headers()

    def _send_json(self, data: dict[str, Any], status: int = 200) -> None:
        self._send_headers(status)
        self.wfile.write(json.dumps(data, ensure_ascii=False).encode("utf-8"))

    def _send_ndjson(self, rows: list[dict[str, Any]]) -> None:
        self._send_headers(200, "application/x-ndjson")
        for row in rows:
            self.wfile.write(json.dumps(row, ensure_ascii=False).encode("utf-8") + b"\n")
            self.wfile.flush()

    def _error(self, exc: Exception, status: int = 502) -> None:
        self._send_json({"error": str(exc), "done": True}, status)

    def do_OPTIONS(self) -> None:
        self._send_headers(204)

    def do_GET(self) -> None:
        if self.path in {"/", "/health"}:
            self._send_json({"status": "ok", "service": "appflowy-gemini-proxy", "version": VERSION})
        elif self.path == "/api/version":
            self._send_json({"version": VERSION})
        elif self.path == "/api/tags":
            self._send_json(ollama_tags())
        elif self.path == "/api/ps":
            self._send_json({"models": []})
        else:
            self._send_json({"error": f"Unknown endpoint: {self.path}"}, HTTPStatus.NOT_FOUND)

    def do_POST(self) -> None:
        try:
            body = self._read_json()
            if self.path == "/api/generate":
                self.handle_generate(body)
            elif self.path == "/api/chat":
                self.handle_chat(body)
            elif self.path == "/api/show":
                self.handle_show(body)
            elif self.path in {"/api/embeddings", "/api/embed"}:
                self.handle_embed(body)
            else:
                self._send_json({"error": f"Unknown endpoint: {self.path}"}, HTTPStatus.NOT_FOUND)
        except Exception as exc:
            traceback.print_exc()
            self._error(exc)

    def handle_generate(self, body: dict[str, Any]) -> None:
        model = body.get("model", "groq:latest")
        prompt = str(body.get("prompt", ""))
        system = body.get("system")
        answer = self.client.generate(prompt, model=model, system=system)
        base = {
            "model": model,
            "created_at": utc_now(),
            "done": True,
            "done_reason": "stop",
            "total_duration": 0,
            "load_duration": 0,
            "prompt_eval_count": len(prompt.split()),
            "eval_count": len(answer.split()),
        }
        if body.get("stream", False):
            rows = []
            for chunk in chunk_text(answer):
                row = dict(base)
                row.update({"response": chunk, "done": False})
                rows.append(row)
            final = dict(base)
            final["response"] = ""
            rows.append(final)
            self._send_ndjson(rows)
        else:
            base["response"] = answer
            self._send_json(base)

    def handle_chat(self, body: dict[str, Any]) -> None:
        model = body.get("model", "groq:latest")
        messages = body.get("messages", [])
        answer = self.client.chat(messages, model=model)
        base = {
            "model": model,
            "created_at": utc_now(),
            "done": True,
            "done_reason": "stop",
            "total_duration": 0,
            "load_duration": 0,
            "prompt_eval_count": len(str(messages).split()),
            "eval_count": len(answer.split()),
        }
        if body.get("stream", False):
            rows = []
            for chunk in chunk_text(answer):
                row = dict(base)
                row.update({"message": {"role": "assistant", "content": chunk}, "done": False})
                rows.append(row)
            final = dict(base)
            final["message"] = {"role": "assistant", "content": ""}
            rows.append(final)
            self._send_ndjson(rows)
        else:
            base["message"] = {"role": "assistant", "content": answer}
            self._send_json(base)

    def handle_show(self, body: dict[str, Any]) -> None:
        name = body.get("model") or body.get("name") or "groq:latest"
        self._send_json(
            {
                "license": "Groq API",
                "modelfile": f"FROM {resolve_model(name)}",
                "parameters": "",
                "template": "{{ .Prompt }}",
                "details": model_tag(str(name))["details"],
                "model_info": {"general.architecture": "groq", "proxy.default_model": default_model()},
                "capabilities": ["completion", "chat", "embedding"],
            }
        )

    def handle_embed(self, body: dict[str, Any]) -> None:
        value = body.get("input", body.get("prompt", ""))
        inputs = value if isinstance(value, list) else [value]
        embeddings = [self.client.embed(str(item)) for item in inputs]
        if self.path == "/api/embeddings":
            self._send_json({"embedding": embeddings[0] if embeddings else []})
        else:
            self._send_json({"model": body.get("model", embedding_model()), "embeddings": embeddings})


def chunk_text(text: str, size: int = 96) -> list[str]:
    if not text:
        return [""]
    return [text[i : i + size] for i in range(0, len(text), size)]


def run(host: str, port: int) -> None:
    server = ThreadingHTTPServer((host, port), ProxyHandler)
    server.gemini_client = GroqClient()  # type: ignore[attr-defined]
    print(f"AppFlowy Groq proxy listening on http://{host}:{port}")
    print(f"Default Groq model: {default_model()}")
    server.serve_forever()


def main() -> None:
    parser = argparse.ArgumentParser(description="Ollama-compatible Groq proxy for AppFlowy.")
    parser.add_argument("--host", default=str(setting("HOST", "127.0.0.1")))
    parser.add_argument("--port", default=int(setting("PORT", 11434)), type=int)
    args = parser.parse_args()
    run(args.host, args.port)


if __name__ == "__main__":
    main()

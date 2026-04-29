"""Shareable config for the AppFlowy Gemini proxy.

This file is safe to sync. Put private secrets in config_private.py instead.
"""

HOST = "127.0.0.1"
PORT = 11434

# Groq chat settings. This file is safe to sync.
GROQ_API_KEY = ""
GROQ_MODEL = "groq/compound-mini"
GROQ_FALLBACK_MODELS = [
    "groq/compound",
    "openai/gpt-oss-20b",
    "llama-3.1-8b-instant",
]
NODE_RUNTIME_PATH = "C:/Users/sheik/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/bin/node.exe"

# AppFlowy expects Nomic-style embeddings. Groq chat models do
# not provide embeddings, so the proxy returns deterministic local vectors.
EMBEDDING_DIMENSIONS = 768

ENABLE_WEB_SEARCH = False

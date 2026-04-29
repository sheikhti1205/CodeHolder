import json
import threading
import unittest
import urllib.request
from http.server import ThreadingHTTPServer

import appflowy_gemini_proxy as proxy


class FakeProviderClient:
    def generate(self, prompt, model=None, system=None):
        return f"generated: {prompt}"

    def chat(self, messages, model=None):
        return "chat response"

    def embed(self, text):
        return [0.1, 0.2, 0.3]


class ProxyTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.server = ThreadingHTTPServer(("127.0.0.1", 0), proxy.ProxyHandler)
        cls.server.gemini_client = FakeProviderClient()
        cls.port = cls.server.server_address[1]
        cls.thread = threading.Thread(target=cls.server.serve_forever, daemon=True)
        cls.thread.start()

    @classmethod
    def tearDownClass(cls):
        cls.server.shutdown()
        cls.thread.join(timeout=5)

    def request(self, path, body=None):
        url = f"http://127.0.0.1:{self.port}{path}"
        data = None if body is None else json.dumps(body).encode("utf-8")
        req = urllib.request.Request(url, data=data, headers={"Content-Type": "application/json"})
        with urllib.request.urlopen(req, timeout=10) as response:
            return response.headers.get_content_type(), response.read().decode("utf-8")

    def test_tags_include_groq_aliases(self):
        _, raw = self.request("/api/tags")
        data = json.loads(raw)
        names = [item["name"] for item in data["models"]]
        self.assertIn("groq:latest", names)
        self.assertIn("groq/compound-mini", names)
        self.assertIn("groq/compound", names)
        self.assertIn("llama3.1:latest", names)
        self.assertIn("nomic-embed-text:latest", names)

    def test_generate_non_stream(self):
        _, raw = self.request("/api/generate", {"model": "groq:latest", "prompt": "hi", "stream": False})
        data = json.loads(raw)
        self.assertEqual(data["response"], "generated: hi")
        self.assertTrue(data["done"])

    def test_generate_stream(self):
        content_type, raw = self.request("/api/generate", {"prompt": "hi", "stream": True})
        self.assertEqual(content_type, "application/x-ndjson")
        rows = [json.loads(line) for line in raw.splitlines()]
        self.assertFalse(rows[0]["done"])
        self.assertTrue(rows[-1]["done"])

    def test_chat_non_stream(self):
        _, raw = self.request("/api/chat", {"messages": [{"role": "user", "content": "hello"}]})
        data = json.loads(raw)
        self.assertEqual(data["message"]["content"], "chat response")

    def test_system_messages_are_extracted_not_sent_as_user_turns(self):
        messages = [
            {"role": "system", "content": "System instruction"},
            {"role": "user", "content": "Question"},
        ]
        self.assertEqual(proxy.extract_system_messages(messages), "System instruction")
        normalized = proxy.normalize_chat_messages(messages)
        self.assertEqual(len(normalized), 2)
        self.assertEqual(normalized[1]["content"], "Question")

    def test_embeddings(self):
        _, raw = self.request("/api/embeddings", {"prompt": "hello"})
        data = json.loads(raw)
        self.assertEqual(data["embedding"], [0.1, 0.2, 0.3])

    def test_deterministic_embedding_dimensions(self):
        embedding = proxy.deterministic_embedding("hello", 768)
        self.assertEqual(len(embedding), 768)
        self.assertEqual(embedding, proxy.deterministic_embedding("hello", 768))

    def test_groq_sources_are_appended(self):
        result = {
            "choices": [
                {
                    "message": {
                        "content": "Answer.",
                        "executed_tools": [
                            {
                                "search_results": {
                                    "results": [
                                        {"title": "Example", "url": "https://example.com"},
                                        {"title": "Example", "url": "https://example.com"},
                                    ]
                                }
                            }
                        ],
                    }
                }
            ]
        }
        sources = proxy.extract_groq_sources(result)
        self.assertEqual(sources, [{"title": "Example", "uri": "https://example.com"}])
        self.assertIn("Sources:", proxy.add_sources_to_text("Answer.", sources))


if __name__ == "__main__":
    unittest.main()

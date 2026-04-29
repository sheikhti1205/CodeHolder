# AppFlowy Groq Proxy

Tiny Windows-friendly Ollama-compatible proxy for AppFlowy. AppFlowy talks to `http://localhost:11434` as if it were Ollama; this server forwards chat requests to Groq.

## Files

- `appflowy_gemini_proxy.py` - the proxy server.
- `config.py` - safe-to-sync defaults.
- `config_private.py` - private API key and model settings. Ignored by Git.
- `start_proxy.ps1` - starts the local proxy.
- `stop_proxy.ps1` - stops the local proxy.
- `install_autostart.ps1` - starts the proxy automatically at Windows logon.
- `uninstall_autostart.ps1` - removes the autostart task.
- `run_tests.ps1` - runs local tests.

## Private Key

`config_private.py` now contains the Groq API key and the default Groq model:

```python
GROQ_MODEL = "groq/compound-mini"
```

`groq/compound-mini` is the default because Groq documents it as a built-in tool system with web search and code execution.

## Run

```powershell
.\start_proxy.ps1
```

In AppFlowy, set the Ollama server URL to:

```text
http://localhost:11434
```

Use one of these chat model names:

```text
groq:latest
groq/compound-mini
groq/compound
llama3.1:latest
openai/gpt-oss-20b
openai/gpt-oss-120b
```

For embeddings, keep:

```text
nomic-embed-text
```

The embedding endpoint returns deterministic local 768-dimensional vectors because Groq chat models do not provide embeddings.

## Stop

```powershell
.\stop_proxy.ps1
```

## Start Automatically After Restart

```powershell
.\install_autostart.ps1
```

This installs either a Windows Scheduled Task or, if Windows denies that, a Startup-folder shortcut.

## Remove Autostart

```powershell
.\uninstall_autostart.ps1
```

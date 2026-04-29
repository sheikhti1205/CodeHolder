$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$VenvPython = Join-Path $Root ".venv\Scripts\python.exe"

if (-not (Test-Path -LiteralPath $VenvPython)) {
    py -3 -m venv (Join-Path $Root ".venv")
}

Push-Location $Root
try {
    & $VenvPython -m unittest discover -s tests -v
} finally {
    Pop-Location
}

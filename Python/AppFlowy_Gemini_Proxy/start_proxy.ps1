$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$Runtime = Join-Path $Root ".runtime"
$VenvPython = Join-Path $Root ".venv\Scripts\python.exe"
$PidFile = Join-Path $Runtime "proxy.pid"
$LogFile = Join-Path $Runtime "proxy.log"
$ErrFile = Join-Path $Runtime "proxy.err.log"

New-Item -ItemType Directory -Force -Path $Runtime | Out-Null

if (-not (Test-Path -LiteralPath $VenvPython)) {
    py -3 -m venv (Join-Path $Root ".venv")
}

$ExistingProxy = Get-CimInstance Win32_Process |
    Where-Object { $_.Name -like "python*" -and $_.CommandLine -and $_.CommandLine.Contains($Root) -and $_.CommandLine.Contains("appflowy_gemini_proxy.py") } |
    Select-Object -First 1
if ($ExistingProxy) {
    Set-Content -LiteralPath $PidFile -Value $ExistingProxy.ProcessId
    Write-Output "Proxy already running with PID $($ExistingProxy.ProcessId)"
    exit 0
}

if (Test-Path -LiteralPath $PidFile) {
    $ExistingPid = Get-Content -LiteralPath $PidFile -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($ExistingPid -and (Get-Process -Id ([int]$ExistingPid) -ErrorAction SilentlyContinue)) {
        Write-Output "Proxy already running with PID $ExistingPid"
        exit 0
    }
}

$PortBusy = Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort 11434 -State Listen -ErrorAction SilentlyContinue
if ($PortBusy) {
    throw "Port 11434 is already in use. Stop Ollama or another proxy first."
}

$Process = Start-Process `
    -FilePath $VenvPython `
    -ArgumentList @("appflowy_gemini_proxy.py", "--host", "127.0.0.1", "--port", "11434") `
    -WorkingDirectory $Root `
    -RedirectStandardOutput $LogFile `
    -RedirectStandardError $ErrFile `
    -WindowStyle Hidden `
    -PassThru

Set-Content -LiteralPath $PidFile -Value $Process.Id
Write-Output "Started AppFlowy Gemini proxy on http://localhost:11434 with PID $($Process.Id)"
Write-Output "Log: $LogFile"

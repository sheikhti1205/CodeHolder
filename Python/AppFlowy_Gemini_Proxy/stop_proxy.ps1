$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$Runtime = Join-Path $Root ".runtime"
$PidFile = Join-Path $Runtime "proxy.pid"

$Stopped = $false

$ProxyProcesses = Get-CimInstance Win32_Process |
    Where-Object { $_.Name -like "python*" -and $_.CommandLine -and $_.CommandLine.Contains($Root) -and $_.CommandLine.Contains("appflowy_gemini_proxy.py") }

foreach ($ProxyProcess in $ProxyProcesses) {
    Stop-Process -Id ([int]$ProxyProcess.ProcessId) -Force -ErrorAction SilentlyContinue
    Write-Output "Stopped AppFlowy Gemini proxy with PID $($ProxyProcess.ProcessId)"
    $Stopped = $true
}

if (Test-Path -LiteralPath $PidFile) {
    $PidValue = Get-Content -LiteralPath $PidFile -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($PidValue -and (Get-Process -Id ([int]$PidValue) -ErrorAction SilentlyContinue)) {
        Stop-Process -Id ([int]$PidValue) -Force -ErrorAction SilentlyContinue
        Write-Output "Stopped AppFlowy Gemini proxy with PID $PidValue"
        $Stopped = $true
    }
}

if (-not $Stopped) {
    Write-Output "Proxy process was not running."
}

Remove-Item -LiteralPath $PidFile -Force -ErrorAction SilentlyContinue

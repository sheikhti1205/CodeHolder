$ErrorActionPreference = "Stop"

$TaskName = "AppFlowy Gemini Proxy"
$StartupShortcut = Join-Path ([Environment]::GetFolderPath("Startup")) "AppFlowy Gemini Proxy.lnk"
$Task = Get-ScheduledTask -TaskName $TaskName -ErrorAction SilentlyContinue
if ($Task) {
    Unregister-ScheduledTask -TaskName $TaskName -Confirm:$false
    Write-Output "Removed Windows autostart task: $TaskName"
} else {
    Write-Output "Autostart task was not installed."
}

if (Test-Path -LiteralPath $StartupShortcut) {
    Remove-Item -LiteralPath $StartupShortcut -Force
    Write-Output "Removed Startup shortcut: $StartupShortcut"
}

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$TaskName = "AppFlowy Gemini Proxy"
$StartScript = Join-Path $Root "start_proxy.ps1"
$StartupShortcut = Join-Path ([Environment]::GetFolderPath("Startup")) "AppFlowy Gemini Proxy.lnk"

$Action = New-ScheduledTaskAction `
    -Execute "powershell.exe" `
    -Argument "-NoProfile -ExecutionPolicy Bypass -File `"$StartScript`""

$Trigger = New-ScheduledTaskTrigger -AtLogOn
$Settings = New-ScheduledTaskSettingsSet `
    -AllowStartIfOnBatteries `
    -DontStopIfGoingOnBatteries `
    -ExecutionTimeLimit (New-TimeSpan -Hours 0)

try {
    Register-ScheduledTask `
        -TaskName $TaskName `
        -Action $Action `
        -Trigger $Trigger `
        -Settings $Settings `
        -Description "Starts the local Ollama-compatible Gemini proxy for AppFlowy at Windows logon." `
        -Force `
        -ErrorAction Stop | Out-Null

    Write-Output "Installed Windows autostart task: $TaskName"
} catch {
    $Shell = New-Object -ComObject WScript.Shell
    $Shortcut = $Shell.CreateShortcut($StartupShortcut)
    $Shortcut.TargetPath = "powershell.exe"
    $Shortcut.Arguments = "-NoProfile -ExecutionPolicy Bypass -File `"$StartScript`""
    $Shortcut.WorkingDirectory = $Root
    $Shortcut.WindowStyle = 7
    $Shortcut.Description = "Starts the local Ollama-compatible Gemini proxy for AppFlowy at Windows logon."
    $Shortcut.Save()
    Write-Output "Task Scheduler was denied, so installed Startup shortcut instead: $StartupShortcut"
}

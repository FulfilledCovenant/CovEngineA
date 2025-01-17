$outputFile = "status.txt"

function Log-Output {
    param(
        [string]$message
    )
    Write-Output $message
    $message | Out-File -FilePath $outputFile -Append
}

Log-Output "------------------------------------"
Log-Output "General Tweaks"
Log-Output "------------------------------------"

$regPath = "HKCU:\Software\Policies\Microsoft\Windows\Explorer"
$valueName = "DisableNotificationCenter"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Action Center: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance"
$valueName = "MaintenanceDisabled"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Automatic Maintenance: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\Windows Search"
$valueName = "AllowCortana"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Cortana: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Attachments"
$valueName = "SaveZoneInformation"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Downloads Blocking: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\WindowsUpdate"
$valueName = "ExcludeWUDriversInQualityUpdate"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Driver Updates: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\Windows Error Reporting"
$valueName = "Disabled"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Error Reporting: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\Personalization"
$valueName = "NoLockScreen"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Lock Screen: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\EdgeUpdate"
$valueName = "Allowsxs"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Microsoft Edge Auto-Installation: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\MRT"
$valueName = "DontOfferThroughWUAU"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable MRT Updates: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\WindowsStore"
$valueName = "AutoDownload"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Store Auto-Updates: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows NT\SystemRestore"
$valueName = "DisableConfig"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable System Restore (DisableConfig): $regPath\$valueName = $value"
$valueName = "DisableSR"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable System Restore (DisableSR): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System"
$valueName = "EnableLUA"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable UAC: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\WindowsInkWorkspace"
$valueName = "AllowWindowsInkWorkspace"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Windows Ink Workspace: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\WindowsUpdate\AU"
$valueName = "NoAutoUpdate"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Windows Updates: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\WindowsUpdate\UpdatePolicy\Settings"
$valueName = "Paused"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Pause Windows Updates (Paused): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\WindowsUpdate\UpdatePolicy"
$valueName = "PauseUpdatesExpiryTime"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Pause Windows Updates (PauseUpdatesExpiryTime): $regPath\$valueName = $value"

Log-Output "`r`n------------------------------------"
Log-Output "Extra Tweaks"
Log-Output "------------------------------------"

$regPath = "HKCU:\Control Panel\Mouse"
$valueName = "MouseSensitivity"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Mouse Acceleration (MouseSensitivity): $regPath\$valueName = $value"
$valueName = "MouseSpeed"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Mouse Acceleration (MouseSpeed): $regPath\$valueName = $value"
$valueName = "MouseThreshold1"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Mouse Acceleration (MouseThreshold1): $regPath\$valueName = $value"
$valueName = "MouseThreshold2"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Mouse Acceleration (MouseThreshold2): $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects"
$valueName = "VisualFXSetting"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize Visual Effects: $regPath\$valueName = $value"

$regPath = "HKCU:\Control Panel\Desktop"
$valueName = "WaitToKillAppTimeout"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Reduce Shutdown Time (WaitToKillAppTimeout): $regPath\$valueName = $value"
$valueName = "HungAppTimeout"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Reduce Shutdown Time (HungAppTimeout): $regPath\$valueName = $value"
$valueName = "AutoEndTasks"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Reduce Shutdown Time (AutoEndTasks): $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers"
$valueName = "DisableAutoplay"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Autorun/Autoplay (DisableAutoplay): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "NoDriveTypeAutoRun"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Autorun/Autoplay (NoDriveTypeAutoRun): $regPath\$valueName = $value"

Log-Output "`r`n------------------------------------"
Log-Output "Performance Tweaks"
Log-Output "------------------------------------"

Log-Output "Configure BCDEdit: Requires manual check using 'bcdedit /enum'"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile"
$valueName = "NetworkThrottlingIndex"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (NetworkThrottlingIndex): $regPath\$valueName = $value"
$valueName = "SystemResponsiveness"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (SystemResponsiveness): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile\Tasks\Games"
$valueName = "Affinity"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (Affinity): $regPath\$valueName = $value"
$valueName = "Background Only"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (Background Only): $regPath\$valueName = $value"
$valueName = "Clock Rate"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (Clock Rate): $regPath\$valueName = $value"
$valueName = "GPU Priority"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (GPU Priority): $regPath\$valueName = $value"
$valueName = "Priority"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (Priority): $regPath\$valueName = $value"
$valueName = "Scheduling Category"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (Scheduling Category): $regPath\$valueName = $value"
$valueName = "SFIO Priority"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure MMCSS (SFIO Priority): $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Classes\Local Settings\Software\Microsoft\Windows\Shell\Bags\AllFolders\Shell"
$valueName = "FolderType"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Automatic Folder Discovery: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\BackgroundAccessApplications"
$valueName = "GlobalUserDisabled"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Background Apps: $regPath\$valueName = $value"

Log-Output "Disable Boot Tracing: Requires manual check using 'bcdedit /enum'"

$regPath = "HKLM:\SOFTWARE\Microsoft\FTH"
$valueName = "Enabled"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Fault Tolerant Heap: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management"
$valueName = "DisablePagingExecutive"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Paging Settings: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management\PrefetchParameters"
$valueName = "EnablePrefetcher"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Prefetch (EnablePrefetcher): $regPath\$valueName = $value"
$valueName = "EnableSuperfetch"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Prefetch (EnableSuperfetch): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control"
$valueName = "SvcHostSplitThresholdInKB"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Service Host Splitting: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\power"
$valueName = "Start"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Sleep Study: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management"
$valueName = "FeatureSettingsOverride"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Spectre and Meltdown (FeatureSettingsOverride): $regPath\$valueName = $value"
$valueName = "FeatureSettingsOverrideMask"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Spectre and Meltdown (FeatureSettingsOverrideMask): $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize"
$valueName = "StartupDelayInMSec"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Startup Apps Delay: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\DeviceGuard"
$valueName = "EnableVirtualizationBasedSecurity"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable VBS (EnableVirtualizationBasedSecurity): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\LSA"
$valueName = "LsaCfgFlags"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable VBS (LsaCfgFlags): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows Defender"
$valueName = "DisableAntiSpyware"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Windows Defender (DisableAntiSpyware): $regPath\$valueName = $value"
$valueName = "DisableAntiVirus"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Windows Defender (DisableAntiVirus): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\WinDefend"
$valueName = "Start"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Windows Defender (Start): $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\DWM"
$valueName = "OverlayTestMode"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize DWM Settings: $regPath\$valueName = $value"

$regPath = "HKCU:\System\GameConfigStore"
$valueName = "GameDVR_FSEBehaviorMode"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize FSO Settings (GameDVR_FSEBehaviorMode): $regPath\$valueName = $value"
$valueName = "GameDVR_HonorUserFSEBehaviorMode"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize FSO Settings (GameDVR_HonorUserFSEBehaviorMode): $regPath\$valueName = $value"
$valueName = "GameDVR_FSEBehavior"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize FSO Settings (GameDVR_FSEBehavior): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\FileSystem"
$valueName = "NtfsDisable8dot3NameCreation"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize NTFS (NtfsDisable8dot3NameCreation): $regPath\$valueName = $value"
$valueName = "NtfsMemoryUsage"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize NTFS (NtfsMemoryUsage): $regPath\$valueName = $value"
$valueName = "NtfsDisableLastAccessUpdate"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize NTFS (NtfsDisableLastAccessUpdate): $regPath\$valueName = $value"

$regPath = "HKCU:\Control Panel\Mouse"
$valueName = "MouseSensitivity"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize Mouse Settings (MouseSensitivity): $regPath\$valueName = $value"
$valueName = "SmoothMouseXCurve"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize Mouse Settings (SmoothMouseXCurve): $regPath\$valueName = $value"
$valueName = "SmoothMouseYCurve"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize Mouse Settings (SmoothMouseYCurve): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\stornvme\Parameters\Device"
$valueName = "ForcedUnitAccess"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Optimize NVMe Settings: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\PriorityControl"
$valueName = "Win32PrioritySeparation"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Win32 Priority Separation: $regPath\$valueName = $value"

Log-Output "`r`n------------------------------------"
Log-Output "Privacy Tweaks"
Log-Output "------------------------------------"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\lfsvc"
$valueName = "Start"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Location Tracking (lfsvc Start): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\LocationAndSensors"
$valueName = "DisableLocation"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Location Tracking (DisableLocation): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\DataCollection"
$valueName = "AllowTelemetry"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Telemetry (AllowTelemetry): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\DiagTrack"
$valueName = "Start"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Telemetry (DiagTrack Start): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\dmwappushservice"
$valueName = "Start"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Telemetry (dmwappushservice Start): $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\LocationAndSensors"
$valueName = "DisableLocation"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable App Access to Location: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\DataCollection"
$valueName = "DoNotShowFeedbackNotifications"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Feedback: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\DataCollection"
$valueName = "AllowTelemetry"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Diagnostic Data: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\CloudContent"
$valueName = "DisableTailoredExperiencesWithDiagnosticData"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Tailored Experiences: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\System"
$valueName = "EnableActivityFeed"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Activity History (EnableActivityFeed): $regPath\$valueName = $value"
$valueName = "PublishUserActivities"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Activity History (PublishUserActivities): $regPath\$valueName = $value"
$valueName = "UploadUserActivities"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Activity History (UploadUserActivities): $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\SettingSync"
$valueName = "DisableSettingSync"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Settings Sync (DisableSettingSync): $regPath\$valueName = $value"
$valueName = "DisableSettingSyncUserOverride"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Settings Sync (DisableSettingSyncUserOverride): $regPath\$valueName = $value"

Log-Output "`r`n------------------------------------"
Log-Output "Network Tweaks"
Log-Output "------------------------------------"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters"
$valueName = "EnableTCPA"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure Network Settings (EnableTCPA): $regPath\$valueName = $value"
$valueName = "EnableTCPChimney"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure Network Settings (EnableTCPChimney): $regPath\$valueName = $value"
$valueName = "EnableTCPRSS"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure Network Settings (EnableTCPRSS): $regPath\$valueName = $value"
$valueName = "EnableTCPOffload"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Configure Network Settings (EnableTCPOffload): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters"
$valueName = "DisableBandwidthThrottling"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable SMB Bandwidth Throttling: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Control\Lsa"
$valueName = "RestrictAnonymous"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Restrict Anonymous Access: $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\LanmanServer\Parameters"
$valueName = "NullSessionShares"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Restrict Anonymous Enumeration of Shares: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows NT\DNSClient"
$valueName = "EnableMulticast"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable LLMNR Protocol: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\Psched"
$valueName = "NonBestEffortLimit"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Miscellaneous Network Settings (NonBestEffortLimit): $regPath\$valueName = $value"

$regPath = "HKLM:\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters\Interfaces"
Get-ChildItem -Path $regPath | ForEach-Object {
    $interfaceKey = $_.PSPath
    $value = (Get-ItemProperty -Path "$interfaceKey" -Name "TCPNoDelay" -ErrorAction SilentlyContinue).TCPNoDelay
    Log-Output "Miscellaneous Network Settings (TCPNoDelay for interface $($_.PSChildName)): $interfaceKey\TCPNoDelay = $value"
    $value = (Get-ItemProperty -Path "$interfaceKey" -Name "TcpAckFrequency" -ErrorAction SilentlyContinue).TcpAckFrequency
    Log-Output "Miscellaneous Network Settings (TcpAckFrequency for interface $($_.PSChildName)): $interfaceKey\TcpAckFrequency = $value"
}

Log-Output "`r`n------------------------------------"
Log-Output "QoL Tweaks"
Log-Output "------------------------------------"

$regPath = "HKCU:\Software\Classes\CLSID\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\InprocServer32"
$value = (Get-ItemProperty -Path $regPath -Name "" -ErrorAction SilentlyContinue).'(default)'
Log-Output "Always Show Full Context Menu on Items: $regPath\(Default) = $value"

$regPath = "HKCU:\Software\Microsoft\Windows NT\CurrentVersion\Accessibility"
$valueName = "Configuration"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Accessibility Tool Shortcut: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer"
$valueName = "NoUseStoreOpenWith"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable App Lookup in Store: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Policies\Microsoft\Windows\WindowsCopilot"
$valueName = "TurnOffWindowsCopilot"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Copilot: $regPath\$valueName = $value"

$regPath = "HKLM:\Software\Policies\Microsoft\Windows\System"
$valueName = "EnableFileAssociate"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Internet File Association Service: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "NoLowDiskSpaceChecks"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Low Disk Space Warning: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "HideSCAMeetNow"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Meet Now: $regPath\$valueName = $value"

$regPath = "HKCU:\Control Panel\Desktop"
$valueName = "MenuShowDelay"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Menu Show Delay: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Classes\CLSID\{F02C1A0D-BE21-4350-88B0-7367FC96EF3C}"
$valueName = "System.IsPinnedToNameSpaceTree"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Network Navigation Pane in Explorer: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Feeds"
$valueName = "ShellFeedsTaskbarViewMode"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable News and Interest: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "NoRecommendedFiles"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Recommendation on Start Menu: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "NoResolveSearch"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Searching for Invalid Shortcuts: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "NoSharingWizard"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Sharing Wizard: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer"
$valueName = "Link"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Shortcut Suffix: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer"
$valueName = "ShowRecent"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Show Office Files: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize"
$valueName = "StartupDelayInMSec"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Startup Delay: $regPath\$valueName = $value"

$regPath = "HKCU:\Control Panel\Accessibility\StickyKeys"
$valueName = "Flags"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Sticky Keys: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\ImmersiveShell"
$valueName = "TabletMode"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Tablet Mode: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Policies\Microsoft\Windows\Personalization"
$valueName = "DisableImageCompression"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Wallpaper Quality Reduction: $regPath\$valueName = $value"

$regPath = "HKCU:\AppEvents\Schemes\Apps\.Default\Notification.Default"
$value = (Get-ItemProperty -Path $regPath -Name "" -ErrorAction SilentlyContinue).'(default)'
Log-Output "Disable Warning Sounds: $regPath\(Default) = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "HideSCA"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Disable Windows 11 Settings Home Page: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer"
$valueName = "Max Cached Icons"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Extend Icon Cache: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace"
if (Test-Path -Path $regPath) {
    Log-Output "Hide Folders from This PC: Folders are potentially visible (check subkeys of $regPath)"
} else {
    Log-Output "Hide Folders from This PC: Folders are hidden"
}

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\HideFileExt"
$valueName = "{e88865ea-0e1c-4e20-9aa6-edcd0212c87c}"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Hide Gallery in File Explorer: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer"
$valueName = "NoRecentDocsHistory"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Hide Recent Items: $regPath\$valueName = $value"

$regPath = "HKCU:\Control Panel\Mouse"
$valueName = "MouseHoverTime"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Minimize Mouse Hover Time for Item Info: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced"
$valueName = "LaunchTo"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Open Windows Explorer to This PC: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Shell Extensions\Blocked"
$valueName = "{7AD84985-87B4-4a16-BE58-8B72A5B390F7}"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Remove Cast to Device from Context Menu: $regPath\$valueName = $value"

$regPath = "HKCR:\SystemFileAssociations\image\shell\edit"
$valueName = "ProgrammaticAccessOnly"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Remove Edit with Paint 3D from Context Menu: $regPath\$valueName = $value"

$regPath = "HKCR:\CompressedFolder\ShellEx\ContextMenuHandlers\{b8cdcb65-b1bf-4b42-9428-1dfdb7ee92af}"
$value = (Get-ItemProperty -Path $regPath -ErrorAction SilentlyContinue).'(default)'
Log-Output "Remove Extract All from Context Menu: $regPath\(Default) = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Shell Extensions\Blocked"
$valueName = "{7BA4C740-9E81-11CF-99D3-00AA004AE837}"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Remove Include in Library from Context Menu: $regPath\$valueName = $value"

$regPath = "HKCR:\.bmp\ShellNew"
$valueName = "NullFile"
$nullFileExists = (Test-Path -Path "$regPath\$valueName") -and ((Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName -eq "")
Log-Output "Remove New Bitmap Image from Context Menu: $regPath\$valueName exists and is empty = $nullFileExists"

$regPath = "HKCR:\.rtf\ShellNew"
$valueName = "NullFile"
$nullFileExists = (Test-Path -Path "$regPath\$valueName") -and ((Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName -eq "")
Log-Output "Remove New Rich Text Document from Context Menu: $regPath\$valueName exists and is empty = $nullFileExists"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer"
$valueName = "EnablePreviousVersionsPage"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Remove Previous Version from Explorer: $regPath\$valueName = $value"

$regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Shell Extensions\Blocked"
$valueName = "{f81e9010-6ea4-11ce-a7ff-00aa003ca9f6}"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Remove Share from Context Menu: $regPath\$valueName = $value"

$regPath = "HKCR:\exefile\shellex\ContextMenuHandlers\Compatibility"
$value = (Get-ItemProperty -Path $regPath -ErrorAction SilentlyContinue).'(default)'
Log-Output "Remove Troubleshoot Compatibility from Context Menu: $regPath\(Default) = $value"

$regPath = "HKCU:\Software\Classes\CLSID\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\InprocServer32"
if (Test-Path -Path $regPath) {
    Log-Output "Restore Old Context Menu: Key $regPath exists"
} else {
    Log-Output "Restore Old Context Menu: Key $regPath does not exist"
}

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced"
$valueName = "HideFileExt"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Show Extensions for All Files: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced"
$valueName = "Start_TrackDocs"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Show More Pins on Start Menu: $regPath\$valueName = $value"

$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer"
$valueName = "AltTabSettings"
$value = (Get-ItemProperty -Path $regPath -Name $valueName -ErrorAction SilentlyContinue).$valueName
Log-Output "Use Classic Alt + Tab: $regPath\$valueName = $value"
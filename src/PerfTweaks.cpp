#include "PerfTweaks.h"
#include "Utils.h"
#include <windows.h>
#include <iostream>
#include <string>

bool ExcCMD(const std::string& command) {
    int result = std::system(command.c_str());
    if (result != 0) {
        std::cerr << "command failed - " << command << std::endl;
        return false;
    }
    return true;
}

void DoPerfTweaks(const json& config) {
    BCDEditConf(config);
    MmcssConf(config);
    AutoDisc(config);
    BackAppsDis(config);
    BootTraceDis(config);
    FaultHeapDis(config);
    PagingDis(config);
    PFetchNo(config);
    SvcHsSpltDis(config);
    SlpStdNo(config);
    SpecMeltDis(config);
    StartUpApsDis(config);
    VbsDis(config);
    WinDefDis(config);
    DwmOpt(config);
    FsoOpt(config);
    NtfsOpt(config);
    MsOpt(config);
    NvmeOpt(config);
    Win32Prior(config);
}

void BCDEditConf(const json& config) {
    if (config.value("Configure BCDEdit", "NO") != "YES") {
        return;
    }
    ExcCMD("bcdedit /set increaseuserva 3072");
    ExcCMD("bcdedit /set pae ForceEnable");
    ExcCMD("bcdedit /set {current} nx OptIn");
    ExcCMD("bcdedit /set useplatformclock false");
    ExcCMD("bcdedit /set tscsyncpolicy Enhanced");
    ExcCMD("bcdedit /set disabledynamictick Yes");
}

void MmcssConf(const json& config) {
    if (config.value("Configure MMCSS", "NO")
        != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile", KEY_SET_VALUE);
    if (hKey) {
        SetVal(hKey, L"NetworkThrottlingIndex", L"FFFFFFFF");
        SetVal(hKey, L"SystemResponsiveness", L"0");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", KEY_SET_VALUE);
    if (hKey)
    {
        SetVal(hKey, L"Affinity", L"0");
        SetVal(hKey, L"Background Only", L"False");
        SetVal(hKey, L"Clock Rate", L"2710");
        SetVal(hKey, L"GPU Priority", L"8");
        SetVal(hKey, L"Priority", L"6");
        SetVal(hKey, L"Scheduling Category", L"High");
        SetVal(hKey, L"SFIO Priority", L"High");
        RegCloseKey(hKey);
    }
}

void AutoDisc(const json& config) {
    if (config.value("Disable Automatic Folder Discovery", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Classes\\Local Settings\\Software\\Microsoft\\Windows\\Shell\\Bags\\AllFolders\\Shell", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"FolderType", L"NotSpecified");
        RegCloseKey(hKey);
    }
}

void BackAppsDis(const json& config) {
    if (config.value("Disable Background Apps", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\BackgroundAccessApplications", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"GlobalUserDisabled", 1);
        RegCloseKey(hKey);
    }
}

void BootTraceDis(const json& config) {
    if (config.value("Disable Boot Tracing", "NO") != "YES") {
        return;
    }
    ExcCMD("bcdedit /set bootlog No");
    ExcCMD("bcdedit /set bootstatuspolicy IgnoreAllFailures");
}

void FaultHeapDis(const json& config) {
    if (config.value("Disable Fault Tolerant Heap", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\FTH", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Enabled", 0);
        RegCloseKey(hKey);
    }
}

void PagingDis(const json& config) {
    if (config.value("Disable Paging Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisablePagingExecutive", 1);
        RegCloseKey(hKey);
    }
}

void PFetchNo(const json& config) {
    if (config.value("Disable Prefetch", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnablePrefetcher", 0);
        DWORDSET(hKey, L"EnableSuperfetch", 0);
        RegCloseKey(hKey);
    }
}

void SvcHsSpltDis(const json& config) {
    if (config.value("Disable Service Host Splitting", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SvcHostSplitThresholdInKB", 0x3FFFFFFF);
        RegCloseKey(hKey);
    }
}

void SlpStdNo(const json& config) {
    if (config.value("Disable Sleep Study", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\power", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void SpecMeltDis(const json& config) {
    if (config.value("Disable Spectre and Meltdown", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"FeatureSettingsOverride", 3);
        DWORDSET(hKey, L"FeatureSettingsOverrideMask", 3);
        RegCloseKey(hKey);
    }
}

void StartUpApsDis(const json& config) {
    if (config.value("Disable Startup Apps Delay", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Serialize", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"StartupDelayInMSec", 0);
        RegCloseKey(hKey);
    }
}

void VbsDis(const json& config) {
    if (config.value("Disable VBS", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\DeviceGuard", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableVirtualizationBasedSecurity", 0);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\LSA", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LsaCfgFlags", 0);
        RegCloseKey(hKey);
    }
}

void WinDefDis(const json& config) {
    if (config.value("Disable Windows Defender", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableAntiSpyware", 1);
        DWORDSET(hKey, L"DisableAntiVirus", 1);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\WinDefend", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void DwmOpt(const json& config) {
    if (config.value("Optimize DWM Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\DWM", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"OverlayTestMode", 5);
        RegCloseKey(hKey);
    }
}

void FsoOpt(const json& config) {
    if (config.value("Optimize FSO Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"System\\GameConfigStore", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"GameDVR_FSEBehaviorMode", 2);
        DWORDSET(hKey, L"GameDVR_HonorUserFSEBehaviorMode", 1);
        DWORDSET(hKey, L"GameDVR_FSE এলাওড", 0);
        RegCloseKey(hKey);
    }
}

void NtfsOpt(const json& config) {
    if (config.value("Optimize NTFS", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\FileSystem", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NtfsDisable8dot3NameCreation", 1);
        DWORDSET(hKey, L"NtfsMemoryUsage", 2);
        DWORDSET(hKey, L"NtfsDisableLastAccessUpdate", 1);
        RegCloseKey(hKey);
    }
}

void MsOpt(const json& config) {
    if (config.value("Optimized Mouse Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Mouse", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"MouseSensitivity", L"10");
        SetVal(hKey, L"SmoothMouseXCurve", L"00,00,00,00,00,00,00,00,C0,CC,0C,00,00,00,00,00,80,19,19,00,00,00,00,00,40,66,26,00,00,00,00,00,00,00,34,00,00,00,00,00");
        SetVal(hKey, L"SmoothMouseYCurve", L"00,00,00,00,00,00,00,00,00,00,38,00,00,00,00,00,00,00,E0,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,50,02,00,00,00,00");
        RegCloseKey(hKey);
    }
}

void NvmeOpt(const json& config) {
    if (config.value("Optimize NVMe Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters\\Device", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"ForcedUnitAccess", 1);
        RegCloseKey(hKey);
    }
}

void Win32Prior(const json& config) {
    if (config.value("Win32 Priority Separation", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Win32PrioritySeparation", 26);
        RegCloseKey(hKey);
    }
}
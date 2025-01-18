#include "CaterTweaks.h"
#include "Utils.h"
#include <iostream>
#include <windows.h>
#include <string>

void CaterTweaksDo(const json& config) {
    UltPlan(config);
    PwrThrttleNo(config);
    UlckPwrOpt(config);
    BtNo(config);
    DiskChkTmInc(config);
    BootDefNo(config);
    SysCacheLgEn(config);
    NtfsLsAccStNo(config);
    NameETCrNo(config);
    IrpStackInc(config);
    BanResNo(config);
    CoreParkNo(config);
    UltPlanEn(config);
    IndSvcNo(config);
    SuFtchNo(config);
    SsdOptSet(config);
    DiffCompNo(config);
    SysCacLimitInc(config);
    MemONo(config);
    FstStEn(config);
    VisEffNo(config);
    DvrGameNo(config);
    DelivOptNo(config);
    PcSchdAdj(config);
    StPrNo(config);
    AdvIDNo(config);
    WfiSensNo(config);
    SSFiltNo(config);
    CldProtWinDefNo(config);
    WinDefSampNo(config);
    SgCtSetAppNo(config);
    AppAccInfNo(config);
    NACC(config);
    NACCT(config);
    NACH(config);
    NAAE(config);
    NAAT(config);
    NAAM(config);
    NAAR(config);
    NAAOD(config);
    NHDS(config);
    NITP(config);
    NSSTS(config);
    NFMD(config);
    NCEP(config);
    AnimateNo(config);
    NTE(config);
    NSANo(config);
    NtNo(config);
    NSATM(config);
    NGMOFW(config);
    NTASNo(config);
    NWSISM(config);
    NFANo(config);
    GameMdNo(config);
    SSNo(config);
    SYSNoS(config);
    TelemSvcNo(config);
    ShdExpNo(config);
    CBHNo(config);
    PBNo(config);
    NWIPNo(config);
    ResStNo(config);
    ODNo(config); 

    // this is always called regardless of the config state
    // just to show mark
    DeskFinish();

}

void UltPlan(const json& config) {
    if (config.value("Set Ultimate Performance Power Plan Once", "NO") != "YES") {
        return;
    }

    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\CaterTweaks", KEY_READ | KEY_WRITE);
    if (!hKey) {
        std::cerr << "Opening/creating CaterTweaks registry key failed!" << std::endl;
        return;
    }
    DWORD alreadySet;
    DWORD size = sizeof(DWORD);

    if (RegGetValue(hKey, NULL, L"UltimatePowerPlanSet", RRF_RT_DWORD, NULL, &alreadySet, &size) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return; 
    }

    std::system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
    std::string ultimate_guid = "e9a42b02-d5df-448d-aa00-03f14749eb61";
    std::string set_active_command = "powercfg /setactive " + ultimate_guid;
    std::system(set_active_command.c_str());

    DWORD value = 1;
    if (RegSetValueEx(hKey, L"UltimatePowerPlanSet", 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS) {
        std::cerr << "Setting UltimatePowerPlanSet registry value failed!" << std::endl;
    }

    RegCloseKey(hKey);
}

void PwrThrttleNo(const json& config) {
    if (config.value("Disable Power Throttling", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Power", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"PowerThrottlingOff", 1);
        RegCloseKey(hKey);
    }
}

void UlckPwrOpt(const json& config) {
    if (config.value("Unlock All Advanced Power Options", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Power\\User\\PowerSchemes", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Attributes", 2);
        RegCloseKey(hKey);
    }
}

void BtNo(const json& config) {
    if (config.value("Disable Bluetooth", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\BthServ", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void DiskChkTmInc(const json& config) {
    if (config.value("Increase Disk Check Timeout", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager", KEY_SET_VALUE);
    if (hKey) {
        if (RegSetValueEx(hKey, L"AutoChkTimeOut", 0, REG_DWORD, (const BYTE*)10, sizeof(DWORD)) != ERROR_SUCCESS) {
            std::cerr << "Setting AutoChkTimeOut value failed!" << std::endl;
        }
        RegCloseKey(hKey);
    }
}

void BootDefNo(const json& config) {
    if (config.value("Disable Automatic Defragmentation of Boot Files", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Dfrg\\BootOptimizeFunction", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"OptimizeComplete", L"No");
        RegCloseKey(hKey);
    }
}

void SysCacheLgEn(const json& config) {
    if (config.value("Enable Large System Cache", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LargeSystemCache", 1);
        RegCloseKey(hKey);
    }
}

void NtfsLsAccStNo(const json& config) {
    if (config.value("Disable NTFS Last Access Timestamp", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\FileSystem", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NtfsDisableLastAccessUpdate", 1);
        RegCloseKey(hKey);
    }
}

void NameETCrNo(const json& config) {
    if (config.value("Disable 8.3 Name Creation", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\FileSystem", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NtfsDisable8dot3NameCreation", 1);
        RegCloseKey(hKey);
    }
}

void IrpStackInc(const json& config) {
    if (config.value("Increase IRPStackSize", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters", KEY_SET_VALUE);
    if (hKey) {
        DWORD existingValue;
        DWORD size = sizeof(DWORD);
        if (RegGetValue(hKey, NULL, L"IRPStackSize", RRF_RT_DWORD, NULL, &existingValue, &size) == ERROR_SUCCESS)
        {
            DWORDSET(hKey, L"IRPStackSize", 32);
        }

        RegCloseKey(hKey);
    }
}

void BanResNo(const json& config) {
    if (config.value("Disable Bandwidth Reservation for QoS", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Psched", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NonBestEffortLimit", 0);
        RegCloseKey(hKey);
    }
}

void CoreParkNo(const json& config) {
    if (config.value("Disable Core Parking", "NO") != "YES") {
        return;
    }
    std::system("powercfg /setacvalueindex SCHEME_CURRENT SUB_PROCESSOR CPMINCORES 100");
    std::system("powercfg /setdcvalueindex SCHEME_CURRENT SUB_PROCESSOR CPMINCORES 100");
    std::system("powercfg /setactive SCHEME_CURRENT");
}

void UltPlanEn(const json& config) {
    if (config.value("Enable Ultimate Performance Power Plan", "NO") != "YES") {
        return;
    }
    std::system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
}

void IndSvcNo(const json& config) {
    if (config.value("Disable Indexing Service", "NO") != "YES") {
        return;
    }
    std::system("net stop \"Windows Search\" & sc config \"WSearch\" start=disabled");
}

void SuFtchNo(const json& config) {
    if (config.value("Disable Superfetch/SysMain", "NO") != "YES") {
        return;
    }
    std::system("net stop \"SysMain\" & sc config \"SysMain\" start=disabled");
}

void SsdOptSet(const json& config) {
    if (config.value("Optimize Solid State Drive (SSD) Settings", "NO") != "YES") {
        return;
    }
    std::system("powercfg -h off");
}

void DiffCompNo(const json& config) {
    if (config.value("Disable Remote Differential Compression", "NO") != "YES") {
        return;
    }
    std::system("dism /online /Disable-Feature /FeatureName:RemoteDifferentialCompression");
}

void SysCacLimitInc(const json& config) {
    if (config.value("Increase System File Cache Limit", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management", KEY_SET_VALUE);
    if (hKey) {
        DWORD existingValue;
        DWORD size = sizeof(DWORD);
        if (RegGetValue(hKey, NULL, L"SystemCacheDirtyPageThreshold", RRF_RT_DWORD, NULL, &existingValue, &size) == ERROR_SUCCESS)
        {
            DWORDSET(hKey, L"SystemCacheDirtyPageThreshold", 10000);
        }
        RegCloseKey(hKey);
    }
}

void MemONo(const json& config) {
    if (config.value("Disable Full Memory Dump", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\CrashControl", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"CrashDumpEnabled", 3);
        RegCloseKey(hKey);
    }
}

void FstStEn(const json& config) {
    if (config.value("Enable Fast Startup", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"HiberbootEnabled", 1);
        RegCloseKey(hKey);
    }
}

void VisEffNo(const json& config) {
    if (config.value("Disable Visual Effects for Best Performance", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\VisualEffects", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"VisualFXSetting", 3); 
        RegCloseKey(hKey);
    }
}

void DvrGameNo(const json& config) {
    if (config.value("Disable Game DVR and Game Bar", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"System\\GameConfigStore", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"GameDVR_Enabled", 0);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\GameDVR", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowGameDVR", 0);
        RegCloseKey(hKey);
    }
}

void DelivOptNo(const json& config) {
    if (config.value("Disable Delivery Optimization", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\DeliveryOptimization", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DODownloadMode", 0);
        RegCloseKey(hKey);
    }
}

void PcSchdAdj(const json& config) {
    if (config.value("Adjust Processor Scheduling", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"Win32PrioritySeparation", 24);
        RegCloseKey(hKey);
    }
}

void StPrNo(const json& config) {
    if (config.value("Disable Startup Programs", "NO") != "YES") {
        return;
    }
}

void AdvIDNo(const json& config) {
    if (config.value("Disable Advertising ID", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Enabled", 0);
        RegCloseKey(hKey);
    }
}

void WfiSensNo(const json& config) {
    if (config.value("Disable Wi-Fi Sense", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\WcmSvc\\wifinetworkmanager\\config", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AutoConnectAllowedOEM", 0);
        RegCloseKey(hKey);
    }
}

void SSFiltNo(const json& config) {
    if (config.value("Disable SmartScreen Filter", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\System", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableSmartScreen", 0);
        RegCloseKey(hKey);
    }
}

void CldProtWinDefNo(const json& config) {
    if (config.value("Disable Cloud-based Protection (Microsoft Defender)", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender\\Spynet", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SpynetReporting", 0);
        RegCloseKey(hKey);
    }
}

void WinDefSampNo(const json& config) {
    if (config.value("Disable Automatic Sample Submission (Microsoft Defender)", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender\\Spynet", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SubmitSamplesConsent", 2); 
        RegCloseKey(hKey);
    }
}

void SgCtSetAppNo(const json& config) {
    if (config.value("Disable Suggested Content in the Settings App", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SubscribedContent-338388Enabled", 0);
        RegCloseKey(hKey);
    }
}

void AppAccInfNo(const json& config) {
    if (config.value("Disable App Access to Your Account Info", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessAccountInfo", 2); 
        RegCloseKey(hKey);
    }
}

void NACC(const json& config) {
    if (config.value("Disable App Access to Your Contacts", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessContacts", 2); 
        RegCloseKey(hKey);
    }
}

void NACCT(const json& config) {
    if (config.value("Disable App Access to Your Calendar", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessCalendar", 2); 
        RegCloseKey(hKey);
    }
}

void NACH(const json& config) {
    if (config.value("Disable App Access to Your Call History", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessCallHistory", 2); 
        RegCloseKey(hKey);
    }
}

void NAAE(const json& config) {
    if (config.value("Disable App Access to Your Email", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessEmail", 2); 
        RegCloseKey(hKey);
    }
}

void NAAT(const json& config) {
    if (config.value("Disable App Access to Your Tasks", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessTasks", 2); 
        RegCloseKey(hKey);
    }
}

void NAAM(const json& config) {
    if (config.value("Disable App Access to Your Messaging", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessMessaging", 2); 
        RegCloseKey(hKey);
    }
}

void NAAR(const json& config) {
    if (config.value("Disable App Access to Your Radios", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsAccessRadios", 2); 
        RegCloseKey(hKey);
    }
}

void NAAOD(const json& config) {
    if (config.value("Disable App Access to Other Devices", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Privacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LetAppsSyncWithDevices", 2); 
        RegCloseKey(hKey);
    }
}

void NHDS(const json& config) {
    if (config.value("Disable Handwriting Data Sharing", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\InputPersonalization", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"RestrictImplicitTextCollection", 1);
        DWORDSET(hKey, L"RestrictImplicitInkCollection", 1);
        RegCloseKey(hKey);
    }
}

void NITP(const json& config) {
    if (config.value("Disable Inking & Typing Personalization", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\InputPersonalization", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"RestrictImplicitTextCollection", 1);
        DWORDSET(hKey, L"RestrictImplicitInkCollection", 1);
        RegCloseKey(hKey);
    }
}

void NSSTS(const json& config) {
    if (config.value("Disable Speech Services and Typing Suggestions", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Speech_OneCore\\Settings\\OnlineSpeechPrivacy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"HasAccepted", 0);
        RegCloseKey(hKey);
    }
}

void NFMD(const json& config) {
    if (config.value("Disable Find My Device", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\FindMyDevice", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowFindMyDevice", 0);
        RegCloseKey(hKey);
    }
}

void NCEP(const json& config) {
    if (config.value("Disable the Customer Experience Improvement Program", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\SQMClient\\Windows", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"CEIPEnable", 0);
        RegCloseKey(hKey);
    }
}

void AnimateNo(const json& config) {
    if (config.value("Disable Animations", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\VisualEffects", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"VisualFXSetting", 3); 
        RegCloseKey(hKey);
    }

    hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Desktop\\WindowMetrics", KEY_SET_VALUE);
    if (hKey)
    {
        SetVal(hKey, L"MinAnimate", L"0");
        RegCloseKey(hKey);
    }
}

void NTE(const json& config) {
    if (config.value("Disable Transparency Effects", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableTransparency", 0);
        RegCloseKey(hKey);
    }
}

void NSANo(const json& config) {
    if (config.value("Disable Snap Assist", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SnapAssist", 0);
        RegCloseKey(hKey);
    }
}

void NtNo(const json& config) {
    if (config.value("Disable Timeline", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\System", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableActivityFeed", 0);
        DWORDSET(hKey, L"PublishUserActivities", 0);
        DWORDSET(hKey, L"UploadUserActivities", 0);
        RegCloseKey(hKey);
    }
}

void NSATM(const json& config) {
    if (config.value("Disable Suggested Apps in the Start Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SystemPaneSuggestionsEnabled", 0);
        RegCloseKey(hKey);
    }
}

void NGMOFW(const json& config) {
    if (config.value("Disable \"Get even more out of Windows\"", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\UserProfileEngagement", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"ScoobeSystemSettingEnabled", 0);
        RegCloseKey(hKey);
    }
}

void NTASNo(const json& config) {
    if (config.value("Disable \"Get tips, tricks, and suggestions as you use Windows\"", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SubscribedContent-338389Enabled", 0);
        DWORDSET(hKey, L"SubscribedContent-338393Enabled", 0);
        RegCloseKey(hKey);
    }
}

void NWSISM(const json& config) {
    if (config.value("Disable Web Search in the Start Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Windows\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableSearchBoxSuggestions", 1);
        RegCloseKey(hKey);
    }
}

void NFANo(const json& config) {
    if (config.value("Disable Focus Assist", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NOC_GLOBAL_SETTING_TOASTS_ENABLED", 0);
        RegCloseKey(hKey);
    }
}

void GameMdNo(const json& config) {
    if (config.value("Disable Game Mode", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\GameBar", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowAutoGameMode", 0);
        RegCloseKey(hKey);
    }
}

void SSNo(const json& config) {
    if (config.value("Disable Storage Sense", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\StorageSense\\Parameters\\StoragePolicy", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"01", 0); 
        RegCloseKey(hKey);
    }
}

void SYSNoS(const json& config) {
    if (config.value("Disable Sync Your Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\SettingSync", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableSync", 1);
        DWORDSET(hKey, L"DisableSyncOnPaidNetwork", 1);
        RegCloseKey(hKey);
    }
}

void TelemSvcNo(const json& config) {
    if (config.value("Disable Connected User Experiences and Telemetry", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\DiagTrack", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void ShdExpNo(const json& config) {
    if (config.value("Disable Shared Experiences", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\System", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableCdp", 0);
        RegCloseKey(hKey);
    }
}

void CBHNo(const json& config) {
    if (config.value("Disable Clipboard History", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\System", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowClipboardHistory", 0);
        RegCloseKey(hKey);
    }
}

void PBNo(const json& config) {
    if (config.value("Disable People Bar", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\\People", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"PeopleBand", 0);
        RegCloseKey(hKey);
    }
}

void NWIPNo(const json& config) {
    if (config.value("Disable Windows Insider Program", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\PreviewBuilds", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnablePreviewBuilds", 0);
        RegCloseKey(hKey);
    }
}

void ResStNo(const json& config) {
    if (config.value("Disable Reserved Storage", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ReserveManager", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"ShippedWithReserves", 0);
        RegCloseKey(hKey);
    }
}

void ODNo(const json& config) {
    if (config.value("Disable OneDrive", "NO") != "YES") {
        return;
    }
    std::system("taskkill /f /im OneDrive.exe");

    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteValue(hKey, L"OneDrive");
        RegCloseKey(hKey);
    }

    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\OneDrive", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"DisableFileSyncNGSC", 1);
        RegCloseKey(hKey);
    }
}
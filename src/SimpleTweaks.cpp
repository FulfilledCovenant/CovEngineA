#include "SimpleTweaks.h"
#include "Utils.h"
#include <windows.h>
#include <fstream>
#include <iostream>

void SimpleTweaks(const json& config) {
    ActCenter(config);
    MaintenNo(config);
    CortNo(config);
    DownBlckNo(config);
    DrivUpdNo(config);
    ErrorNo(config);
    LockNo(config);
    EdgeNo(config);
    MrtNo(config);
    StoreUpdNo(config);
    SysRestNo(config);
    UacNo(config);
    InkNo(config);
    WinUpdNo(config);
    WinUpdPsNo(config);
}

bool ReadConfig(json& config) {
    std::ifstream configFile("config.json");
    if (!configFile.is_open()) {
        return false;
    }

    try {
        configFile >> config;
    }

    catch (const json::parse_error& e) {
        std::cerr << "Unable to parse config.json - " << e.what() << std::endl;
        return false;
    }
    configFile.close();
    return true;
}
/// <summary>
/// set defaults
/// </summary>
json DefConfig() {
    json defaultConfig;
    defaultConfig["Disable Action Center"] = "YES";
    defaultConfig["Disable Automatic Maintenance"] = "YES";
    defaultConfig["Disable Cortana"] = "YES";
    defaultConfig["Disable Downloads Blocking"] = "YES";
    defaultConfig["Disable Driver Updates"] = "YES";
    defaultConfig["Disable Error Reporting"] = "YES";
    defaultConfig["Disable Lock Screen"] = "YES";
    defaultConfig["Disable Microsoft Edge Auto-Installation"] = "YES";
    defaultConfig["Disable MRT Updates"] = "YES";
    defaultConfig["Disable Store Auto-Updates"] = "YES";
    defaultConfig["Disable System Restore"] = "NO";
    defaultConfig["Disable UAC"] = "YES";
    defaultConfig["Disable Windows Ink Workspace"] = "YES";
    defaultConfig["Disable Windows Updates"] = "YES";
    defaultConfig["Disable Windows Timeline"] = "YES";
    defaultConfig["Pause Windows Updates"] = "YES";
    return defaultConfig;
}

void CurrentConf(const json& config) {
    std::cout << "Tweak Stateues:" << std::endl;
    for (auto& element : config.items()) {
        std::cout << element.key() << ": " << element.value() << std::endl;
    }
    std::cout << std::endl;
}

void ActCenter(const json& config) {
    if (config.value("Disable Action Center", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Windows\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableNotificationCenter", 1);
        RegCloseKey(hKey);
    }
}

void MaintenNo(const json& config) {
    if (config.value("Disable Automatic Maintenance", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\Maintenance", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"MaintenanceDisabled", 1);
        RegCloseKey(hKey);
    }
}

void CortNo(const json& config) {
    if (config.value("Disable Cortana", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowCortana", 0);
        RegCloseKey(hKey);
    }
}

void DownBlckNo(const json& config) {
    if (config.value("Disable Downloads Blocking", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Attachments", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"SaveZoneInformation", 1);
        RegCloseKey(hKey);
    }
}

void DrivUpdNo(const json& config) {
    if (config.value("Disable Driver Updates", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"ExcludeWUDriversInQualityUpdate", 1);
        RegCloseKey(hKey);
    }
}

void ErrorNo(const json& config) {
    if (config.value("Disable Error Reporting", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Disabled", 1);
        RegCloseKey(hKey);
    }
}

void LockNo(const json& config) {
    if (config.value("Disable Lock Screen", "NO") != "YES") {
        return;
    }
    // 1
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Personalization", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"NoLockScreen", 1);
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Could not open registry key for DLS!" << std::endl;
    }
    // 2
    HKEY hKeyGP = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", KEY_SET_VALUE);
    if (hKeyGP) {
        DWORDSET(hKeyGP, L"DisableLockWorkstation", 1); 
        RegCloseKey(hKeyGP);
    }
    else {
        std::cerr << "DLS 2 failed!" << std::endl;
    }
}

void EdgeNo(const json& config) {
    if (config.value("Disable Microsoft Edge Auto-Installation", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\EdgeUpdate", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Allowsxs", 0);
        RegCloseKey(hKey);
    }
}

void MrtNo(const json& config) {
    if (config.value("Disable MRT Updates", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\MRT", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DontOfferThroughWUAU", 1);
        RegCloseKey(hKey);
    }
}

void StoreUpdNo(const json& config) {
    if (config.value("Disable Store Auto-Updates", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\WindowsStore", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AutoDownload", 2);
        RegCloseKey(hKey);
    }
}

void SysRestNo(const json& config) {
    if (config.value("Disable System Restore", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows NT\\SystemRestore", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableConfig", 1);
        DWORDSET(hKey, L"DisableSR", 1);
        RegCloseKey(hKey);
    }
}

void UacNo(const json& config) {
    if (config.value("Disable UAC", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableLUA", 0);
        RegCloseKey(hKey);
    }
}

void InkNo(const json& config) {
    if (config.value("Disable Windows Ink Workspace", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\WindowsInkWorkspace", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowWindowsInkWorkspace", 0);
        RegCloseKey(hKey);
    }
}

void WinUpdNo(const json& config) {
    if (config.value("Disable Windows Updates", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoAutoUpdate", 1);
        RegCloseKey(hKey);
    }
}

void WinUpdPsNo(const json& config) {
    if (config.value("Pause Windows Updates", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\WindowsUpdate\\UpdatePolicy\\Settings", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Paused", 1);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\WindowsUpdate\\UpdatePolicy", KEY_SET_VALUE);
    if (hKey) {
        if (RegSetValueEx(hKey, L"PauseUpdatesExpiryTime", 0, REG_SZ, (const BYTE*)L"2099-01-01", (DWORD)((wcslen(L"2099-01-01") + 1) * sizeof(wchar_t))) != ERROR_SUCCESS)
        {
            // error!
        }
        RegCloseKey(hKey);
    }
}
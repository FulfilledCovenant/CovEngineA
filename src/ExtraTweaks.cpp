#include "ExtraTweaks.h"
#include "Utils.h"
#include <windows.h>
#include <iostream>

void ExtraTweaks(const json& config) {
    MsAccelNo(config);
    VisBetter(config);
    FstShut(config);
    AutorunNo(config);
}

void MsAccelNo(const json& config) {
    if (config.value("Disable Mouse Acceleration", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Mouse", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"MouseSensitivity", L"10");
        SetVal(hKey, L"MouseSpeed", L"0");
        SetVal(hKey, L"MouseThreshold1", L"0");
        SetVal(hKey, L"MouseThreshold2", L"0");
        RegCloseKey(hKey);
    }
}

void VisBetter(const json& config) {
    if (config.value("Optimize Visual Effects", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\VisualEffects", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"VisualFXSetting", 1);
        RegCloseKey(hKey);
    }
}

void FstShut(const json& config) {
    if (config.value("Reduce Shutdown Time", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Desktop", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"WaitToKillAppTimeout", L"2000");
        SetVal(hKey, L"HungAppTimeout", L"1000");
        SetVal(hKey, L"AutoEndTasks", L"1");
        RegCloseKey(hKey);
    }
}

void AutorunNo(const json& config) {
    if (config.value("Disable Autorun/AutoPlay", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoplayHandlers", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableAutoplay", 1);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoDriveTypeAutoRun", 0xFF);
        RegCloseKey(hKey);
    }
}

void DeskFinish() {
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Desktop", KEY_SET_VALUE);
    if (hKey) {
        SetVal(hKey, L"WallpaperStyle", L"10"); 
        SetVal(hKey, L"TileWallpaper", L"0"); 
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Colors", KEY_SET_VALUE);
    if (hKey) {
        SetVal(hKey, L"Background", L"0 0 0");
        RegCloseKey(hKey);
    }
    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (PVOID)L"", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
}
// for showing progress
// also for less power consumption
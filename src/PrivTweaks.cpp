#include "PrivTweaks.h"
#include "Utils.h"
#include <windows.h>
#include <iostream>

void DoPrivTweaks(const json& config) {
    TrackingNo(config);
    TelemNo(config);
    AppAccNo(config);
    FbNo(config);
    DiaDataNo(config);
    TlExpNo(config);
    ActHisNo(config);
    SetSyncNo(config);
}

void TrackingNo(const json& config) {
    if (config.value("Disable Location Tracking", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\lfsvc", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\LocationAndSensors", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableLocation", 1);
        RegCloseKey(hKey);
    }
}

void TelemNo(const json& config) {
    if (config.value("Disable Telemetry", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowTelemetry", 0);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\DiagTrack", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\dmwappushservice", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void AppAccNo(const json& config) {
    if (config.value("Disable App Access to Location", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\LocationAndSensors", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableLocation আপত্তি", 1);
        RegCloseKey(hKey);
    }
}

void FbNo(const json& config) {
    if (config.value("Disable Feedback", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DoNotShowFeedbackNotifications", 1);
        RegCloseKey(hKey);
    }
}

void DiaDataNo(const json& config) {
    if (config.value("Disable Diagnostic Data", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AllowTelemetry", 0);
        RegCloseKey(hKey);
    }
}

void TlExpNo(const json& config) {
    if (config.value("Disable Tailored Experiences", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\CloudContent", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableTailoredExperiencesWithDiagnosticData", 1);
        RegCloseKey(hKey);
    }
}

void ActHisNo(const json& config) {
    if (config.value("Disable Activity History", "NO") != "YES") {
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

void SetSyncNo(const json& config)
{
    if (config.value("Disable Settings Sync", "NO") != "YES") {
        return;
    }

    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\SettingSync", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableSettingSync", 1);
        DWORDSET(hKey, L"DisableSettingSyncUserOverride", 1);
        RegCloseKey(hKey);
    }
}
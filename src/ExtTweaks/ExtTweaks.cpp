#include "ExtTweaks.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <powrprof.h>
#include <rpcdce.h>
#pragma comment(lib, "Powrprof.lib")
#pragma comment(lib, "Rpcrt4.lib")

std::vector<std::wstring> PWRSchGet() {
    std::vector<std::wstring> guids;
    DWORD bufferSize = 0;
    DWORD index = 0;
    GUID* guid = nullptr;

    while (PowerEnumerate(NULL, NULL, NULL, ACCESS_SCHEME, index, (UCHAR*)&guid, &bufferSize) == ERROR_MORE_DATA)
    {
        bufferSize = sizeof(GUID);
        guid = (GUID*)LocalAlloc(LPTR, bufferSize);

        if (PowerEnumerate(NULL, NULL, NULL, ACCESS_SCHEME, index, (UCHAR*)guid, &bufferSize) == ERROR_SUCCESS)
        {
            RPC_WSTR szGuid = NULL;
            if (UuidToStringW(guid, &szGuid) == RPC_S_OK)
            {
                guids.push_back(std::wstring((wchar_t*)szGuid));
                RpcStringFreeW(&szGuid);
            }
        }
        LocalFree(guid);
        guid = nullptr;
        index++;
    }

    return guids;
}

void PwrCfgGetExc(const std::string& subkey, const std::string& setting, const std::string& value) {
    std::vector<std::wstring> guids = PWRSchGet();
    for (const auto& guid : guids) {
        std::string guidNarrow(guid.begin(), guid.end());
        std::string command = "powercfg /setacvalueindex " + guidNarrow + " " + subkey + " " + setting + " " + value;
        std::system(command.c_str());
        command = "powercfg /setdcvalueindex " + guidNarrow + " " + subkey + " " + setting + " " + value;
        std::system(command.c_str());
    }
}

void ExtTwks(const json& config)
{
    DisASLR(config);
    CSRSSRRT(config);
    LtcTol(config);
    IRQPrior(config);
    SysResE(config);
    GPUEng(config);
    EngLogDis(config);
    AppsUni(config);
    LogiProcEn(config);
    DisCStates(config);
    HighPSt(config);
    CorePKDis(config);
}

void DisASLR(const json& config) {
    if (config.value("Disable Address Space Layout Randomization (ASLR)", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\MitigationOptions", KEY_SET_VALUE);
    if (hKey) {
        SetVal(hKey, L"DisallowAslr", L"1");
        RegCloseKey(hKey);
    }
}

void CSRSSRRT(const json& config) {
    if (config.value("Set CSRSS to Realtime", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\csrss.exe", KEY_SET_VALUE);
    if (hKey) {
        HKEY hSubKey;
        if (RegCreateKeyEx(hKey, L"PerfOptions", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hSubKey, NULL) == ERROR_SUCCESS) {
            DWORDSET(hSubKey, L"CpuPriorityClass", 0x00000005);
            RegCloseKey(hSubKey);
        }
        RegCloseKey(hKey);
    }
}

void LtcTol(const json& config) {
    if (config.value("Set Latency Tolerance (1)", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Power\\PowerSettings\\501a4d13-42af-4429-9fd1-a8218c268e20\\54533251-82be-4824-96c1-47b60b740d00\\0bc5072e-985c-494b-b793-4f7d6175e749", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"ValueMax", 1);
        DWORDSET(hKey, L"ValueMin", 1);
        RegCloseKey(hKey);
    }
}

void IRQPrior(const json& config) {
    if (config.value("Set IRQ8 + IRQ16 Priority", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl\\IRQ8Priority", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"Priority", 1);
        RegCloseKey(hKey);
    }
    //
    //
    // usb controllers
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl\\IRQ16Priority", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"Priority", 1);
        RegCloseKey(hKey);
    }
}

void SysResE(const json& config) {
    if (config.value("Set System Responsiveness (0)", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"SystemResponsiveness", 0);
        RegCloseKey(hKey);
    }
}

void GPUEng(const json& config) {
    if (config.value("Disable GPU Energy Driver", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\GpuEnergyDrv", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void EngLogDis(const json& config) {
    if (config.value("Disable Energy Logging", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\energydrv", KEY_SET_VALUE);
    if (hKey) {
        DWORDSET(hKey, L"Start", 4);
        RegCloseKey(hKey);
    }
}

void AppsUni(const json& config) {
    if (config.value("Uninstall Useless Windows Apps", "NO") != "YES") {
        return;
    }
    std::system("powershell -Command \"Get-AppxPackage -allusers *3DBuilder* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.WindowsAlarms* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.WindowsCalculator* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.WindowsCamera* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.GetHelp* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Getstarted* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.MicrosoftOfficeHub* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.MicrosoftSolitaireCollection* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.People* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.SkypeApp* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.StorePurchaseApp* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Windows.Photos* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.WindowsFeedbackHub* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.WindowsMaps* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.WindowsSoundRecorder* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Xbox.TCUI* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.XboxApp* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.XboxGameOverlay* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.XboxGamingOverlay* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.XboxIdentityProvider* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.XboxSpeechToTextOverlay* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.YourPhone* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.ZuneMusic* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.ZuneVideo* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.549981C3F5F10* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.MixedReality.Portal* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.OneConnect* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Print3D* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Windows.MixedReality.WebPortal* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Windows.SecondaryTileExperience* | Remove-AppxPackage\"");
    std::system("powershell -Command \"Get-AppxPackage -allusers *Microsoft.Windows.SecureAssessmentBrowser* | Remove-AppxPackage\"");
}

void LogiProcEn(const json& config) {
    if (config.value("Enable All Logical Processors", "NO") != "YES") {
        return;
    }
    std::system("bcdedit /set {default} numproc");
}

void DisCStates(const json& config) {
    if (config.value("Disable C-States", "NO") != "YES") {
        return;
    }
    PwrCfgGetExc("SUB_PROCESSOR", "IDLEDISABLE", "000");
}

void HighPSt(const json& config) {
    if (config.value("Use Higher P-States on Lower C-States And Viseversa", "NO") != "YES") {
        return;
    }
    PwrCfgGetExc("SUB_PROCESSOR", "IDLEPROMOTION", "000");
    PwrCfgGetExc("SUB_PROCESSOR", "IDLEDEMOTION", "FFFF");
}

void CorePKDis(const json& config) {
    if (config.value("Disable Core Parking", "NO") != "YES") {
        return;
    }
    PwrCfgGetExc("SUB_PROCESSOR", "CPMINCORES", "100");
}
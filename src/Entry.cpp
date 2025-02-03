#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shlobj.h> 
#include <knownfolders.h> 
#include <shlwapi.h> 
#include "Utils.h"
#include "SimpleTweaks.h"
#include "ExtraTweaks.h"
#include "PerfTweaks.h"
#include "PrivTweaks.h"
#include "NetTweaks.h"
#include "QolTweaks.h"
#include "CaterTweaks.h"
#include "SvcTweaks.h"
#include "RnBat/RnBat.h"
#include "BGFx/BGF.h"
#include "ExtTweaks/ExtTweaks.h"
#include "nlohmann/json.hpp"
#pragma comment(lib, "Shlwapi.lib") 
using json = nlohmann::json;

int main()
{
    if (!ElavCheck()) {
        if (!ElavPerf()) {
            return 1;
        }
        return 0;
    }

    std::cout << "Proceed? y/n - ";
    char choice;
    std::cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        return 0;
    }
    json config;
    if (!ReadConfig(config)) {
        config = DefConfig();
    }
    //
    CurrentConf(config);
    //
    /*HKEY hKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SystemRestore", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        DWORD dwValue = 0;
        RegSetValueEx(hKey, L"RPGlobalInterval", 0, REG_DWORD, (const BYTE*)&dwValue, sizeof(dwValue));
        RegCloseKey(hKey);
    }*/

    //RnBat();
    //
    //
    // run batch
    // point 1 (the start of entry)
    BGFx();
    SimpleTweaks(config);
    ExtraTweaks(config);
    DoPerfTweaks(config);
    DoPrivTweaks(config);
    NetDoTweaks(config);
    QolTweaks(config);
    CaterTweaksDo(config);
    SvcTweaks(config);
    ExtTwks(config);

    wchar_t szPath[MAX_PATH];
    if (GetModuleFileNameW(NULL, szPath, ARRAYSIZE(szPath))) {
        PathRemoveFileSpecW(szPath);
        std::wstring scriptPath = std::wstring(szPath) + L"\\StartPowerService.ps1";
        std::wstring command = L"powershell -ExecutionPolicy Bypass -Command \"$Action = New-ScheduledTaskAction -Execute 'powershell.exe' -Argument '-ExecutionPolicy Bypass -File \\\"" + scriptPath + L"\\\"'; $Trigger = New-ScheduledTaskTrigger -AtLogOn; $Settings = New-ScheduledTaskSettingsSet; $Principal = New-ScheduledTaskPrincipal -UserID 'NT AUTHORITY\\SYSTEM' -LogonType ServiceAccount -RunLevel Highest; Register-ScheduledTask -TaskName 'StartPowerService' -Action $Action -Trigger $Trigger -Principal $Principal -Settings $Settings -Force\"";
        std::string commandNarrow(command.begin(), command.end());
        std::system(commandNarrow.c_str());
        std::cout << "\nRestarting in 5 seconds.\n";
        std::system("shutdown /r /t 5");
    }
    else {
        std::cerr << "Getting executable path failed!" << std::endl;
    }
    return 0;
}
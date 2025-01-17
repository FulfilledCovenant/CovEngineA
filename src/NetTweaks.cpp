#include "NetTweaks.h"
#include "Utils.h"
#include <windows.h>
#include <iostream>

void NetDoTweaks(const json& config) {
    NetConf(config);
    SMBandNo(config);
    AnonAccRes(config);
    AnonShareRes(config);
    LLMNRNo(config);
    NetMisc(config);
}

void NetConf(const json& config) {   
    if (config.value("Configure Network Settings", "NO") != "YES") {
        return;
    }

    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableTCPA", 0); 
        DWORDSET(hKey, L"EnableTCPChimney", 0); 
        DWORDSET(hKey, L"EnableTCPRSS", 0); 
        DWORDSET(hKey, L"EnableTCPOffload", 0); 

        RegCloseKey(hKey);
    }
}

void SMBandNo(const json& config) {
    if (config.value("Disable SMB Bandwidth Throttling", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableBandwidthThrottling", 1);
        RegCloseKey(hKey);
    }
}

void AnonAccRes(const json& config) {
    if (config.value("Restrict Anonymous Access", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"RestrictAnonymous", 1);
        RegCloseKey(hKey);
    }
}

void AnonShareRes(const json& config) {
    if (config.value("Restrict Anonymous Enumeration of Shares", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NullSessionShares", 0);
        RegCloseKey(hKey);
    }
}

void LLMNRNo(const json& config) {
    if (config.value("Disable LLMNR Protocol", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows NT\\DNSClient", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableMulticast", 0);
        RegCloseKey(hKey);
    }
}

void NetMisc(const json& config) {
    if (config.value("Miscellaneous Network Settings", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Psched", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NonBestEffortLimit", 0); 
        RegCloseKey(hKey);
    }

    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces", KEY_ALL_ACCESS);
    if (hKey) {
        DWORD dwIndex = 0;
        wchar_t szSubKeyName[256];
        DWORD cchSubKeyName = ARRAYSIZE(szSubKeyName);

        while (RegEnumKeyEx(hKey, dwIndex, szSubKeyName, &cchSubKeyName, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            HKEY hInterfaceKey;
            if (RegOpenKeyEx(hKey, szSubKeyName, 0, KEY_SET_VALUE, &hInterfaceKey) == ERROR_SUCCESS) {
                DWORDSET(hInterfaceKey, L"TCPNoDelay", 1); 
                DWORDSET(hInterfaceKey, L"TcpAckFrequency", 1); 
                RegCloseKey(hInterfaceKey);
            }
            dwIndex++;
            //
            // RESET
            // Buffer
            cchSubKeyName = ARRAYSIZE(szSubKeyName); 
        }
        RegCloseKey(hKey);
    }
}
#include "Utils.h"
#include <windows.h>
#include <shellapi.h>
#include <iostream>

/// <summary>
/// opens or creates
/// </summary>
HKEY OpenCKey(HKEY hKey, LPCWSTR path, REGSAM samDesired) {
    HKEY resultKey;
    if (RegCreateKeyEx(hKey, path, 0, NULL, REG_OPTION_NON_VOLATILE, samDesired, NULL, &resultKey, NULL) == ERROR_SUCCESS) {
        return resultKey;
    }
    else {
        return NULL;
    }
}
/// <summary>
/// sets dword value
/// </summary>
bool DWORDSET(HKEY hKey, LPCWSTR valueName, DWORD data) {
    if (RegSetValueEx(hKey, valueName, 0, REG_DWORD, (const BYTE*)&data, sizeof(data)) == ERROR_SUCCESS) {
        return true;
    }
    else {
        return false;
    }
}
/// <summary>
/// sets a string val
/// </summary>
bool SetVal(HKEY hKey, LPCWSTR valueName, LPCWSTR data) {
    if (RegSetValueEx(hKey, valueName, 0, REG_SZ, (const BYTE*)data, (DWORD)((wcslen(data) + 1) * sizeof(wchar_t))) == ERROR_SUCCESS) {
        return true;
    }
    else {
        return false;
    }
}
/// <summary>
/// admin check
/// </summary>
bool ElavCheck() {
    BOOL isAdmin = FALSE;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;

    if (AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &AdministratorsGroup
    )) {
        if (!CheckTokenMembership(NULL, AdministratorsGroup, &isAdmin)) {
            isAdmin = FALSE;
        }

        FreeSid(AdministratorsGroup);
    }

    return isAdmin;
}

bool ElavPerf() {
    wchar_t szPath[MAX_PATH];
    if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath))) {
        SHELLEXECUTEINFO sei = { sizeof(sei) };
        sei.lpVerb = L"runas";
        sei.lpFile = szPath;
        sei.hwnd = NULL;
        sei.nShow = SW_NORMAL;

        if (!ShellExecuteEx(&sei)) {
            DWORD dwError = GetLastError();
            if (dwError == ERROR_CANCELLED) {
                return false;
            }
        }
        else {
            return true;
        }
    }
    return false;
}
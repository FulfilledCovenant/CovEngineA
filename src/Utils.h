#pragma once
#include <windows.h>

HKEY OpenCKey(HKEY hKey, LPCWSTR path, REGSAM samDesired);
bool DWORDSET(HKEY hKey, LPCWSTR valueName, DWORD data);
bool SetVal(HKEY hKey, LPCWSTR valueName, LPCWSTR data);
bool ElavCheck();
bool ElavPerf();
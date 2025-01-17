#include "QolTweaks.h"
#include "Utils.h"
#include <windows.h>
#include <iostream>

void QolTweaks(const json& config) {
    ContxtShow(config);
    AccTlNo(config);
    LkUpStNo(config);
    CoNo(config);
    FileAssocNo(config);
    DiskWarnNo(config);
    MeetNo(config);
    MenShowDl(config);
    NavNetNo(config);
    IntNewsNo(config);
    RecoNo(config);
    SInvalidNo(config);
    SharWizNo(config);
    SufNo(config);
    OffShowNo(config);
    StUpDlNo(config);
    StckKeysNo(config);
    TabMdNo(config);
    WpQualNo(config);
    WarnSNo(config);
    Win11StBan(config);
    IcoCacheNo(config);
    HdFold(config);
    FExplNo(config);
    RecItNo(config);
    MsHvrNo(config);
    WinExplONo(config);
    CastDvcNo(config);
    TdPtNo(config);
    ExtNo(config);
    LibCtxMenNo(config);
    BitMpNo(config);
    RchTxtCMNo(config);
    ExplVerNo(config);
    CtxShareNo(config);
    TbShtCtxNo(config);
    RstOCtxMenNo(config);
    ExtFAFls(config);
    StMnPins(config);
    AltClsTabUs(config);
}

void ContxtShow(const json& config) {
    if (config.value("Always Show Full Context Menu on Items", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32", KEY_SET_VALUE);
    if (hKey) {
        if (RegSetValueEx(hKey, L"", 0, REG_SZ, (const BYTE*)L"", sizeof(L"")) != ERROR_SUCCESS) {
            std::cerr << "Error setting default value for InprocServer32" << std::endl;
        }
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Error opening/creating key: Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32" << std::endl;
    }
}

void AccTlNo(const json& config) {
    if (config.value("Disable Accessibility Tool Shortcut", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Accessibility", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"Configuration", L" ");
        RegCloseKey(hKey);
    }
}

void LkUpStNo(const json& config) {
    if (config.value("Disable App Lookup in Store", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoUseStoreOpenWith", 1);
        RegCloseKey(hKey);
    }
}

void CoNo(const json& config) {
    if (config.value("Disable Copilot", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Windows\\WindowsCopilot", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"TurnOffWindowsCopilot", 1);
        RegCloseKey(hKey);
    }
}

void FileAssocNo(const json& config) {
    if (config.value("Disable Internet File Assocation Service", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"Software\\Policies\\Microsoft\\Windows\\System", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnableFileAssociate", 0);
        RegCloseKey(hKey);
    }
}

void DiskWarnNo(const json& config) {
    if (config.value("Disable Low Disk Space Warning", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoLowDiskSpaceChecks", 1);
        RegCloseKey(hKey);
    }
}

void MeetNo(const json& config) {
    if (config.value("Disable Meet Now", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"HideSCAMeetNow", 1);
        RegCloseKey(hKey);
    }
}

void MenShowDl(const json& config) {
    if (config.value("Disable Menu Show Delay", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Desktop", KEY_SET_VALUE);
    if (hKey) {

        SetVal(hKey, L"MenuShowDelay", L"0");
        RegCloseKey(hKey);
    }
}

void NavNetNo(const json& config) {
    if (config.value("Disable Network Navigation Pane in Explorer", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Classes\\CLSID\\{F02C1A0D-BE21-4350-88B0-7367FC96EF3C}", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"System.IsPinnedToNameSpaceTree", L"0");
        RegCloseKey(hKey);
    }
}

void IntNewsNo(const json& config) {
    if (config.value("Disable News and Interest", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Feeds", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"ShellFeedsTaskbarViewMode", 2);
        RegCloseKey(hKey);
    }
}

void RecoNo(const json& config) {
    if (config.value("Disable Recommendation on Start Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoRecommendedFiles", 1);
        RegCloseKey(hKey);
    }
}

void SInvalidNo(const json& config) {
    if (config.value("Disable Searching for Invalid Shortcuts", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoResolveSearch", 1);
        RegCloseKey(hKey);
    }
}

void SharWizNo(const json& config) {
    if (config.value("Disable Sharing Wizard", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoSharingWizard", 1);
        RegCloseKey(hKey);
    }
}

void SufNo(const json& config) {
    if (config.value("Disable Shortcut Suffix", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Link", 0);
        RegCloseKey(hKey);
    }
}

void OffShowNo(const json& config) {
    if (config.value("Disable Show Office Files", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"ShowRecent", 0);
        RegCloseKey(hKey);
    }
}

void StUpDlNo(const json& config) {
    if (config.value("Disable Startup Delay", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Serialize", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"StartupDelayInMSec", 0);
        RegCloseKey(hKey);
    }
}

void StckKeysNo(const json& config) {
    if (config.value("Disable Sticky Keys", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Accessibility\\StickyKeys", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"Flags", L"506");
        RegCloseKey(hKey);
    }
}

void TabMdNo(const json& config) {
    if (config.value("Disable Tablet Mode", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"TabletMode", 0);
        RegCloseKey(hKey);
    }
}

void WpQualNo(const json& config) {
    if (config.value("Disable Wallpaper Quality Reduction", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Personalization", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"DisableImageCompression", 1);
        RegCloseKey(hKey);
    }
}

void WarnSNo(const json& config) {
    if (config.value("Disable Warning Sounds", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"AppEvents\\Schemes\\Apps\\.Default\\Notification.Default", KEY_SET_VALUE);
    if (hKey) {
        
        if (RegSetValueEx(hKey, L"", 0, REG_SZ, (const BYTE*)L"", sizeof(L"")) != ERROR_SUCCESS) {
            std::cerr << "Error setting default value" << std::endl;
        }
        RegCloseKey(hKey);
    }
}

void Win11StBan(const json& config) {
    if (config.value("Disable Windows 11 Settings Home Page", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"HideSCA", 1);
        RegCloseKey(hKey);
    }
}

void IcoCacheNo(const json& config) {
    if (config.value("Extend Icon Cache", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"Max Cached Icons", L"4096");
        RegCloseKey(hKey);
    }
}

void HdFold(const json& config) {
    if (config.value("Hide Folders from This PC", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A8CDFF1C-4878-43be-B5FD-F8091C1C60D0}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{d3162b92-9365-467a-956b-92703aca08af}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{374DE290-123F-4565-9164-39C4925E467B}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{088e3905-0323-4b02-9826-5d99428e115f}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{1CF12D6D-4AEB-450F-A15E-F5F5D5C965BA}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{3ADD1653-EB32-4cb0-BBD7-DFA0ABB5ACCA}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{24ad3ad4-a569-4530-98e1-ab02f9417aa3}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{A0953C92-50DC-43bf-BE83-3742FED03C9C}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
    hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
}

void FExplNo(const json& config) {
    if (config.value("Hide Gallery in File Explorer", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideFileExt\\{e88865ea-0e1c-4e20-9aa6-edcd0212c87c}", KEY_SET_VALUE);
    if (hKey) {
        if (RegSetValueEx(hKey, L"", 0, REG_SZ, (const BYTE*)L"", sizeof(L"")) != ERROR_SUCCESS) {
            std::cerr << "Error setting default value to hide Gallery" << std::endl;
        }
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Error opening/creating key to hide Gallery" << std::endl;
    }
}

void RecItNo(const json& config) {
    if (config.value("Hide Recent Items", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"NoRecentDocsHistory", 1);
        RegCloseKey(hKey);
    }
}

void MsHvrNo(const json& config) {
    if (config.value("Minimize Mouse Hover Time for Item Info", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Control Panel\\Mouse", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"MouseHoverTime", L"10");
        RegCloseKey(hKey);
    }
}

void WinExplONo(const json& config) {
    if (config.value("Open Windows Explorer to This PC", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"LaunchTo", 1);
        RegCloseKey(hKey);
    }
}

void CastDvcNo(const json& config) {
    if (config.value("Remove Cast to Device from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Blocked", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"{7AD84985-87B4-4a16-BE58-8B72A5B390F7}", L"Cast to Device");
        RegCloseKey(hKey);
    }
}

void TdPtNo(const json& config) {
    if (config.value("Remove Edit with Paint 3D from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CLASSES_ROOT, L"SystemFileAssociations\\image\\shell\\edit", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"ProgrammaticAccessOnly", L"");
        RegCloseKey(hKey);
    }
}

void ExtNo(const json& config) {
    if (config.value("Remove Extract All from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CLASSES_ROOT, L"CompressedFolder\\ShellEx\\ContextMenuHandlers\\{b8cdcb65-b1bf-4b42-9428-1dfdb7ee92af}", KEY_SET_VALUE);
    if (hKey) {
        if (RegSetValueEx(hKey, L"", 0, REG_SZ, (const BYTE*)L"", sizeof(L"")) != ERROR_SUCCESS) {
            std::cerr << "Error setting default value" << std::endl;
        }
        RegCloseKey(hKey);
    }
}

void LibCtxMenNo(const json& config) {
    if (config.value("Remove Include in Library from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Blocked", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"{7BA4C740-9E81-11CF-99D3-00AA004AE837}", L"");
        RegCloseKey(hKey);
    }
}

void BitMpNo(const json& config) {
    if (config.value("Remove New Bitmap Image from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CLASSES_ROOT, L".bmp\\ShellNew", KEY_SET_VALUE);
    if (hKey) {
        if (RegDeleteValue(hKey, L"NullFile") != ERROR_SUCCESS) {
            std::cerr << "Error deleting NullFile value" << std::endl;
        }
        RegCloseKey(hKey);
    }
}

void RchTxtCMNo(const json& config) {
    if (config.value("Remove New Rich Text Document from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CLASSES_ROOT, L".rtf\\ShellNew", KEY_SET_VALUE);
    if (hKey) {
        if (RegDeleteValue(hKey, L"NullFile") != ERROR_SUCCESS) {
            std::cerr << "Error deleting NullFile value" << std::endl;
        }
        RegCloseKey(hKey);
    }
}

void ExplVerNo(const json& config) {
    if (config.value("Remove Previous Version from Explorer", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"EnablePreviousVersionsPage", 0);
        RegCloseKey(hKey);
    }
}

void CtxShareNo(const json& config) {
    if (config.value("Remove Share from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Blocked", KEY_SET_VALUE);
    if (hKey) {
        
        SetVal(hKey, L"{f81e9010-6ea4-11ce-a7ff-00aa003ca9f6}", L"");
        RegCloseKey(hKey);
    }
}

void TbShtCtxNo(const json& config) {
    if (config.value("Remove Troubleshoot Compatibility from Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CLASSES_ROOT, L"exefile\\shellex\\ContextMenuHandlers\\Compatibility", KEY_SET_VALUE);
    if (hKey) {
        if (RegSetValueEx(hKey, L"", 0, REG_SZ, (const BYTE*)L"", sizeof(L"")) != ERROR_SUCCESS) {
            std::cerr << "Error setting default value" << std::endl;
        }
        RegCloseKey(hKey);
    }
}

void RstOCtxMenNo(const json& config) {
    if (config.value("Restore Old Context Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32", KEY_SET_VALUE);
    if (hKey) {
        RegDeleteTree(hKey, L"");
        RegCloseKey(hKey);
    }
}

void ExtFAFls(const json& config) {
    if (config.value("Show Extensions for All Files", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"HideFileExt", 0);
        RegCloseKey(hKey);
    }
}

void StMnPins(const json& config) {
    if (config.value("Show More Pins on Start Menu", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"Start_TrackDocs", 0);
        RegCloseKey(hKey);
    }
}

void AltClsTabUs(const json& config) {
    if (config.value("Use Classic Alt + Tab", "NO") != "YES") {
        return;
    }
    HKEY hKey = OpenCKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", KEY_SET_VALUE);
    if (hKey) {
        
        DWORDSET(hKey, L"AltTabSettings", 1);
        RegCloseKey(hKey);
    }
}
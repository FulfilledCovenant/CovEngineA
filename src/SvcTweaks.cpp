#include "SvcTweaks.h"
#include "Utils.h"
#include <iostream>
#include <windows.h>
#include <string>

void SvcTweaks(const json& config) {
    ZoneMod(config);
    CncTelem(config);
    DeviceMng(config);
    StndCl(config);
    HlthSvcNo(config);
    sshNo(config);
    NfcSvcNo(config);
    SplNo(config);
    PcaNo(config);
    RasNo(config);
    SysMNo(config);
    BioNo(config);
    XboxNo(config);
}

void ZoneMod(const json& config) {
    if (config.value("Disable Auto Time Zone Updater Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"tzautoupdate\" & sc config \"tzautoupdate\" start=disabled");
}

void CncTelem(const json& config) {
    if (config.value("Disable Connected User Experiences and Telemetry Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"DiagTrack\" & sc config \"DiagTrack\" start=disabled");
}

void DeviceMng(const json& config) {
    if (config.value("Disable Device Management Wireless Application Protocol (WAP) Push message Routing Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"dmwappushservice\" & sc config \"dmwappushservice\" start=disabled");
}

void StndCl(const json& config) {
    if (config.value("Disable Microsoft (R) Diagnostics Hub Standard Collector Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"diagnosticshub.standardcollector.service\" & sc config \"diagnosticshub.standardcollector.service\" start=disabled");
}

void HlthSvcNo(const json& config) {
    if (config.value("Disable Microsoft Update Health Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"uhssvc\" & sc config \"uhssvc\" start=disabled");
}

void sshNo(const json& config) { 
    if (config.value("Disable OpenSSH Authentication Agent", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"ssh-agent\" & sc config \"ssh-agent\" start=disabled");
}

void NfcSvcNo(const json& config) {
    if (config.value("Disable Payments and NFC/SE Manager Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"SEMgrSvc\" & sc config \"SEMgrSvc\" start=disabled");
}

void SplNo(const json& config) {
    if (config.value("Disable Print Spooler Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"Spooler\" & sc config \"Spooler\" start=disabled");
}

void PcaNo(const json& config) {   
    if (config.value("Disable Program Compatibility Assistant Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"PcaSvc\" & sc config \"PcaSvc\" start=disabled");
}

void RasNo(const json& config) {
    if (config.value("Disable Routing and Remote Access Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"RemoteAccess\" & sc config \"RemoteAccess\" start=disabled");
}

void SysMNo(const json& config) {
    if (config.value("Disable SysMain Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"SysMain\" & sc config \"SysMain\" start=disabled");
}

void BioNo(const json& config) {
    if (config.value("Disable Windows Biometric Service", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"WbioSrvc\" & sc config \"WbioSrvc\" start=disabled");
}

void XboxNo(const json& config) {
    if (config.value("Disable Xbox Services", "NO") != "YES") {
        return;
    }
    std::system("sc stop \"XblAuthManager\" & sc config \"XblAuthManager\" start=disabled");
    std::system("sc stop \"XblGameSave\" & sc config \"XblGameSave\" start=disabled");
    std::system("sc stop \"XboxNetApiSvc\" & sc config \"XboxNetApiSvc\" start=disabled");
    std::system("sc stop \"XboxGipSvc\" & sc config \"XboxGipSvc\" start=disabled");
}
#pragma once

#include "nlohmann/json.hpp"
#include "Utils.h"

using json = nlohmann::json;
void SvcTweaks(const json& config);
/// <summary>
/// tweaks the auto time zone updater service
/// </summary>
void ZoneMod(const json& config);
/// <summary>
/// tweaks the connected exp and telem
/// </summary>
void CncTelem(const json& config);
/// <summary>
/// tweaks the device management WAP push rt
/// </summary>
void DeviceMng(const json& config);
/// <summary>
/// tweaks the diagnostics hub
/// </summary>
void StndCl(const json& config);
/// <summary>
/// tweaks the update health service
/// </summary>
void HlthSvcNo(const json& config);
/// <summary>
/// tweaks the OpenSSH authentication agent service
/// </summary>
void sshNo(const json& config);
/// <summary>
/// yweaks the payments and NFC/SE manager service
/// </summary>
void NfcSvcNo(const json& config);
/// <summary>
/// yweaks the print spooler service
/// </summary>
void SplNo(const json& config);
/// <summary>
/// tweaks the program compatibility assistant service
/// </summary>
void PcaNo(const json& config);
/// <summary>
/// tweaks the routing and remote access service
/// </summary>
void RasNo(const json& config);
/// <summary>
/// tweaks the sysmain service
/// </summary>
void SysMNo(const json& config);
/// <summary>
/// tweaks the windows biometric service
/// </summary>
void BioNo(const json& config);
/// <summary>
/// tweaks all Xbox services
/// </summary>
void XboxNo(const json& config);
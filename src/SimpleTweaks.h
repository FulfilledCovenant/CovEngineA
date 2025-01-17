#pragma once
#include "nlohmann/json.hpp"
#include "utils.h"

using json = nlohmann::json;
//
//
///	
//
//
void SimpleTweaks(const json& config);

/// <summary>
/// reads config file
/// </summary>
bool ReadConfig(json& config);

/// <summary>
/// creates default config 
/// </summary>
json DefConfig();

/// <summary>
/// displays current config
/// </summary>
void CurrentConf(const json& config);

/// <summary>
/// tweaks action center
/// </summary>
void ActCenter(const json& config);

/// <summary>
/// tweaks auto maintenance
/// </summary>
void MaintenNo(const json& config);

/// <summary>
/// tweaks cortana
/// </summary>
void CortNo(const json& config);

/// <summary>
/// tweaks download blocking
/// </summary>
void DownBlckNo(const json& config);

/// <summary>
/// tweaks driver updates
/// </summary>
void DrivUpdNo(const json& config);

/// <summary>
/// tweaks error reporting
/// </summary>
void ErrorNo(const json& config);

/// <summary>
/// tweaks lock screen
/// </summary>
void LockNo(const json& config);

/// <summary>
/// tweaks edge install
/// </summary>
void EdgeNo(const json& config);

/// <summary>
/// tweaks mrt updates
/// </summary>
void MrtNo(const json& config);

/// <summary>
/// tweaks ms store updates
/// </summary>
void StoreUpdNo(const json& config);

/// <summary>
/// tweaks system restore (not recommended)
/// </summary>
void SysRestNo(const json& config);

/// <summary>
/// tweaks uac prompt
/// </summary>
void UacNo(const json& config);

/// <summary>
/// tweaks ink
/// </summary>
void InkNo(const json& config);

/// <summary>
/// tweaks windows updates
/// </summary>
void WinUpdNo(const json& config);

/// <summary>
/// tweaks win update pause status
/// </summary>
void WinUpdPsNo(const json& config);
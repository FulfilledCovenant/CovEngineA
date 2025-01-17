#pragma once
#include "nlohmann/json.hpp"
#include "Utils.h"

using json = nlohmann::json;

/// <summary>
/// performs privacy tweaks
/// </summary>
void DoPrivTweaks(const json& config);

/// <summary>
/// tweaks location
/// </summary>
void TrackingNo(const json& config);

/// <summary>
/// tweaks telemetry
/// </summary>
void TelemNo(const json& config);

/// <summary>
/// tweaks app access
/// </summary>
void AppAccNo(const json& config);

/// <summary>
/// tweaks feedback
/// </summary>
void FbNo(const json& config);

/// <summary>
/// tweaks diagnostics
/// </summary>
void DiaDataNo(const json& config);

/// <summary>
/// tweaks tailored
/// </summary>
void TlExpNo(const json& config);

/// <summary>
/// tweaks activity history
/// </summary>
void ActHisNo(const json& config);

/// <summary>
/// tweaks settings sync
/// </summary>
void SetSyncNo(const json& config);
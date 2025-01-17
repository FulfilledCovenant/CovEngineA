#pragma once
#include "nlohmann/json.hpp"
#include "Utils.h"

using json = nlohmann::json;
void NetDoTweaks(const json& config);
void NetConf(const json& config);
void SMBandNo(const json& config);
void AnonAccRes(const json& config);
/// <summary>
/// tweaks anonymous share
/// </summary>
void AnonShareRes(const json& config);
/// <summary>
/// tweaks LLMNR protocol
/// </summary>
void LLMNRNo(const json& config);
/// <summary>
/// tweaks miscellaneous network settings
/// </summary>
void NetMisc(const json& config);
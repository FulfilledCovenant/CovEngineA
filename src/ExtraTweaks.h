#pragma once
#include "nlohmann/json.hpp"
#include "Utils.h"

using json = nlohmann::json;
void ExtraTweaks(const json& config);
void MsAccelNo(const json& config);
void VisBetter(const json& config);
void FstShut(const json& config);
void AutorunNo(const json& config);
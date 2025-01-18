#pragma once
#include "../nlohmann/json.hpp"
#include "../Utils.h"

using json = nlohmann::json;
void ExtTwks(const json& config);
void DisASLR(const json& config);
void CSRSSRRT(const json& config);
void LtcTol(const json& config);
void IRQPrior(const json& config);
void SysResE(const json& config);
void GPUEng(const json& config);
void EngLogDis(const json& config);
void AppsUni(const json& config);
void LogiProcEn(const json& config);
void DisCStates(const json& config);
void HighPSt(const json& config);
void CorePKDis(const json& config);
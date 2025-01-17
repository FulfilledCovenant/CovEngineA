#pragma once
#include "nlohmann/json.hpp"
#include "Utils.h"

using json = nlohmann::json;
void DoPerfTweaks(const json& config);
void BCDEditConf(const json& config);
void MmcssConf(const json& config);
void AutoDisc(const json& config);
void BackAppsDis(const json& config);
void BootTraceDis(const json& config);
void FaultHeapDis(const json& config);
void PagingDis(const json& config);
void PFetchNo(const json& config);
void SvcHsSpltDis(const json& config);
void SlpStdNo(const json& config);
void SpecMeltDis(const json& config);
void StartUpApsDis(const json& config);
void VbsDis(const json& config);
void WinDefDis(const json& config);
void DwmOpt(const json& config);
void FsoOpt(const json& config);
void NtfsOpt(const json& config);
void MsOpt(const json& config);
void NvmeOpt(const json& config);
void Win32Prior(const json& config);
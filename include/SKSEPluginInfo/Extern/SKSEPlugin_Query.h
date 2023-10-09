#pragma once

// This is for all versions of CommonLib/SKSE

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) bool SKSEAPI
    SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info) {
    a_info->infoVersion = SKSE::PluginInfo::kVersion;
    a_info->name        = SKSEPluginInfo::GetPluginName();
    a_info->version     = SKSEPluginInfo::GetPluginVersion.pack();
    if (a_skse->IsEditor()) return false;
    return true;
}

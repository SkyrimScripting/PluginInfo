#pragma once

// This is for all versions of CommonLib/SKSE

#include <REL/Relocation.h>
#include <SKSE/SKSE.h>

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) bool SKSEAPI REL::Version version{
    SKSE::PluginInfo::GetPluginVersionMajor(), SKSE::PluginInfo::GetPluginVersionMinor(),
    SKSE::PluginInfo::GetPluginVersionPatch()};

SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info) {
    a_info->infoVersion = SKSE::PluginInfo::kVersion;
    a_info->name        = SKSEPluginInfo::GetPluginName();
    a_info->version     = SKSEPluginInfo::GetPluginVersionStruct().pack();
    if (a_skse->IsEditor()) return false;
    return true;
}

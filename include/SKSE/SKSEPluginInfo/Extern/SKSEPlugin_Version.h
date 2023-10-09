#pragma once

// This is only for AE 1.6+ SKSE plugins

#include <REL/Relocation.h>
#include <SKSE/SKSE.h>

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) constinit auto SKSEPlugin_Version = []() {
    SKSE::PluginVersionData v;
    v.PluginVersion(SKSEPluginInfo::GetPluginVersionStruct());
    v.PluginName(SKSEPluginInfo::GetPluginName());
    v.UsesAddressLibrary();
    v.UsesUpdatedStructs();

    return v;
}();

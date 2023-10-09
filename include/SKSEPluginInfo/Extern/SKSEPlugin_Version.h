#pragma once

// This is only for AE 1.6+ SKSE plugins

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) constinit auto SKSEPlugin_Version = []() {
    SKSE::PluginVersionData v;
    v.PluginVersion(SKSEPluginInfo::PluginVersion);
    v.PluginName(SKSEPluginInfo::PluginName);
    v.UsesAddressLibrary();
    v.UsesUpdatedStructs();
    return v;
}();

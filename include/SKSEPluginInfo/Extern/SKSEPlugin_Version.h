#pragma once

// This is only for AE 1.6+ SKSE plugins

#include <algorithm>
#include <span>

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) constinit auto SKSEPlugin_Version = []() {
    SKSE::PluginVersionData v{};

    v.PluginVersion(SKSEPluginInfo::PluginVersion);
    v.PluginName(SKSEPluginInfo::PluginName.data());
    v.AuthorName(SKSEPluginInfo::AuthorName.data());
    v.AuthorEmail(SKSEPluginInfo::AuthorEmail.data());

    v.UsesAddressLibrary(true);
    v.HasNoStructUse(true);
    v.UsesStructsPost629(false);

    return v;
}();

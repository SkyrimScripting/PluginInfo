#pragma once

// This is only for AE 1.6+ SKSE plugins

// For this include to work, the values must be defined as inline constexpr by the build system

#include <algorithm>
#include <span>

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) constinit auto SKSEPlugin_Version = []() {
    SKSE::PluginVersionData v{};

    v.PluginVersion(SKSEPluginInfoConstants::PluginVersion);
    v.PluginName(SKSEPluginInfoConstants::PluginName.data());
    v.AuthorName(SKSEPluginInfoConstants::AuthorName.data());
    v.AuthorEmail(SKSEPluginInfoConstants::AuthorEmail.data());

    v.UsesAddressLibrary();
    v.UsesUpdatedStructs();

    return v;
}();

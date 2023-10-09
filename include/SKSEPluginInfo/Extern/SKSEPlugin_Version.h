#pragma once

// This is only for AE 1.6+ SKSE plugins

#include "../SKSEPluginInfo.h"

extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
    .pluginVersion = SKSEPluginInfo::PluginVersion.pack(),
    .pluginName    = SKSEPluginInfo::PluginName.data(),
    .author        = SKSEPluginInfo::AuthorName.data(),
    .supportEmail  = SKSEPluginInfo::AuthorEmail.data(),
    /*
        kVersionIndependent_AddressLibraryPostAE = 1 << 0,
        kVersionIndependent_Signatures = 1 << 1,
        kVersionIndependent_StructsPost629 = 1 << 2,

        versionIndependency |= kVersionIndependent_AddressLibraryPostAE; (1 << 0)
        versionIndependency |= kVersionIndependent_StructsPost629; (1 << 2)

        versionIndependency = 5 (1 | 4) [0101 = 5]
    */
    .versionIndependence = 5};

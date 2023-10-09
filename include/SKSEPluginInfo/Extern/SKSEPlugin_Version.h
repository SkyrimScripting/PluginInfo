#pragma once

// This is only for AE 1.6+ SKSE plugins

#include <algorithm>
#include <span>

#include "../SKSEPluginInfo.h"

namespace {
    // Lovely hacky fun time to get the constinit working OK for the various string_view fields

    constexpr char[256] to_char_array_256(const std::string_view sv) {
        char arr[256] = {};
        for (size_t i = 0; i < sv.size() && i < 256; ++i) arr[i] = sv[i];
        return arr;
    }
    constexpr char[252] to_char_array_252(const std::string_view sv) {
        char arr[252] = {};
        for (size_t i = 0; i < sv.size() && i < 252; ++i) arr[i] = sv[i];
        return arr;
    }
}

// 	constexpr void AuthorEmail(std::string_view a_email) noexcept { SetCharBuffer(a_email,
// std::span{ supportEmail }); } 		constexpr void AuthorName(std::string_view a_name) noexcept
// { SetCharBuffer(a_name, std::span{ author }); } constexpr void PluginName(std::string_view
// a_plugin) noexcept { SetCharBuffer(a_plugin, std::span{ pluginName }); }

extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
    .pluginVersion = SKSEPluginInfo::PluginVersion.pack(),
    .pluginName    = to_char_array_256(SKSEPluginInfo::PluginName),
    .author        = to_char_array_256(SKSEPluginInfo::AuthorName),
    .supportEmail  = to_char_array_252(SKSEPluginInfo::AuthorEmail),
    /*
        kVersionIndependent_AddressLibraryPostAE = 1 << 0,
        kVersionIndependent_Signatures = 1 << 1,
        kVersionIndependent_StructsPost629 = 1 << 2,

        versionIndependency |= kVersionIndependent_AddressLibraryPostAE; (1 << 0)
        versionIndependency |= kVersionIndependent_StructsPost629; (1 << 2)

        versionIndependency = 5 (1 | 4) [0101 = 5]
    */
    .versionIndependence = 5};

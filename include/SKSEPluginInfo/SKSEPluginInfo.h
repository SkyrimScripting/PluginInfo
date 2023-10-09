#pragma once

// These functions need to be defined in your plugin's source file (or by a build system)

#include <SKSE/SKSE.h>
// ^ before REL/Relocation.h

#include <REL/Relocation.h>

#include <cstdint>
#include <string>

namespace SKSEPluginInfo {
    const char*   GetPluginName();
    std::uint16_t GetPluginVersionMajor();
    std::uint16_t GetPluginVersionMinor();
    std::uint16_t GetPluginVersionPatch();

    std::string GetPluginVersionString() {
        return std::to_string(GetPluginVersionMajor()) + "." +
               std::to_string(GetPluginVersionMinor()) + "." +
               std::to_string(GetPluginVersionPatch());
    }

    REL::Version GetPluginVersionStruct() {
        return REL::Version{
            GetPluginVersionMajor(), GetPluginVersionMinor(), GetPluginVersionPatch()};
    }
}

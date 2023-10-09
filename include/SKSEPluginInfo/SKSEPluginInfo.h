#pragma once

// These functions need to be defined in your plugin's source file (or by a build system)

#include <SKSE/SKSE.h>
// ^ before REL/Relocation.h

#include <REL/Relocation.h>

#include <cstdint>
#include <string>

namespace SKSEPluginInfo {
    extern const char*  PluginName;
    extern REL::Version PluginVersion;
}

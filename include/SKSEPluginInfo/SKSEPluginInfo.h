#pragma once

// These functions need to be defined in your plugin's source file (or by a build system)

#include <SKSE/SKSE.h>
// ^ before REL/Relocation.h

#include <REL/Relocation.h>

#include <cstdint>
#include <string_view>

namespace SKSEPluginInfo {
    extern const std::string_view PluginName;
    extern const std::string_view AuthorName;
    extern const std::string_view AuthorEmail;
    extern const REL::Version     PluginVersion;
}

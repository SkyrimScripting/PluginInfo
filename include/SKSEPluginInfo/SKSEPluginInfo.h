#pragma once

// These functions need to be defined in your plugin's source file (or by a build system)

// These are functions for flexibility

#include <SKSE/SKSE.h>
// ^ before REL/Relocation.h

#include <REL/Relocation.h>

namespace SKSEPluginInfo {
    extern const char*        GetPluginName;
    extern const char*        GetAuthorName;
    extern const char*        GetAuthorEmail;
    extern const REL::Version GetPluginVersion;
}

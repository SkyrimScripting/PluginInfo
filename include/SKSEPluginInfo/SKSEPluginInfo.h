#pragma once

// These functions need to be defined in your plugin's source file (or by a build system)

// These are functions for flexibility

#include <SKSE/SKSE.h>
// ^ before REL/Relocation.h

#include <REL/Relocation.h>

namespace SKSEPluginInfo {
    const char*        GetPluginName();
    const char*        GetAuthorName();
    const char*        GetAuthorEmail();
    const REL::Version GetPluginVersion();
}

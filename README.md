# SKSE Plugin Info

> Standard header for SKSE plugin info

Provides a common way for SKSE plugins to know their _own_ name and version.

[CommonLib NG](https://github.com/CharmedBaryon/CommonLibSSE-NG) provides this functionality via `SKSE::PluginDeclaration` but this is not a core feature of CommonLib.

## CommonLib Packages

This interface is integrated into the CommonLib packages available via: [SkyrimScripting/Packages](https://github.com/SkyrimScripting/Packages)

## Usage

If you are using a package which integrates `SKSEPluginInfo`, then you can simply include the header to read the plugin info.

```cpp
// ... my SKSE plugin ...

// Get the plugin name, e.g. "MyCoolPlugin"
const char* pluginName = SKSEPluginInfo::GetPluginName();

// Get the plugin version parts combined into a string, e.g. "1.0.0"
string pluginVersion = SKSEPluginInfo::GetPluginVersionString();
```

And if you want some more specific access to the plugin version:

```cpp
// Get the plugin version parts individually, e.g. 1, 0, 0
uint16_t pluginVersionMajor = SKSEPluginInfo::GetPluginVersionMajor();
uint16_t pluginVersionMinor = SKSEPluginInfo::GetPluginVersionMinor();
uint16_t pluginVersionPatch = SKSEPluginInfo::GetPluginVersionPatch();

// Get the plugin version parts as a REL::Version struct, e.g. { 1, 0, 0 }
REL::Version = SKSEPluginInfo::GetPluginVersionStruct();
```

## SKSE Plugin Setup

Helper headers are provided for defining these required DLL interfaces:

- `SKSEPlugin_Query`
- `SKSEPlugin_Version` (_only requires for Skyrim AE 1.6+_)

Here is a minimal working SKSE plugin using core CommonLib (_not NG_):

```cpp
#include <SKSE/SKSEPluginInfo.h>

// You need to define the plugin name and version yourself.
// Normally this would be handled by a build system for you.
const char* SKSE::SKSEPluginInfo::GetPluginName() { return "MyCoolPlugin"; }
std::uint16_t SKSE::SKSEPluginInfo::GetPluginVersionMajor() { return 1; }
std::uint16_t SKSE::SKSEPluginInfo::GetPluginVersionMinor() { return 0; }
std::uint16_t SKSE::SKSEPluginInfo::GetPluginVersionPatch() { return 0; }

// Now you can use helper headers to define the required DLL interfaces.
#include <SKSE/SKSEPluginInfo/Extern/SKSEPlugin_Query.h>
#include <SKSE/SKSEPluginInfo/Extern/SKSEPlugin_Version.h> // <--- only needed for AE

// Then you're ready to define your own entry point for the SKSE plugin
extern "C" __declspec(dllexport) bool SKSEPlugin_Load(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);

    // ...
    
    // If you need to get the plugin name, in your own plugin:
    auto pluginName = SKSE::SKSEPluginInfo::GetPluginName();

    // Or the version:
    auto pluginVersion = SKSE::SKSEPluginInfo::GetPluginVersionString();

    // ...

    return true;
}
```

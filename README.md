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
const char* pluginName = SKSEPluginInfo::PluginName;

// Get the plugin version parts combined into a string, e.g. "1.0.0"
std::string pluginVersion = SKSEPluginInfo::VersionString.string();
```

And if you want some more specific access to the plugin version:

```cpp
// ...
```

## SKSE Plugin Setup

Helper headers are provided for defining these required DLL interfaces:

- `SKSEPlugin_Query`
- `SKSEPlugin_Version` (_only requires for Skyrim AE 1.6+_)

Here is a minimal working SKSE plugin using core CommonLib (_not NG_):

```cpp
// ... TODO ...
```

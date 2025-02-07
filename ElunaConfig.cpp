/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifdef TRINITY
#include "Config.h"
#elif defined CMANGOS || defined VMANGOS
#include "Config/Config.h"
#endif
#include "ElunaConfig.h"

ElunaConfig::ElunaConfig()
{
}

ElunaConfig* ElunaConfig::instance()
{
    static ElunaConfig instance;
    return &instance;
}

ElunaConfig::~ElunaConfig()
{
}

void ElunaConfig::Initialize()
{
    // Load bools
    SetConfig(CONFIG_ELUNA_ENABLED, "Eluna.Enabled", true);
    SetConfig(CONFIG_ELUNA_COMPATIBILITY_MODE, "Eluna.CompatibilityMode", true);
    SetConfig(CONFIG_ELUNA_TRACEBACK, "Eluna.TraceBack", false);

    // Load strings
    SetConfig(CONFIG_ELUNA_SCRIPT_PATH, "Eluna.ScriptPath", "lua_scripts");
    SetConfig(CONFIG_ELUNA_ONLY_ON_MAPS, "Eluna.OnlyOnMaps", "");
}

void ElunaConfig::SetConfig(ElunaConfigBoolValues index, char const* fieldname, bool defvalue)
{
#ifdef TRINITY
    SetConfig(index, sConfigMgr->GetBoolDefault(fieldname, defvalue));
#elif defined CMANGOS || defined VMANGOS
    SetConfig(index, sConfig.GetBoolDefault(fieldname, defvalue));
#endif
}

void ElunaConfig::SetConfig(ElunaConfigStringValues index, char const* fieldname, std::string defvalue)
{
#ifdef TRINITY
    SetConfig(index, sConfigMgr->GetStringDefault(fieldname, defvalue));
#elif CMANGOS
    SetConfig(index, sConfig.GetStringDefault(fieldname, defvalue));
#elif VMANGOS
    SetConfig(index, sConfig.GetStringDefault(fieldname, defvalue.c_str()));
#endif
}

bool ElunaConfig::IsElunaEnabled()
{
    return GetConfig(CONFIG_ELUNA_ENABLED);
}

bool ElunaConfig::IsElunaCompatibilityMode()
{
    return GetConfig(CONFIG_ELUNA_COMPATIBILITY_MODE);
}

#pragma once

#include "Include/IncludeBase.h"

struct GConfig
{
    struct
    {
        GString _Prorocole;
        GString _Host;
        int32 _Port;
        GString _Scope;
    } _HttpConfig;

    struct {
        GString _Host = "localhost";
        int32 _Port = 8080;
    } _WsConfig;
};

class GConfigModule
{

public:
    static GConfig Config;
    static void init();
    static void loadNetConfig();

public:
    GConfigModule();
    ~GConfigModule();
    static GConfigModule *getInstance();
};
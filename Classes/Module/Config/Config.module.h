#pragma once

#include "Include/IncludeBase.h"

struct GConfig
{
    struct
    {
        GString ApiUrl;
        GString ApiFullUrl;
        GString ApiPort;
        GString ApiHost;
        GString ApiPath;
        GString ApiVersion;
    } ApiConfig;

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
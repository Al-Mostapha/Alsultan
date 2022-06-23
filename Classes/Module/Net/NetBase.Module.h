#pragma once
#include "Include/IncludeBase.h"
#include "network/HttpClient.h"

namespace Net = cocos2d::network;
typedef std::function<void(GJson *)> JsonStrCallBack;
class NetBaseModule
{

public:
    NetBaseModule();
    ~NetBaseModule();
    static Net::HttpRequest *_createHttp(const GString &url);
    static NetBaseModule *getInstance();
    static bool getJson(const GString &url, JsonStrCallBack callback);
    static void _post();
    static void _put();
    static void _delete();
    static void _head();
    static void _options();
    static void _trace();
    static void _connect();
    static void _patch();
};
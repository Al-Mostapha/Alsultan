#pragma once
#include "Include/IncludeBase.h"
#include "network/HttpClient.h"
#include "Base/Type/XJson.h"
#include "Base/Type/XFunction.h"
#include "Net.Enum.h"

namespace Net = cocos2d::network;
typedef std::function<void(const XJson &)> JsonStrCallBack;
class WsClient;
class IRequest;
class NetModule
{
    int32 _RequestCount = 0;
    int32 _WsPort;
    GString _Host;
  public:
    WsClient *_WsClient;

public:

    
    NetModule();
    ~NetModule();
    static NetModule *Get();
    void Init();
    void StartGame();
    void SetHost(GString pHost);
    void SetWsPort(int32 pPort);

    IRequest *GetJson(
      const GString &url, 
      GFunc<void(const XJson &, IRequest *)> pCallback = nullptr);
    IRequest *GetJson(
      const GString &url, const XJson &pParams,
      GFunc<void(const XJson &, IRequest *)> pCallback = nullptr);
    IRequest *GetJsonFile(
      const GString &url, 
      const GFunc<void(const XJson &, IRequest *)> &pCallback = nullptr);  
    IRequest *HttpGet(const GString &url, 
      const GFunc<void(const XJson &, IRequest *)> &pOnSuc = nullptr,
      const GFunc<void(ERequestError, GString)> &pOnError = nullptr
      );
    IRequest *HttpPost(const GString &url, const XJson &pParams = nullptr,
      GFunc<void(const XJson &, IRequest *)> pCallback = nullptr);
      
    Net::HttpRequest *_createHttp(const GString &url);
    static NetModule *getInstance();
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
#include "NetBase.Module.h"
#include "Module/Config/Config.module.h"
#include <iostream>
#include "WsClient.h"
#include "WsRequest.h"
#include "IResponse.h"
#include "Module/Player/Player.Static.h"

NetModule *NetModule::Get(){
    static NetModule *l_Inst = new NetModule();
    return l_Inst;
}
void NetModule::Init(){
  _WsClient = WsClient::Create(GConfigModule::Config._WsConfig._Host, GConfigModule::Config._WsConfig._Port);
  _WsClient->Connect();
}

void NetModule::SetHost(GString pHost){

}

void NetModule::SetWsPort(int32 pPort){

}


NetModule::NetModule()
{
}

NetModule::~NetModule()
{
}

NetModule *NetModule::getInstance()
{
    static NetModule instance;
    return &instance;
}

Net::HttpRequest *NetModule::_createHttp(const GString &url)
{

    Net::HttpRequest *request = new Net::HttpRequest();
    request->setUrl(GConfigModule::Config.ApiConfig.ApiFullUrl + url);
    return request;
}

bool NetModule::getJson(const GString &url, JsonStrCallBack callback)
{
    Net::HttpRequest *request = _createHttp(url);
    if (!request)
        return false;
    request->setRequestType(Net::HttpRequest::Type::GET);
    request->setResponseCallback(
        [callback](Net::HttpClient *sender, Net::HttpResponse *response)
        {
            if (response->isSucceed())
            {
                GString responseStr = GString(response->getResponseData()->begin(), response->getResponseData()->end());
                GJson JsonObject;
                JsonObject.Parse(responseStr.c_str());
                if (JsonObject.HasParseError())
                {
                    cocos2d::log("Error: %s\n", JsonObject.GetParseError());
                    if (callback)
                        callback(nullptr);
                    return;
                }
                std::cout << responseStr;
                cocos2d::log("Responce %s", response->getResponseData());
                callback(&JsonObject);
            }
            else
            {
                cocos2d::log("Error: %s\n", response->getErrorBuffer());
                callback(nullptr);
            }
        });
    Net::HttpClient::getInstance()->send(request);
    request->release();
    return true;
    // request->setUrl("");
}

IRequest *NetModule::GetJson(
  const GString &url, std::function<void(const XJson &, IRequest *)>  pCallback){
  return GetJson(url, {}, pCallback);
}
IRequest *NetModule::GetJson(
  const GString &url, const XJson &pParams,
  std::function<void(const XJson &, IRequest *)>  pCallback){
  auto lRequest = WsRequest::Create(url);
  lRequest->_Url = url;
  lRequest->_Method      = ERequestMethod::Get;
  lRequest->_ContentType = ERequestContentType::Json;
  lRequest->_Type        = ERequestType::WebSocket;
  lRequest->_Token       = PlayerStatic::Get()->GetPlayerToken();
  lRequest->_Data        = pParams.dump();
  lRequest->_OnComplete  = [pCallback, lRequest](IResponse *pResponse, IRequest *pRequest) {
    if(!pResponse){
      if(lRequest->_OnError)
        lRequest->_OnError(ERequestError::NoResponse, "Response is null");
      throw "Response is null";
    }
    if(!pResponse->IsJson()){
      if(lRequest->_OnError)
        lRequest->_OnError(ERequestError::NotJson, "Response is null");
      throw "Response is not json";
    }
    pCallback(pResponse->_Json, pRequest);
  };
  lRequest->Send();
  return lRequest;
}
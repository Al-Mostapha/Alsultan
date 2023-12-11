#include "NetBase.Module.h"
#include "Module/Config/Config.module.h"
#include <iostream>
#include "WsClient.h"
#include "WsRequest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "IResponse.h"
#include "Module/Player/Player.Static.h"

NetModule *NetModule::Get(){
    static NetModule *l_Inst = new NetModule();
    return l_Inst;
}
void NetModule::Init(){

}

void NetModule::StartGame(){
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
    request->setUrl(url);
    return request;
}


bool NetModule::getJson(const GString &pUrl, JsonStrCallBack callback)
{
    Net::HttpRequest *request = nullptr;
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
        
    request->setUrl("");
    Net::HttpClient::getInstance()->send(request);
    request->release();
    return true;
}

IRequest *NetModule::GetJsonFile(
  const GString &pUrl, 
  const GFunc<void(const XJson &, IRequest *)> &pCallback){
    return HttpGet(pUrl, pCallback);
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

IRequest *NetModule::HttpGet(const GString &url, 
  const GFunc<void(const XJson &, IRequest *)> &pOnSuccess,
  const GFunc<void(ERequestError, GString)> &pOnError
  ){
    
  HttpRequest *lRequest = HttpRequest::Create(url);
  lRequest->_Method      = ERequestMethod::Get;
  lRequest->_ContentType = ERequestContentType::Json;
  lRequest->_Type        = ERequestType::Http;
  lRequest->_Token       = PlayerStatic::Get()->GetPlayerToken();
  lRequest->_Data        = "";
  lRequest->_OnSuccess  = [=](IResponse *pResponse, IRequest *pRequest) {
    if(!pResponse){
      if(lRequest->_OnError)
        lRequest->_OnError(ERequestError::NoResponse, "Response is null");
      if(pOnError)
        pOnError(ERequestError::NoResponse, "Response is null");
      return;
    }
    if(!pResponse->IsJson()){
      if(lRequest->_OnError)
        lRequest->_OnError(ERequestError::NotJson, "Response is null");
      if(pOnError)
        pOnError(ERequestError::NotJson, "Response is null");
      return;
    }
    pOnSuccess(pResponse->_Json, pRequest);
  };
  lRequest->Send();

  return lRequest;
}

IRequest *HttpPost(const GString &url, const XJson &pParams,
  std::function<void(const XJson &, IRequest *)> pCallback){
  return nullptr;
}
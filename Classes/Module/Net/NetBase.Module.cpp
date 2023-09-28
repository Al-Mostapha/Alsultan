#include "NetBase.Module.h"
#include "Module/Config/Config.module.h"
#include <iostream>

static NetModule *Get(){
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
#include "NetBase.Module.h"
#include "Module/Config/Config.module.h"

NetBaseModule::NetBaseModule()
{
}

NetBaseModule::~NetBaseModule()
{
}

NetBaseModule *NetBaseModule::getInstance()
{
    static NetBaseModule instance;
    return &instance;
}

Net::HttpRequest *NetBaseModule::_createHttp(const GString &url)
{

    Net::HttpRequest *request = new Net::HttpRequest();
    request->setUrl(GConfigModule::Config.ApiConfig.ApiFullUrl + url);
    return request;
}

bool NetBaseModule::getJson(const GString &url, JsonStrCallBack callback)
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
                    callback(nullptr);
                    return;
                }
                cocos2d::log("Responce %s", responseStr.c_str());
            callback(&JsonObject);
            }
            else
            {
                cocos2d::log("Error: %s\n", response->getErrorBuffer());
                callback(nullptr);
        } });
    Net::HttpClient::getInstance()->send(request);
    request->release();
    return true;
    // request->setUrl("");
}
#include "HttpRequest.h"
#include "Module/Config/Config.module.h"
#include "HttpResponse.h"
#include "NetBase.Module.h"


HttpRequest *HttpRequest::Create()
{
  auto lReq =  new HttpRequest();
  auto lUUid = GenerateUUID();
  lReq->SetRequestID(lUUid);
  return lReq;
}


void HttpRequest::SetUrl(const GString &pUrl)
{
    auto lUrl =
    GConfigModule::Config._HttpConfig._Prorocole + "://" 
    + GConfigModule::Config._HttpConfig._Host + ":" 
    + std::to_string(GConfigModule::Config._HttpConfig._Port) 
    + pUrl;
  IRequest::SetUrl(lUrl);
}

HttpRequest *HttpRequest::Create(const GString &pUrl){

  auto lReq =  Create();
  lReq->SetUrl(pUrl);
  return lReq;
}

HttpRequest *HttpRequest::Create(const GString &pUrl, ReqCallback pSuccess){
  auto lReq =  Create();
  lReq->SetUrl(pUrl);
  lReq->_OnSuccess = pSuccess;
  return lReq;
}
  
void HttpRequest::SetHttpMethod()
{
  switch (_Method)
  {
  case ERequestMethod::Get:
    _Request->setRequestType(Net::HttpRequest::Type::GET);
    break;
  case ERequestMethod::Post:
    _Request->setRequestType(Net::HttpRequest::Type::POST);
    break;
  case ERequestMethod::Put:
    _Request->setRequestType(Net::HttpRequest::Type::PUT);
    break;
  case ERequestMethod::Delete:
    _Request->setRequestType(Net::HttpRequest::Type::DELETE);
    break;
  default:
    break;
  }
}

void HttpRequest::SetHttpCallBack(){
  _Request->setResponseCallback(
  [this](Net::HttpClient *lSender, Net::HttpResponse *lRes)
  {
    if (lRes->isSucceed())
    {
      GString lResString = GString(lRes->getResponseData()->begin(), lRes->getResponseData()->end());
      XJson lJsonObject;
      try{
          lJsonObject = XJson::parse(lResString.c_str());
      } catch (const XJson::exception& e) {
          Logger::Get()->Log("Error: \n" + GString(e.what()));
          if(_OnError) _OnError(ERequestError::NotJson, "Json Parse Error");
          return;
      }
      if (lJsonObject.is_null())
      {
          Logger::Get()->Log("Error: \n" + lJsonObject.dump());
          if (_OnError) _OnError(ERequestError::NotJson, "Json is null");
          return;
      }
        Logger::Get()->Log("Json From Request: \n" + lJsonObject.dump(), ELogLvl::Info);
        Logger::Get()->Log("Response \n" + lResString, ELogLvl::Info);
        auto lResponse = HttpResponse::Create(lRes);
        lResponse->FromJson(lJsonObject);
        lResponse->Exec();
        if(_OnSuccess) _OnSuccess(lResponse, this);
    }
    else
    {
        Logger::Get()->Log("Error: \n" + GString(lRes->getErrorBuffer()));
        if(_OnError)
        _OnError(ERequestError::NoResponse, "");
    }
  });
}

void HttpRequest::Send()
{
    _Request = NetModule::Get()->_createHttp(_Url);
    if (!_Request)
        return;
    SetHttpMethod();
    SetHttpCallBack();
    Net::HttpClient::getInstance()->send(_Request);
    _Request->release();
    return ;
}
#include "HttpResponse.h"

HttpResponse *HttpResponse::Create(cocos2d::network::HttpResponse *_Response)
{
  auto lRes = new HttpResponse();
  lRes->_Data = GString(_Response->getResponseData()->begin(), _Response->getResponseData()->end());
  return lRes;
}

void HttpResponse::FromJson(const XJson &pJson)
{
  _Json = pJson;
}

void HttpResponse::Exec()
{

}
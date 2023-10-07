#include "WsResponse.h"

WSResponse *WSResponse::Create(const GString &pMsg)
{
  auto lRes = new WSResponse();
  lRes->_Data = pMsg;
  return lRes;
}

void WSResponse::FromJson(const XJson &pJson)
{
  _Json = pJson;
}

void WSResponse::FromWsMsg()
{
  _Json = XJson::parse(_Data);
}

void WSResponse::Exec()
{

}
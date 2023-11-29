#include "WsRequest.h"
#include "NetBase.Module.h"
#include "WsClient.h"



WsRequest *WsRequest::Create()
{
  auto lReq =  new WsRequest();
  auto lUUid = GenerateUUID();
  lReq->SetRequestID(lUUid);
  return lReq;
}


WsRequest *WsRequest::Create(const GString &pUrl){
  auto lReq =  Create();
  lReq->SetUrl(pUrl);
  return lReq;
}

WsRequest *WsRequest::Create(const GString &pUrl, ReqCallback pSuccess){
  auto lReq =  Create();
  lReq->SetUrl(pUrl);
  lReq->_OnSuccess = pSuccess;
  return lReq;
}
  


void WsRequest::Send()
{
  auto lWsClient = NetModule::Get()->_WsClient;
  if(!lWsClient)
    return;
  lWsClient->Send(this);
}
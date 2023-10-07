#include "WsRequest.h"
#include "NetBase.Module.h"
#include "WsClient.h"

GString GenerateUUID() {
    char buffer[64];
    snprintf(buffer, sizeof(buffer),
            "%04X%04X-%04X-%04X-%04X-%04X%04X%04X",
            rand() & 0xFFFF, rand() & 0xFFFF,
            rand() & 0xFFFF,
            ((rand() & 0x0FFF) | 0x4000),
            rand() & 0x3FFF | 0x8000,
            rand() & 0xFFFF, rand() & 0xFFFF, rand() & 0xFFFF);

    return GString(buffer);
}

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
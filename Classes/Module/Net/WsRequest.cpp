#include "WsRequest.h"

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
  lReq->SetRequestID(GenerateUUID());
  return lReq;
}
#pragma once
#include "IRequest.h"

class WsRequest : public IRequest
{
  public: 
  static WsRequest *Create();
  static WsRequest *Create(const GString &pUrl);
  static WsRequest *Create(const GString &pUrl, ReqCallback pSuccess);
  
  void Send() override;

};
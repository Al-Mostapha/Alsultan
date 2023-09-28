#pragma once
#include "IRequest.h"

class WsRequest : public IRequest
{
  public: 
  static WsRequest *Create();
  void Send() override;
};
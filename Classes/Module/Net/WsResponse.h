#pragma once
#include "IResponse.h"

class WSResponse : public IResponse
{
  
  public:
  static WSResponse *Create(const GString &pMsg);
  void FromJson(const XJson &pJson);
  void FromWsMsg();
  void Exec() override;
};
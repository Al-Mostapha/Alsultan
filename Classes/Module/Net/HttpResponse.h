#pragma once
#include "IResponse.h"
#include "network/HttpClient.h"



class HttpResponse : public IResponse
{
  cocos2d::network::HttpResponse *_Response = nullptr;
  public: 
  static HttpResponse *Create(cocos2d::network::HttpResponse *_Response);
  void FromJson(const XJson &pJson);
  void Exec() override;

};

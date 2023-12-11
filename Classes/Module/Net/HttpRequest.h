#pragma once
#include "IRequest.h"
#include "network/HttpClient.h"

class HttpRequest : public IRequest
{
  cocos2d::network::HttpRequest *_Request = nullptr;
  public: 
  static HttpRequest *Create();
  static HttpRequest *Create(const GString &pUrl);
  static HttpRequest *Create(const GString &pUrl, ReqCallback pSuccess);
  
  void Send() override;
  public:
    void SetUrl(const GString &pUrl) override;
  private:
    void SetHttpMethod();
    void SetHttpCallBack();


};
#pragma once
#include "Base/BaseTypeDef.h"
#include "Net.Enum.h"
#include "Base/Containers/HashMap.h"

USING_NS_CC;

class IResponse ;
class IRequest : public Ref{
  private:
  GString _Url = "";
  GHashMap<GString, GString> _Params;
  ERequestMethod _Method = ERequestMethod::Get;
  ERequestContentType _ContentType = ERequestContentType::Json;
  ERequestState _State = ERequestState::None;
  ERequestError _Error = ERequestError::None;
  ERequestType _Type = ERequestType::Http;
  GMap<ERequestHeader, GString> _Headers;
  GString _Token = "";
  std::function<void(IResponse *, IRequest *)> _OnComplete = nullptr;
  std::function<void(ERequestError, GString)> _OnError = nullptr;
  std::function<void(IResponse *, IRequest *)> _OnSuccess = nullptr;
  std::function<void(IRequest *)> _BeforeSend = nullptr;
  GString _RequestID = "";
  GTime _TimeStamp;
  
  public:
  IRequest() {}
  virtual ~IRequest() {}
  virtual void SetUrl(GString p_Url) { _Url = p_Url; }
  virtual void SetParams(GHashMap<GString, GString> p_Params) { _Params = p_Params; }
  virtual void SetMethod(ERequestMethod p_Method) { _Method = p_Method; }
  virtual void SetContentType(ERequestContentType p_ContentType) { _ContentType = p_ContentType; }
  virtual void SetState(ERequestState p_State) { _State = p_State; }
  virtual void SetError(ERequestError p_Error) { _Error = p_Error; }
  virtual void SetType(ERequestType p_Type) { _Type = p_Type; }
  virtual void SetHeaders(GMap<ERequestHeader, GString> p_Headers) { _Headers = p_Headers; }
  virtual void SetToken(GString p_Token) { _Token = p_Token; }
  virtual void SetOnComplete(std::function<void(IResponse *, IRequest *)> p_OnComplete) { _OnComplete = p_OnComplete; }
  virtual void SetOnError(std::function<void(ERequestError, GString)> p_OnError) { _OnError = p_OnError; }
  virtual void SetOnSuccess(std::function<void(IResponse *, IRequest *)> p_OnSuccess) { _OnSuccess = p_OnSuccess; }
  virtual void SetBeforeSend(std::function<void(IRequest *)> p_BeforeSend) { _BeforeSend = p_BeforeSend; }

  GString GetRequestID() { return _RequestID; }
  void SetRequestID(const GString &pID) { _RequestID = pID; }

  virtual void Send() = 0;

  Ref* autorelease()
  {
      CCASSERT(false, "HttpResponse is used between network thread and ui thread therefore, autorelease is forbidden here");
      return nullptr;
  }
};




#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XMap.h"
#include "Base/Type/XEngine.h"
#include "Net.Enum.h"
#include "Base/Containers/HashMap.h"
#include "Base/Type/XJson.h"
#include "Base/Type/XFunction.h"


class IResponse ;

typedef GFunc<void(IResponse *, class IRequest *)> ReqCallback;



class IRequest : public Ref{
  public:
  GString _Url = "";
  GHashMap<GString, GString> _Params;
  GString _Data = "";
  ERequestMethod _Method = ERequestMethod::Get;
  ERequestContentType _ContentType = ERequestContentType::Json;
  ERequestState _State = ERequestState::None;
  ERequestError _Error = ERequestError::None;
  ERequestType _Type = ERequestType::Http;
  GMap<ERequestHeader, GString> _Headers;
  GString _Token = "";
  ReqCallback _OnComplete = nullptr;
  std::function<void(ERequestError, GString)> _OnError = nullptr;
  ReqCallback _OnSuccess = nullptr;
  std::function<void(IRequest *)> _BeforeSend = nullptr;
  GString _RequestID = "";
  GTime _TimeStamp;
  
  public:
  IRequest() {}
  virtual ~IRequest() {}
  virtual void SetUrl(const GString &p_Url) { _Url = p_Url; }
  virtual void SetParams(GHashMap<GString, GString> p_Params) { _Params = p_Params; }
  virtual void SetMethod(ERequestMethod p_Method) { _Method = p_Method; }
  virtual void SetContentType(ERequestContentType p_ContentType) { _ContentType = p_ContentType; }
  virtual void SetState(ERequestState p_State) { _State = p_State; }
  virtual void SetError(ERequestError p_Error) { _Error = p_Error; }
  virtual void SetType(ERequestType p_Type) { _Type = p_Type; }
  virtual void SetHeaders(GMap<ERequestHeader, GString> p_Headers) { _Headers = p_Headers; }
  virtual void SetToken(GString p_Token) { _Token = p_Token; }
  virtual void SetOnComplete(ReqCallback p_OnComplete) { _OnComplete = p_OnComplete; }
  virtual void SetOnError(std::function<void(ERequestError, GString)> p_OnError) { _OnError = p_OnError; }
  virtual void SetOnSuccess(ReqCallback p_OnSuccess) { _OnSuccess = p_OnSuccess; }
  virtual void Done(ReqCallback p_OnSuccess) { _OnSuccess = p_OnSuccess; }
  virtual void SetBeforeSend(std::function<void(IRequest *)>  p_BeforeSend) { _BeforeSend = p_BeforeSend; }

  GString GetRequestID() { return _RequestID; }
  void SetRequestID(const GString &pID) { _RequestID = pID; }
  
  static GString GenerateUUID() {
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
    

  virtual void Send() = 0;

  Ref* autorelease()
  {
      CCASSERT(false, "HttpResponse is used between network thread and ui thread therefore, autorelease is forbidden here");
      return nullptr;
  }
};




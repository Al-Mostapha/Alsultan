#pragma once
#include "Base/BaseTypeDef.h"
#include "Net.Enum.h"
#include "Base/Json.h"

USING_NS_CC;

class IResponse : public Ref{
  public:
  GString _Url = "";
  GString _Data = "";
  GString _Error = "";
  ERequestState _State = ERequestState::None;
  ERequestError _ErrorType = ERequestError::None;
  ERequestType _Type = ERequestType::Http;
  bool _IsJson = true;
  GJson *_Json = nullptr;

  Ref* autorelease()
  {
      CCASSERT(false, "HttpResponse is used between network thread and ui thread therefore, autorelease is forbidden here");
      return nullptr;
  }
};
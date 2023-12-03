#pragma once
#include "Base/BaseTypeDef.h"
#include "Net.Enum.h"
#include "Base/Type/XJson.h"
#include "Base/Type/XEngine.h"


class IResponse : public Ref{
  public:
  GString _Url = "";
  GString _Data = "";
  GString _Error = "";
  ERequestState _State = ERequestState::None;
  ERequestError _ErrorType = ERequestError::None;
  ERequestType _Type = ERequestType::Http;
  bool IsJson() { return true; }
  XJson _Json = nullptr;
  virtual void Exec() = 0;

  Ref* autorelease()
  {
      CCASSERT(false, "HttpResponse is used between network thread and ui thread therefore, autorelease is forbidden here");
      return nullptr;
  }
};
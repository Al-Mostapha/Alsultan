#pragma once
#include "Include/IncludeBase.h"
#include "Mail.Enum.h"

class MailManger
{
public:
  static MailManger *Get();
  int32 GetNewMailNum(EMailSetType = EMailSetType::None);
};
#include "Mail.Mgr.h"

MailManger *MailManger::Get()
{
  static MailManger *s_MailManger = new MailManger();
  return s_MailManger;
}

int32 MailManger::GetNewMailNum(EMailSetType)
{
  return 0;
}
#include "User.h"

UserModule *UserModule::Get()
{
  static auto l_Inst = new UserModule();
  return l_Inst;
}
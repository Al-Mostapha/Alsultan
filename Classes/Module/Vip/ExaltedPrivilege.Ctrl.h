#pragma once
#include "ExaltedPrivilege.Enum.h"
class ExaltedPrivilegeCtrl{
  public: 
  static ExaltedPrivilegeCtrl *Get();
  bool CheckPrivilege(EExaltedPrivilege p_Privilege = EExaltedPrivilege::None);
};


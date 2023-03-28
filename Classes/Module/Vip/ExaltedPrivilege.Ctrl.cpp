#include "ExaltedPrivilege.Ctrl.h"

ExaltedPrivilegeCtrl* ExaltedPrivilegeCtrl::Get(){
  static ExaltedPrivilegeCtrl* l_Instance = new  ExaltedPrivilegeCtrl();
  return l_Instance;
}

bool ExaltedPrivilegeCtrl::CheckPrivilege(EExaltedPrivilege p_Privilege){
  return true;
}


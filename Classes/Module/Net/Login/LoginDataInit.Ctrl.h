#pragma once

class LoginDataInitCtrl{
  static LoginDataInitCtrl *Get(){
    static auto l_Inst = new LoginDataInitCtrl();
  }
  void GetLoginDataInitRsp();
};
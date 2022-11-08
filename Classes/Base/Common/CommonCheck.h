#pragma once

namespace GBase{
  struct CommonCheck
  {
    static CommonCheck *Get(){
      static auto l_Instance = new CommonCheck();
      return l_Instance;
    }
    bool ScreenShoot = false;
  };
  
}
#pragma once

class CityBuildFunction{
  bool m_IsFirstLogin;
public:
  static CityBuildFunction *Get(){
    static CityBuildFunction *s_CityBuildFunction = nullptr;
    if(s_CityBuildFunction == nullptr){
      s_CityBuildFunction = new CityBuildFunction();
    }
    return s_CityBuildFunction;
  }
  void SetIsFirstLogin(bool p_IsFirstLogin){
    m_IsFirstLogin = false;
  }
};
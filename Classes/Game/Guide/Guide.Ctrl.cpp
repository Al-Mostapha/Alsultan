#include "Guide.Ctrl.h"

GuideCtrl *GuideCtrl::Get(){
  static GuideCtrl *s_pInstance = nullptr;
  if (s_pInstance == nullptr)
  {
    s_pInstance = new GuideCtrl();
  }
  return s_pInstance;
}


RGuideStep *GuideCtrl::GetCurMainCityGuideStep(){
  return nullptr;
}

int32 GuideCtrl::GetCurForceGuideStep(){
  return 0;
}
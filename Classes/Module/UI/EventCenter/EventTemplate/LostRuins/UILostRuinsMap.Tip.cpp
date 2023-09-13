#include "UILostRuinsMap.Tip.h"

UILostRuinsMapTip* UILostRuinsMapTip::Create(){
  return Create("");
}

void UILostRuinsMapTip::InitActivityTime(GTime pLeftTime, GTime pTotalTime, ELosRuinsStatus pStatus, bool pIsSurveying){

}

void UILostRuinsMapTip::SetTimeEndCallBack(const std::function<void()> &pCallBack){}
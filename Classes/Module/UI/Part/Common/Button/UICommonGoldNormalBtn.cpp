#include "UICommonGoldNormalBtn.h"

UICommonGoldNormalBtn *UICommonGoldNormalBtn::Create(){
  auto l_Panel = Create("UiParts/Parts/Common/Button/commonGoldNormalBtn.csb");
  return l_Panel;
}

void UICommonGoldNormalBtn::Ctor(){

}

void UICommonGoldNormalBtn::InitData(RInitDataParm p_Parm, EShowType p_ShowType){}
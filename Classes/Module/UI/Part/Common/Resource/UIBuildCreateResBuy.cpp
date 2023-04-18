#include "UIBuildCreateResBuy.h"

UIBuildCreateResBuy *UIBuildCreateResBuy::Create(){
  auto l_Panel = Create("UiParts/Parts/Common/Resource/buildCreateResBuy.csb");
  return l_Panel;
}

void UIBuildCreateResBuy::Ctor(){

}

void UIBuildCreateResBuy::InitData(GVector<RTableResNeedBuy> p_CostRes, int32 p_ToGold, EResBuyViewType p_ResType){

}

void UIBuildCreateResBuy::InitWidget(){

}

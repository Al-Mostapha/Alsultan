#include "UISpeedUpReCallBuyPop.View.h"

UISpeedUpReCallBuyPopView *UISpeedUpReCallBuyPopView::Create()
{
  return Create("UiParts/Panel/Common/BuyRes/normalStyleBuyPopView.csb");
}

void UISpeedUpReCallBuyPopView::Ctor(){
  UITouchBaseView::Ctor();
}

void UISpeedUpReCallBuyPopView::InitData(EItemType pItemType, UISpeedUpReCallBuyPopView::RItemData pItemData){

}
#include "UIBag.View.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Item/Config/ShopLt.Ctrl.h"

UIBagView* UIBagView::Create(){
  return Create("UiParts/Panel/BagView/bagView.csb");
}

void UIBagView::Ctor(){
  UIBaseView::Ctor();
  _IsHideCurrentSceneView = true;
  _Title = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "CCS_commonFramTitle_bag");
  _Title->SetTitle(Translate::i18n("common_text_307"));
  _NodeTop = GBase::DGetChildByName<Node *>(this, "Top_Node");
  _NodeGold = GBase::DGetExtendChildFromCCSByName<UICommonGoldTop>(this, "CCS_commonGoldTop_gold");
  _BtnShop = GBase::DGetChildByName<ui::Button *>(this, "Button_shop");
  _BtnItems = GBase::DGetChildByName<ui::Button *>(this, "Button_bag");
  _BtnShop->setPressedActionEnabled(false);
  _BtnItems->setPressedActionEnabled(false);
  _BtnShop->setTitleText(Translate::i18n("common_text_270"));
  _BtnItems->setTitleText(Translate::i18n("common_text_309"));
  _BagItemsView = UIBagItemsView::Create();
  _BagItemsView->setPosition(GBase::DFPoint(0, 805, 0));
  _NodeTop->addChild(_BagItemsView, -1);
  // self.bagShopView = nil
  _BagItemsView->setVisible(true);
  _BtnItems->setTouchEnabled(false);
  _BtnItems->setBright(true);
  _BtnItems->setTitleColor(Color3B(255, 245, 176));
  _BtnShop->setTouchEnabled(true);
  _BtnShop->setBright(false);
  _BtnShop->setTitleColor(Color3B(144, 132, 97));
  _BtnItems->addTouchEventListener(CC_CALLBACK_2(UIBagView::OnBtnChangeClick, this));
  _BtnShop->addTouchEventListener(CC_CALLBACK_2(UIBagView::OnBtnChangeClick, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", CC_CALLBACK_1(UIBagView::UpdateDiscount, this));
  GBase::DAddMessage(this, "MESSAGE_ITEM_LIMITITEM_TIMEOUT_BACK", CC_CALLBACK_1(UIBagView::UpdateNewTag, this));
  UpdateDiscount(nullptr);
  _IconNew = GBase::DGetChildByName<Sprite *>(_BtnShop, "icon_new");
  auto l_IsNew = ShopLtCtrl::Get()->GetShopNewTag("all");
  _IconNew->setVisible(l_IsNew);
}

void UIBagView::UpdateDiscount(EventCustom *event){
  // local limitTimeDiscountShopAPI = include("limitTimeDiscountShopAPI")
  // local allianceDesRead = include("allianceDesRead")
  // local status, remainTime = limitTimeDiscountShopAPI:getActivityInfo()
  // if status and not allianceDesRead.getPlayerConquestWarMigration(false) and not allianceDesRead.getPlayerBattleGroundMigration(false) then
  //   self:showFireBorder()
  // else
  //   self:showFireBorder(true)
  // end
}

void UIBagView::UpdateNewTag(EventCustom *event){

}


void UIBagView::OnBtnChangeClick(Ref *pSender, ui::Widget::TouchEventType type){

}
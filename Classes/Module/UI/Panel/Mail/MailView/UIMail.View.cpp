#include "UIMail.View.h"
#include "UIMailScroll.View.h"
#include "Base/Common/Common.Teml.h"

UIMailView* UIMailView::Create(){
  return Create("UiParts/MainUi/Mail/mailView.csb");
}

void UIMailView::Ctor(){
  UIBaseView::Ctor();
  // self.title = SoraDGetExtendChildFromCCSByName(self, "Top_CCS_commonFramTitle_mail")
  _Title = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "Top_CCS_commonFramTitle_mail");
  // self.title:setTitle(i18n("mail_text_25"))
  _Title->SetTitle(Translate::i18n("mail_text_25"));
  // self.scrollView = SoraDGetExtendChildFromCCSByName(self, "CCS_mailScrollView_node", true)
  _ScrollView = GBase::DGetExtendChildFromCCSByName<UIMailScrollView>(this, "CCS_mailScrollView_node", true);
  // self.touchPanel = SoraDGetChildByName(self, "Size_TouchPanel")
  _TouchPanel = GBase::DGetChildByName<ui::Layout *>(this, "Size_TouchPanel");
  // self.touchPanel:setSwallowTouches(false)
  _TouchPanel->setSwallowTouches(false);
  // self.touchPanel:addTouchEventListener(handler(self, self.onTouchPanel))
  _TouchPanel->addTouchEventListener(CC_CALLBACK_2(UIMailView::OnTouchPanel, this));
  // self.emptyTipNode = SoraDGetChildByName(self, "Center_EmptyTip")
  _EmptyTipNode = GBase::DGetChildByName<Node *>(this, "Center_EmptyTip");
  // self.text_empty_tip = SoraDGetChildByName(self.emptyTipNode, "Center_text_empty_tip")
  _TextEmptyTip = GBase::DGetChildByName<ui::Text *>(_EmptyTipNode, "Center_text_empty_tip");
  // self.text_empty_tip:setString(i18n("common_text_1800"))
  _TextEmptyTip->setString(Translate::i18n("common_text_1800"));
  // self.scrollTab = SoraDGetChildByName(self, "Top_ScrollView_Tab")
  _ScrollTab = GBase::DGetChildByName<ui::ScrollView *>(this, "Top_ScrollView_Tab");
  // self.nodeTabs[1] = SoraDGetChildByName(self.scrollTab, "Node_TabSingle")
  _NodeTabs.push_back(GBase::DGetChildByName<Node *>(_ScrollTab, "Node_TabSingle"));
  // self.battleMailType = 0
  _BattleMailType = EBattelMailType::None;
  // self.dropDownBox = SoraDGetExtendChildFromCCSByName(self, "Top_CCS_commonDropDownBox", true)
  _DropDownBox = GBase::DGetExtendChildFromCCSByName<UICommonDropDownBox>(this, "Top_CCS_commonDropDownBox", true);
  // self.dropDownBox:setCustomColor(true)
  _DropDownBox->SetCustomColor(true);
  // self.dropDownBox:setIsCustom(true)
  _DropDownBox->SetIsCustom(true);
  // self.dropDownBox:setSelectSingleTarget("Image_select")
  _DropDownBox->SetSelectSingleTarget("Image_select");
  // self.dropDownBox:setTouchClose()
  _DropDownBox->SetTouchClose();
  // self.dropDownBox:setFlipArrow(0)
  _DropDownBox->SetFlipArrow(0);
  // self.dropDownBox:setChooseTag(self.battleMailType + 1)
  _DropDownBox->SetChooseTag(static_cast<int32>(_BattleMailType) + 1);
  // self.dropDownBox:setTouchClose()
  _DropDownBox->SetTouchClose();
  auto l_InitData = RCommonDropDownBoxInitData();
  l_InitData._MaxHeight = 300;
  l_InitData._ChildSize = Size(360, 47);
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_4"), 1});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_5"), 1 + static_cast<int32>(EBattelMailType::NORMAL)});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_6"), 1 + static_cast<int32>(EBattelMailType::ALLIANCE)});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_7"), 1 + static_cast<int32>(EBattelMailType::PALACE)});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_8"), 1 + static_cast<int32>(EBattelMailType::ESCORT)});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_9"), 1 + static_cast<int32>(EBattelMailType::PLAYING)});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_10"), 1 + static_cast<int32>(EBattelMailType::EXPLORE)});
  l_InitData._ChildData.push_back({Translate::i18n("mail_2_text_11"), 1 + static_cast<int32>(EBattelMailType::OTHER)});
  _DropDownBox->InitData(l_InitData);
  _DropDownBox->SetDefaultIndex(static_cast<int32>(_BattleMailType) + 1);
  _DropDownBox->AddEventListener(CC_CALLBACK_1(UIMailView::OnSelDropDownBox, this));
  _BtnDelet = GBase::DGetChildByName<ui::Button *>(this, "btn_del");
  _BtnDelet->setTitleText(Translate::i18n("mail_2_text_2"));
  // SoraDAutoSizeButtonText(self.btnDelet, cc.size(210, 70))
  _BtnReadAndReceive = GBase::DGetChildByName<ui::Button *>(this, "btn_onekey");
  _BtnReadAndReceive->setTitleText(Translate::i18n("mail_2_text_3"));
  // SoraDAutoSizeButtonText(self.btnReadAndReceive, cc.size(210, 70))
  _BtnDelet->addTouchEventListener(CC_CALLBACK_2(UIMailView::OnBottomMenuEvent, this));
  _BtnReadAndReceive->addTouchEventListener(CC_CALLBACK_2(UIMailView::OnBottomMenuEvent, this));
  CreateRedPointLayer();
}

void UIMailView::Show(){
  
}

void UIMailView::InitWithData(RMailInitData *p_InitData){
  
}
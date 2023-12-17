#include "UIMail.View.h"
#include "Base/Base.Geometry.h"
#include "UIMailScroll.View.h"
#include "Base/Common/Common.Teml.h"

UIMailView* UIMailView::Create(){
  return Create("UiParts/MainUi/Mail/mailView.csb");
}

void UIMailView::Ctor(){
  UIBasePanel::Ctor();
  _Title = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "Top_CCS_commonFramTitle_mail");
  _Title->SetTitle(Translate::i18n("mail_text_25"));
  _ScrollView = GBase::DGetExtendChildFromCCSByName<UIMailScrollView>(this, "CCS_mailScrollView_node", true);
  _TouchPanel = GBase::DGetChildByName<ui::Layout *>(this, "Size_TouchPanel");
  _TouchPanel->setSwallowTouches(false);
  _TouchPanel->addTouchEventListener(CC_CALLBACK_2(UIMailView::OnTouchPanel, this));
  _EmptyTipNode = GBase::DGetChildByName<Node *>(this, "Center_EmptyTip");
  _TextEmptyTip = GBase::DGetChildByName<ui::Text *>(_EmptyTipNode, "Center_text_empty_tip");
  _TextEmptyTip->setString(Translate::i18n("common_text_1800"));
  _ScrollTab = GBase::DGetChildByName<ui::ScrollView *>(this, "Top_ScrollView_Tab");
  _NodeTabs.push_back(GBase::DGetChildByName<Node *>(_ScrollTab, "Node_TabSingle"));
  _BattleMailType = EBattelMailType::None;
  _DropDownBox = GBase::DGetExtendChildFromCCSByName<UICommonDropDownBox>(this, "Top_CCS_commonDropDownBox", true);
  _DropDownBox->SetCustomColor(true);
  _DropDownBox->SetIsCustom(true);
  _DropDownBox->SetSelectSingleTarget("Image_select");
  _DropDownBox->SetTouchClose();
  _DropDownBox->SetFlipArrow(0);
  _DropDownBox->SetChooseTag(static_cast<int32>(_BattleMailType) + 1);
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
  GBase::DAutoSizeButtonText(_BtnDelet, Size(210, 70));
  _BtnReadAndReceive = GBase::DGetChildByName<ui::Button *>(this, "btn_onekey");
  _BtnReadAndReceive->setTitleText(Translate::i18n("mail_2_text_3"));
  GBase::DAutoSizeButtonText(_BtnReadAndReceive, Size(210, 70));
  _BtnDelet->addTouchEventListener(CC_CALLBACK_2(UIMailView::OnBottomMenuEvent, this));
  _BtnReadAndReceive->addTouchEventListener(CC_CALLBACK_2(UIMailView::OnBottomMenuEvent, this));
  CreateRedPointLayer();
}

void UIMailView::CreateRedPointLayer(){
  
}

void UIMailView::InitWithData(RMailInitData *p_InitData){
  
}
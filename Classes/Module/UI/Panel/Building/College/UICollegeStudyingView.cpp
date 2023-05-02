#include "UICollegeStudyingView.h"
#include "Base/Common/Panel.Manger.h"
#include "Base/Common/Common.Teml.h"

UICollegeStudyingView *UICollegeStudyingView::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeStudyingView.csb");
  return l_Panel;
}

void UICollegeStudyingView::Ctor(){
  UIBasePanel::Ctor();
  _IsHideCurrentSceneView = true;
  _Type = EScienceType::Resource;
  _NodeTop = GBase::DGetChildByName<Node *>(this, "Top_Node");
  _NodeTitle = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "CCS_commonFramTitle_studying");
  _NodeTitle->setLocalZOrder(1);
  _SizeImageShadow = GBase::DGetChildByName<Node *>(this, "Size_Image_shadow");
  _SizeImageShadow->setContentSize(Size(640, GDisplay::Get()->height - 328));
  _ImageL = GBase::DGetChildByName<ui::ImageView *>(this, "Image_l");
  _ImageL->setContentSize(Size(320, GDisplay::Get()->height - 400));
  _ImageR = GBase::DGetChildByName<ui::ImageView *>(this, "Image_r");
  _ImageR->setContentSize(Size(320, GDisplay::Get()->height - 400));
  _SizeImageBase = GBase::DGetChildByName<Node *>(this, "Size_Image_base");
  _SizeImageBase->setPositionY(-GDisplay::Get()->height);
  _BtnCloseRight = GBase::DGetChildByName<ui::Button *>(this, "Button_close_right");
  if(_BtnCloseRight){
    _BtnCloseRight->setLocalZOrder(2);
    _BtnCloseRight->addTouchEventListener([this](Ref *target, ui::Widget::TouchEventType event){
      if(event == ui::Widget::TouchEventType::ENDED){
        GBase::PlaySound();
        GPanelManger::Get()->DRemoveAllPanelFromManager();
      }
    });
  }
  _Scroll = nullptr;
}

void UICollegeStudyingView::InitData(EScienceType p_Type){
  _Type = p_Type;
  auto l_Scroll = "";
  GString l_Title = "";
  if(_Type == EScienceType::Military){
    l_Scroll = "collegeWarScrollView";
    l_Title = Translate::i18n("common_text_045");
  } else if(_Type == EScienceType::CityDevelop){
    l_Scroll = "collegeDevelopScrollView";
    l_Title = Translate::i18n("common_text_331");
  } else if(_Type == EScienceType::Anchor){
    l_Scroll = "collegeDefScrollView";
    l_Title = Translate::i18n("common_text_332");
  } else if(_Type == EScienceType::Resource){
    l_Scroll = "collegeResScrollView";
    l_Title = Translate::i18n("common_text_123");
  } else if(_Type == EScienceType::Special){
    l_Scroll = "collegeSpecialScrollView";
    l_Title = Translate::i18n("common_text_1962");
  } else if(_Type == EScienceType::Soldier){
    l_Scroll = "collegeSoldierScrollView";
    l_Title = Translate::i18n("common_text_3772");
  } else if(_Type == EScienceType::Leader){
    l_Scroll = "collegeCommanderScrollView";
    l_Title = Translate::i18n("common_text_4055");
  } else if(_Type == EScienceType::Hero){
    l_Scroll = "collegeHeroScrollView";
    l_Title = Translate::i18n("common_name_01");
  } else if(_Type == EScienceType::AdvancedMilitary){
    l_Scroll = "collegeAdvancedMilitaryScrollView";
    l_Title = Translate::i18n("common_name_02");
  }
  _Scroll = UICollegeScrollView::Create(l_Scroll);
  _Scroll->InitData(_Type);
  _Scroll->setPosition({0, 880});
  _NodeTop->addChild(_Scroll, 0);
  _NodeTitle->SetTitle(l_Title);
}

void UICollegeStudyingView::JumpToTechnologyByID(EScience p_ScienceID){
  if(_Scroll){
    _Scroll->JumpToTechnologyByID(p_ScienceID);
  }
}
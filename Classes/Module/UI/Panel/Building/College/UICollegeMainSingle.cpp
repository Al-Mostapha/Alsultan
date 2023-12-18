#include "UICollegeMainSingle.h"
#include "Base/Base.Const.h"
#include "UICollegeStudyingView.h"
#include "Module/Science/Science.Read.h"
#include "Module/City/City.Ctrl.h"
#include "Base/Common/Common.Func.h"
#include "Base/Common/Common.Teml.h"

UICollegeMainSingle *UICollegeMainSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeMainSingle.csb");
  return l_Panel;
}

void UICollegeMainSingle::Ctor(){
  UIBasePanel::Ctor();
  _Type               = EScienceType::Resource;
  _BtnStudy           = GBase::DGetChildByName<ui::Button*>(this, "Button_study");
  _SpriteIcon         = GBase::DGetChildByName<Sprite*>(this, "Sprite_icon");
  _ImgGear            = GBase::DGetChildByName<ui::ImageView*>(this, "Image_gear");
  _LabelName          = GBase::DGetChildByName<ui::Text*>(this, "Text_name");
  _ImageTechBg        = GBase::DGetChildByName<ui::ImageView*>(this, "Image_techBg");
  _NodeStudyingBottom = GBase::DGetChildByName<Node*>(this, "Node_studying_bottom");
  _NodeStudyingTop    = GBase::DGetChildByName<Node*>(this, "Node_studying_top");
  _SpriteLock         = GBase::DGetChildByName<Sprite*>(this, "spriteLock");
  _SpriteLock->setVisible(false);
  _BtnStudy->addTouchEventListener(CC_CALLBACK_2(UICollegeMainSingle::BtnClickCallBack, this));
  SetEffectVisible(false);
}

void UICollegeMainSingle::SetScale(float p_Scale){
  _Scale = p_Scale;
  _BtnStudy->setScale(_Scale);
  _SpriteIcon->setScale(_Scale);
  _ImgGear->setScale(_Scale);
  _ImageTechBg->setScale(_Scale);
  _LabelName->setScale(_Scale);
  _NodeStudyingTop->setScale(_Scale);
  _NodeStudyingBottom->setScale(_Scale);
  _SpriteLock->setScale(_Scale);
}

void UICollegeMainSingle::SetEffectVisible(bool p_IsVisible){
  _NodeStudyingBottom->setVisible(p_IsVisible);
  _NodeStudyingTop->setVisible(p_IsVisible);
  if(p_IsVisible){
    GBase::DResetEffectNode(_NodeStudyingBottom);
    GBase::DResetEffectNode(_NodeStudyingTop);
  }else{
    GBase::DStopEffectNode(_NodeStudyingBottom);
    GBase::DStopEffectNode(_NodeStudyingTop);
  }
}

void UICollegeMainSingle::RunFadeInAct(float p_PosX, float p_PosY){
  auto l_IsCalled = false;
  GVector<Node*> l_TargetArray = {
    _SpriteIcon,
    _ImgGear,
    _LabelName,
    _SpriteLock,
    _ImageTechBg
  };

  for(auto iii = 0; iii < l_TargetArray.size(); iii++){
    auto l_Node = l_TargetArray.at(iii);
    l_Node->setOpacity(0);
    l_Node->setScale(0.7f);
    auto l_Action = Sequence::create(
      DelayTime::create(0.8166666666666667f),
      Spawn::create(
        ScaleTo::create(0.06666666666666667f, _Scale + 0.08f),
        FadeIn::create(0.06666666666666667f),
        CallFunc::create([&](){
          if(!l_IsCalled){
            this->runAction(MoveTo::create(0.06666666666666667f, Vec2(p_PosX, p_PosY)));
            l_IsCalled = true;
          }
        }),
        nullptr
      ),
      ScaleTo::create(0.2833333333333333f, _Scale),
      nullptr
    );
    l_Node->runAction(l_Action);
  }
}

void UICollegeMainSingle::InitData(EScienceType p_Science){
  _Type = p_Science;
  auto l_Data = ScienceRead::Get()->GetTypeTitleIcon(_Type);
  if(l_Data._Valid){
    _SpriteIcon->setSpriteFrame(l_Data._Icon);
    _LabelName->setString(l_Data._Title);
    _ImageTechBg->loadTexture(l_Data._Base, TextureResType::PLIST);
  }
  Unlock();
}

bool UICollegeMainSingle::Unlock(){
  auto l_Ret = true;
  if(_Type == EScienceType::Soldier){
    if(CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::Castle)->_Info.buildingLvl < GBase::Const::Get()->CastleLvl16){
      _SpriteLock->setVisible(true);
      GBase::DCreateGraySprite(_SpriteIcon);
      l_Ret = false;
    }
  }else if(_Type == EScienceType::Leader){
    if(CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Institute) < GBase::Const::Get()->CastleLvl40){
      _SpriteLock->setVisible(true);
      GBase::DCreateGraySprite(_SpriteIcon);
      l_Ret = false;
    }
  }else if(_Type == EScienceType::Hero){
    if(CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Castle) < GBase::Const::Get()->CastleLvl40){
      _SpriteLock->setVisible(true);
      GBase::DCreateGraySprite(_SpriteIcon);
      l_Ret = false;
    }
  }else if(_Type == EScienceType::AdvancedMilitary){
    if(CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Institute) < GBase::Const::Get()->CastleLvl40){
      _SpriteLock->setVisible(true);
      GBase::DCreateGraySprite(_SpriteIcon);
      l_Ret = false;
    }
  }else{
    GBase::DNormalSprite(_SpriteIcon);
  }
  return l_Ret;
}

void UICollegeMainSingle::InitScroll(ui::ScrollView *p_Scroll){
  _PScroll = p_Scroll;
}

void UICollegeMainSingle::BtnClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  static bool l_IsMoved = false;
  auto l_Btn = dynamic_cast<ui::Button *>(p_Sender);
  if(p_Type == ui::Widget::TouchEventType::ENDED){
    if(_PScroll && l_IsMoved){
      l_IsMoved = false;
      return;
    }
    if(_PScroll && !GBase::DIsNodeVisibleOnScroll(l_Btn, _PScroll)){
      return;
    }
    GBase::PlaySound();
    //   local collegeType = gModuleMgr.sharedMgr("mildGuideManager"):getVariate("collegeMainSingle", "collegeType")
    //   if collegeType and collegeType ~= self.type then
    //     gModuleMgr.sharedMgr("mildGuideManager"):clean()
    //   end
    if(Unlock()){
      auto l_Panel = UICollegeStudyingView::Create();
      l_Panel->InitData(_Type);
      l_Panel->Show();
    } else if(_Type == EScienceType::Soldier){
      GBase::DShowMsgTip(Translate::i18n("common_text_3296", {
        {"build", Translate::i18n("common_text_3129")}
      }));
    } else if(_Type == EScienceType::Leader){
      GBase::DShowMsgTip(Translate::i18n("common_text_4039"));
    } else if(_Type == EScienceType::Hero){
      GBase::DShowMsgTip(Translate::i18n("common_text_3868", {
        {"lv", std::to_string(GBase::Const::Get()->CastleLvl7)}
      }));
    } else if(_Type == EScienceType::AdvancedMilitary){
      GBase::DShowMsgTip(Translate::i18n("common_text_4039"));
    }
  } else if(p_Type == ui::Widget::TouchEventType::MOVED){
    auto l_TouchMovePoint = l_Btn->getTouchMovePosition();
    auto l_Distance = l_TouchMovePoint.distance(l_Btn->getTouchBeganPosition());
    if(l_Distance > TOUCH_MOVED_ERROR_VALUE)
      l_IsMoved = true;
  }else if(p_Type == ui::Widget::TouchEventType::CANCELED){
    l_IsMoved = false;
  }
  
}

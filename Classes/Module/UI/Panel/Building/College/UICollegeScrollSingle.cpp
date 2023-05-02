#include "UICollegeScrollSingle.h"
#include "UICollegeWaitCancelView.h"
#include "UICollegeDetailsView.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Science/Science.Read.h"
#include "Module/Science/Science.Ctrl.h"
#include "Module/Task/Task.Ctrl.h"
#include "Base/Common/Common.Func.h"
#include "Module/Task/WaitQueue.Ctrl.h"

UICollegeScrollSingle *UICollegeScrollSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/View/College/collegeScrollSingle.csb");
  return l_Panel;
}

void UICollegeScrollSingle::Ctor(){
  UIBasePanel::Ctor();
  _BtnBg = GBase::DGetChildByName<ui::Button *>(this, "Button_touch");
  _BtnBg->addTouchEventListener(CC_CALLBACK_2(UICollegeScrollSingle::BtnClickCallBack, this));
  _BtnBg->setSwallowTouches(false);
  _ImageTechBg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_techBg");
  _ImageIcon = GBase::DGetChildByName<ui::ImageView *>(this, "Image_icon");
  _ImageIcon->ignoreContentAdaptWithSize(true);
  _NodeName = GBase::DGetChildByName<Node *>(this, "Node_name");
  _LabelName = GBase::DGetChildByName<ui::Text *>(this, "Text_name");
  _NodeLv = GBase::DGetChildByName<Node *>(this, "Node_lv");
  _LabelLv = GBase::DGetChildByName<ui::Text *>(this, "Text_lv");
  _NodeEffectBg = GBase::DGetChildByName<Node *>(this, "Node_effect_bg");
  _NodeEffectFg = GBase::DGetChildByName<Node *>(this, "Node_effect_fg");
  // self.Text_time = SoraDGetChildByName(self, "Text_time")
  // self.Text_time = SoraDCreateTimerLabel(self, self.Text_time)
  _TextTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node *>(this, "Text_time"));
  _TextTime->setVisible(false);
  RunEffect(false);

}

void UICollegeScrollSingle::SetScroll(ui::ScrollView *p_Scroll){
  _Scroll = p_Scroll;
}

void UICollegeScrollSingle::InitData(EScience p_TechId, EScienceType p_TechType){
  _Tid = p_TechId;
  if(p_TechType == EScienceType::None)
    _Type = ScienceRead::Get()->GetType(_Tid);
  else 
    _Type = p_TechType;
  if(_Tid !=  EScience::None && _Type != EScienceType::None){
    UpdateView(nullptr);
  }
};

void UICollegeScrollSingle::HideName(){
  _NodeName->setVisible(false);
}

void UICollegeScrollSingle::HideNameLv(){
  _NodeLv->setVisible(false);
  _NodeName->setVisible(false);
}

void UICollegeScrollSingle::UpdateView(EventCustom *p_Event){
  RunEffect(false);
  if(_Tid == EScience::None || _Type == EScienceType::None)
    return;
  _TableSingleData = ScienceCtrl::Get()->GetTechDataByID(_Tid, _Type);
  _TableSingleDetails = ScienceCtrl::Get()->GetTechDetails(_Tid, _TableSingleData._CurrentLvl);
  _ImageIcon->loadTexture(ScienceRead::Get()->GetIcon(_Tid), ui::Widget::TextureResType::PLIST);
  _ImageTechBg->loadTexture(ScienceRead::Get()->GetBg(_Tid), ui::Widget::TextureResType::PLIST);
  _LabelName->setString(ScienceRead::Get()->GetName(_Tid));
  _LabelLv->setString(StringUtils::format("%d/%d",_TableSingleData._CurrentLvl,_TableSingleData._MaxLvl));
  SetIconStateGrey(_TableSingleData._IsOpened);
  if(_TableSingleData._IsOpened){
    UpdateOtherUI();
  }
}

void UICollegeScrollSingle::SetTimeVisble(bool p_Visible){
  _TextTime->setVisible(p_Visible);
}

void UICollegeScrollSingle::UpdateOtherUI(){
  auto l_LableColor = Color3B(150, 120, 60);
  _TextTime->setVisible(true);
  if(_TableSingleDetails._CurrentLvl >= _TableSingleData._MaxLvl){
    l_LableColor = GDisplay::Get()->COLOR_GREEN;
  }else if(_TableSingleDetails._UpgradeIngTechnology.size() > 2){
    RunEffect(true);
    auto l_Q = TaskCtrl::Get()->QueryQueue(ETask::TechnologyUpgradeQ);
    if(l_Q && _TextTime->isVisible())
      _TextTime->BeginTime(l_Q->GetRemainTime());
  } else if(!CanStudy()){
    l_LableColor = GDisplay::Get()->COLOR_RED;
  }
  if(_TableSingleDetails._UpgradeIngTechnology.size() == 0)
      _TextTime->setVisible(false);
  _LabelName->setColor(l_LableColor);
  _LabelLv->setColor(l_LableColor);
}

bool UICollegeScrollSingle::CanStudy(){
  if(_TableSingleDetails._Builds.size() > 0){
    for(auto l_V :  _TableSingleDetails._Builds){
      if(l_V._IsContentmented && l_V._Bid != EBuilding::NEBULA_PALACE){
        if(_SpriteLock == nullptr){
          _SpriteLock = GDisplay::Get()->NewSprite("frame_techtree_lock_01.png");
          _SpriteLock->setPosition(-50, -30);
          addChild(_SpriteLock);
          GBase::DFTarget(_SpriteLock);
        }
        _SpriteLock->setVisible(true);
        return false;
      }
    }
  }
  if(_TableSingleDetails._Resources.size() > 0){
    for(auto l_V :  _TableSingleDetails._Resources){
      if(!l_V._IsContentmented && !l_V._IsLuckyContentmented){
        return false;
      }
    }
  }

  return true;
}

void UICollegeScrollSingle::RunEffect(bool p_IsShow){
  _NodeEffectBg->setVisible(p_IsShow);
  _NodeEffectFg->setVisible(p_IsShow);

  if(p_IsShow){
    GBase::DResetEffectNode(_NodeEffectBg);
    GBase::DResetEffectNode(_NodeEffectFg);
  }else{
    GBase::DStopEffectNode(_NodeEffectBg);
    GBase::DStopEffectNode(_NodeEffectFg);
  }
}

void UICollegeScrollSingle::SetIconStateGrey(bool p_IsOpen){
  auto l_State = p_IsOpen ? ui::Scale9Sprite::State::NORMAL : ui::Scale9Sprite::State::GRAY;
  auto l_Color = p_IsOpen ? Color3B(150, 120, 60) : Color3B(145, 145, 145);
  dynamic_cast<ui::Scale9Sprite *>(_ImageIcon->getVirtualRenderer())->setState(l_State);
  dynamic_cast<ui::Scale9Sprite *>(_ImageTechBg->getVirtualRenderer())->setState(l_State);
  _LabelName->setColor(l_Color);
  _LabelLv->setColor(l_Color);
}

void UICollegeScrollSingle::BtnClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  auto l_Btn = dynamic_cast<ui::Button *>(p_Sender);
  if(p_Type == ui::Widget::TouchEventType::ENDED){
    if(!GBase::DIsNodeVisibleOnScroll(l_Btn, _Scroll)){
      return;
    }
    if(_SingleIsMoved){
      _SingleIsMoved = false;
      return;
    }
    GBase::PlaySound();
    if(WaitQueueCtrl::Get()->CheckIsWaiting(ETask::TechnologyUpgradeQ, _Tid)){
      auto l_Panel = UICollegeWaitCancelView::Create();
      l_Panel->InitData(_Tid);
      l_Panel->Show();
    }else{
      auto l_Panel = UICollegeDetailsView::Create();
      l_Panel->InitData(_Tid, _Type);
      l_Panel->Show();
    }
  } else if(p_Type == ui::Widget::TouchEventType::MOVED){
    auto l_TouchMovePoint = l_Btn->getTouchMovePosition();
    auto l_Distance = l_Btn->getTouchBeganPosition().getDistance(l_TouchMovePoint);
    if(l_Distance > TOUCH_MOVED_ERROR_VALUE)
      _SingleIsMoved = true;
  }  else if(p_Type == ui::Widget::TouchEventType::CANCELED){
    _SingleIsMoved = false;
  }
}


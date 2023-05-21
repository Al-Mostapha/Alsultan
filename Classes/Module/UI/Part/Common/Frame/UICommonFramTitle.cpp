#include "UICommonFramTitle.h"
#include "Global/Global.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Base.create.h"
#include "spine/spine-cocos2dx.h"

UICommonFramTitle *UICommonFramTitle::Create(){
  auto l_Panel = Create("UiParts/Parts/Common/Frame/commonFramTitle.csb");
  return l_Panel;
}

void UICommonFramTitle::Ctor(){
  UIBasePanel::Ctor();
  _Bg = GBase::DGetChildByName<Sprite *>(this, "Sprite_title");
  _Title = GBase::DGetChildByName<ui::Text *>(this, "Text_title");
  _BtnQuest = GBase::DGetChildByName<ui::Button *>(this, "btn_quest");
  _Title->setVisible(false);
  _BtnMyHelp = GBase::DGetChildByName<ui::Button *>(this, "Button_myHelp");
  _BtnMyHelp->setVisible(false);
  _NodeStyleBg = GBase::DGetChildByName<Node *>(this, "Node_style_bg");
  _Node6thLace = GBase::DGetChildByName<Node *>(this, "Node_6thLace");
  _Node6thLace->setVisible(false);
  InitStyle();
}

void UICommonFramTitle::InitStyle(){
  auto l_Style = GGlobal::Get()->MainUIStyle;
  if(l_Style == EMainUIStyle::None)
    l_Style = EMainUIStyle::QuickSand;
  GString l_Bg = "";
  if(l_Style == EMainUIStyle::Easter)
    l_Bg = "Node_fram_style_easter";
  else if(l_Style == EMainUIStyle::Halloween)
    l_Bg = "Node_fram_style_halloween";
  else if(l_Style == EMainUIStyle::Chritmas)
    l_Bg = "Node_fram_style_chritmas";
  else if(l_Style == EMainUIStyle::QuickSand)
    l_Bg = "Node_fram_style_ztsz";
  else if(l_Style == EMainUIStyle::RosNormal)
    l_Bg = "";
  if(l_Bg != ""){
    auto l_BgNode = GBase::DCreateAnimation(l_Bg.c_str(), nullptr, false).First;
    _NodeStyleBg->addChild(l_BgNode);
    if(l_Style == EMainUIStyle::Easter){
      auto l_SpineDingkuang1 = spine::SkeletonAnimation::createWithBinaryFile("spine/dingkuang01.skel", "spine/dingkuang01.atlas", 1);
      l_SpineDingkuang1->setAnimation(0, "animation", true);
      l_SpineDingkuang1->setPosition(Vec2(GBase::DFPosX(480.f, 0.f), -67));
      _Bg->addChild(l_SpineDingkuang1, 2);
      auto l_SpineDingkuang2 = spine::SkeletonAnimation::createWithBinaryFile("spine/dingkuang02.skel", "spine/dingkuang02.atlas", 1);
      l_SpineDingkuang2->setAnimation(0, "animation", true);
      l_SpineDingkuang2->setPosition(Vec2(GBase::DFPosX(400.f, 0.f), -67));
      _Bg->addChild(l_SpineDingkuang2, 2);
    }
  }
}

void UICommonFramTitle::SetTitle(const GString& p_Title){
  if(_Title){
    _Title->setVisible(true);
    _Title->setString(p_Title);
    if(_Title->getContentSize().width >= 460){
      _Title->setScale(460 / _Title->getContentSize().width);
    }
  }
}
#include "UIBuildingInfoSingle.h"
#include "Module/CityResource/Resource.Read.h"
UIBuildingInfoSingle *UIBuildingInfoSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/Common/buildInfoSingle.csb");
  return l_Panel;
}

void UIBuildingInfoSingle::Ctor(){
  UIBasePanel::Ctor();
  _ImgIcon = GBase::GetChildByName<ui::ImageView *>(this, "Image_icon");
  _LabelDes = GBase::GetChildByName<ui::Text *>(this, "Text_des");
  _LabelValue = GBase::GetChildByName<ui::Text *>(this, "Text_value");
  _LabelPlusValue = GBase::GetChildByName<ui::Text *>(this, "Text_plusValue");
  _BtnHelp = GBase::GetChildByName<ui::Button *>(this, "Button_help");
  // self.tableInfoSingleData = {}
  if(_BtnHelp)
    _BtnHelp->addTouchEventListener(CC_CALLBACK_2(UIBuildingInfoSingle::BtnHelpCallBack, this));
  _LabelPlusValue->setVisible(false);
  _LabelValue->setVisible(false);
  _BtnHelp->setVisible(false);
}

void UIBuildingInfoSingle::InitData(const RBuildingMoreInfoData &p_Data){
  _InfoData = p_Data;
  if(!_InfoData._Value.empty()){
    _LabelValue->setString(_InfoData._Value);
    _LabelValue->setVisible(true);
    _LabelValue->setContentSize({285, 45});
  }else{
    _LabelValue->setContentSize({480, 45});
  }
  if(_InfoData._MoreInfoType == 4){
    _ImgIcon->loadTexture(ResourceRead::Get()->GetIcon(_InfoData._Title.c_str()), TextureResType::PLIST);
    _LabelDes->setString(ResourceRead::Get()->GetName(_InfoData._Title.c_str()));
  }else{
    _LabelDes->setString(_InfoData._Title);
    _ImgIcon->loadTexture("icon_building_research.png", TextureResType::PLIST);
  }

  if(!_InfoData._PlusValue.empty()){
    if(GStringUtils::IsNumber(_InfoData._PlusValue)){
      auto l_IntPlusVal = GStringUtils::ToNumber(_InfoData._PlusValue);
      if(l_IntPlusVal >= 0){
        _LabelPlusValue->setString("+" + GStringUtils::FormatK(l_IntPlusVal));
        _LabelPlusValue->setColor(GDisplay::Get()->COLOR_GREEN);
      }else{
        _LabelPlusValue->setString(GStringUtils::FormatK(l_IntPlusVal));
        _LabelPlusValue->setColor(GDisplay::Get()->COLOR_RED);
      }
    }else{
      _LabelPlusValue->setString(_InfoData._PlusValue);
      _LabelPlusValue->setColor(GDisplay::Get()->COLOR_GREEN);
    }
    _LabelPlusValue->setVisible(true);
    _LabelPlusValue->setPositionX(_LabelValue->getPositionX() - GBase::DFSign(_LabelValue->getContentSize().width + 10));

  }

  if(_InfoData._InfoDesType == 1){
    _BtnHelp->setVisible(true);
  }

  if(GBase::DFIsRA()){
  if(!_InfoData._PlusValue.empty() && _InfoData._InfoDesType == 1){
    GBase::DAlignNodeArray({_BtnHelp, _LabelPlusValue, _LabelValue}, false, {15.f, 10.f});
  } else if(!_InfoData._PlusValue.empty()){
    GBase::DAlignNodeArrayOnLimitX({_LabelValue, _LabelPlusValue}, true, {10}, false, 0);
  }
  }else if(!_InfoData._PlusValue.empty() && _InfoData._InfoDesType == 1){
    GBase::DAlignNodeArray({_BtnHelp, _LabelPlusValue, _LabelValue}, true, {15, 10});
  }else if(!_InfoData._PlusValue.empty()){
    GBase::DAlignNodeArrayOnLimitX({_LabelValue, _LabelPlusValue}, false, {10}, true, 534);
  }
}

void UIBuildingInfoSingle::InitWidget(){

}

void UIBuildingInfoSingle::BtnHelpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  CCLOG("Help Btn Clicked");
}
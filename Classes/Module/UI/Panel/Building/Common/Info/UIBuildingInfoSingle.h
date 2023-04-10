#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIBuildingInfoSingle : public UIBasePanel
{

  CREATE_FUNC(UIBuildingInfoSingle);
  CreateUIPanel(UIBuildingInfoSingle);
  CreateUICCSView(UIBuildingInfoSingle);
  
  ui::ImageView *_ImgIcon;
  ui::Text *_LabelDes;
  ui::Text *_LabelValue;
  ui::Text *_LabelPlusValue;
  ui::Button *_BtnHelp;
  
public: 

  static UIBuildingInfoSingle* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
  void BtnHelpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
};
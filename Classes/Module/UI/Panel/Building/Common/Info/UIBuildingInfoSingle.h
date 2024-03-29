#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Read.h"
#include "Module/Building/Building.Type.h"

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
  RBuildingMoreInfoData _InfoData;
  
public: 

  static UIBuildingInfoSingle* Create();
  void Ctor() override;
  void InitData(const RBuildingMoreInfoData &p_Data);
  void InitWidget();
  void BtnHelpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
};
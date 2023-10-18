#pragma once
#include "Module/UI/UIBasePanel.h"
#include "Include/IncludeBuildingBase.h"


class UIBuildCreateScrollSingle : public UIBasePanel
{

  CREATE_FUNC(UIBuildCreateScrollSingle);
  CreateUIPanel(UIBuildCreateScrollSingle);
  CreateUICCSView(UIBuildCreateScrollSingle);

private:

  ui::Text *m_LabelName;
  ui::ImageView *m_ImgLock;
  Sprite *m_ImgIcon;
  ui::Layout *m_ShowPanel;
  
public:
  static UIBuildCreateScrollSingle* Create();
  void Ctor() override;
  void initData(EBuilding p_BuildingType = EBuilding::None);

};
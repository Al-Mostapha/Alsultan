#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeBuildingBase.h"


class UIBuildCreateScrollSingle : public UIPanelBase
{

private:

  Label *m_LabelName;
  ui::ImageView *m_ImgLock;
  Sprite *m_ImgIcon;
  ui::Layout *m_ShowPanel;
  
public:
  UIBuildCreateScrollSingle();
  ~UIBuildCreateScrollSingle();
  void InitPanel() override;
  void initData(EBuilding p_BuildingType = EBuilding::None);
  CREATE_FUNC(UIBuildCreateScrollSingle);

};
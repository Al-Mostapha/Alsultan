#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeBuildingBase.h"


class UICreateBuildingPanel : public UIPanelBase
{

private:

  Label *m_LabelDes;
  Label *m_LabelCount;
  Label *m_LabelNeed;
  Label *m_LabelName;
  Node *m_NodeCenter;
  ui::ImageView *m_BackGround;
  ui::Button *m_BtnBuild;

  ui::Layout *m_NodeLeft;
  ui::Layout *m_NodeRight;
  ui::Layout *m_NodeTop;
  ui::Layout *m_NodeBottom;
  class UIWheelScrollView *m_SelectWheel;
  GVector<TBuildingInfoUnit> m_BuildableList;
  int m_CurrentIndex = 1;
  TBuildingInfoUnit m_CurrentBuilding;

  
public:
  UICreateBuildingPanel();
  ~UICreateBuildingPanel();
  void initPanel() override;
  void setBuildingTypeAndData(EBuildingType p_BuildingType = EBuildingType::None, int32 p_BuildingIndex = 0);
  void createWheelScrollView();
  void wheelScrollBack(const TBuildingInfoUnit& p_BuildingInfoUnit, size_t p_Index);
  void updateView();
  CREATE_FUNC(UICreateBuildingPanel);

};



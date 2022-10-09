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
  GVector<RBuildingSpecs> m_BuildableList;
  int m_CurrentIndex = 1;
  RBuildingSpecs m_CurrentBuilding;
  RCostBuildingUpgrade m_CostBuildingUpgrade;

  
public:
  UICreateBuildingPanel();
  ~UICreateBuildingPanel();
  void InitPanel() override;
  void SetBuildingTypeAndData(EBuilding p_BuildingType = EBuilding::None, int32 p_BuildingIndex = 0);
  void CreateWheelScrollView();
  void WheelScrollBack(const RBuildingSpecs& p_BuildingInfoUnit, size_t p_Index);
  void UpdateView();
  void SelectWheelByBuildingType(EBuilding p_BuildingType);
  void ClickEffect(Node *p_Target);
  void CreateWheelAction();
  CREATE_FUNC(UICreateBuildingPanel);

};



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
  ui::Layout *m_SelectWheel;

  
public:
  UICreateBuildingPanel();
  ~UICreateBuildingPanel();
  void initPanel() override;
  void setBuildingTypeAndData(EBuildingType p_BuildingType = EBuildingType::CBType_None, int32 p_BuildingIndex = 0);
  void createWheelScrollView();
  CREATE_FUNC(UICreateBuildingPanel);

};



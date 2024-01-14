#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Type.h"


class UIBuildCreatePanel : public UIBasePanel
{

  CREATE_FUNC(UIBuildCreatePanel);
  CreateUIPanel(UIBuildCreatePanel);
  CreateUICCSView(UIBuildCreatePanel);

private:

  ui::Text *m_LabelDes;
  ui::Text *m_LabelCount;
  ui::Text *m_LabelNeed;
  ui::Text *m_LabelName;
  Node *m_NodeCenter;
  ui::ImageView *m_BackGround;
  ui::Button *m_BtnBuild;

  ui::Layout *m_NodeLeft;
  ui::Layout *m_NodeRight;
  ui::Layout *m_NodeTop;
  ui::Layout *m_NodeBottom;
  class UIWheelScrollView *_SelectWheel;
  GVector<RBuildingSpecs> _BuildableList;
  int _CurrentIndex = 1;
  RBuildingSpecs _CurrentBuilding;
  RCostBuildingUpgrade _CostBuildingUpgrade;
  EBuildingIndex _BuildingIndex = EBuildingIndex::None;
  EBuildingPlace _BuildingType = EBuildingPlace::None;

  
public:
  static UIBuildCreatePanel* Create();
  void Ctor() override;
  void SetBuildingTypeAndData(EBuildingPlace pType, EBuildingIndex pIndex = EBuildingIndex::None);
  void CreateWheelScrollView();
  void WheelScrollBack(const RBuildingSpecs& p_BuildingInfoUnit, size_t p_Index);
  void UpdateView();
  void SelectWheelByBuildingType(EBuilding p_BuildingType);
  void ClickEffect(Node *p_Target);
  void CreateWheelAction();
  void CreateButtonCallFunc(Ref *pSender, ui::Widget::TouchEventType pType);
};



#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICreateBuildingPanel : public UIPanelBase
{

private:

  cocos2d::ui::Widget *m_LableDes;
  cocos2d::ui::Widget *m_LabelCount;
  cocos2d::ui::Widget *m_LabelNeed;
  cocos2d::ui::Widget *m_LabelName;
  cocos2d::ui::Widget *m_NodeCenter;
  cocos2d::ui::Widget *m_BackGround;
  
public:
  UICreateBuildingPanel();
  ~UICreateBuildingPanel();
  void initPanel() override;

  CREATE_FUNC(UICreateBuildingPanel);

};



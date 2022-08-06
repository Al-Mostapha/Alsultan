#include "Include/IncludeEngine.h"
#include "Include/IncludeUiBase.h"

class UIPanelBase : public UIElment
{
protected:
  cocos2d::ui::Layout *m_Panel;
public: 
  virtual void initPanel() = 0;
};
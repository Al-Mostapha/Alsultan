#include "Include/IncludeEngine.h"
#include "Module/UI/UIElment.h"

class UIPanelBase : public UIElment
{
protected:
  cocos2d::ui::Layout *m_Panel;
public: 
  virtual void initPanel(){};
   // implement the "static create()" method manually
  CREATE_FUNC(UIPanelBase);
};
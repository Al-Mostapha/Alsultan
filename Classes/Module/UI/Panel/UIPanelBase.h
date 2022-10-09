#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeUiBase.h"

class UIPanelBase : public UIElment
{
protected:
  cocos2d::ui::Layout *m_Panel;
  GString m_ViewName = "";
public: 
  virtual void InitPanel() = 0;
};
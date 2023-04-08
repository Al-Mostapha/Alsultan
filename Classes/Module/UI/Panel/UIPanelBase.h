#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeUiBase.h"

class UIPanelBase : public UIElment
{
protected:
  Node *_Panel;
  GString m_ViewName = "";
public: 
  virtual void InitPanel() = 0;
  virtual void Show() {};
  virtual GString GetViewName() {return m_ViewName;}
};
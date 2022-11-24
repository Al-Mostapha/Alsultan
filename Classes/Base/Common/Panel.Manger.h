#pragma once
#include "Include/IncludeBase.h"


class UIBasePanel;
class GPanelManger
{
public:
  static GPanelManger *Get();
  UIBasePanel *DCurrentTopPanelFromManager(); 
  void DRemoveAllPanelFromManager();
  void DAddPanelToManager(UIBasePanel *p_Panel);
  void DRemovePanelFromManager(UIBasePanel *p_Panel);
  void DDeleteTopWindow();
};
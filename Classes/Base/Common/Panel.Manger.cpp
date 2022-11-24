#include "Panel.Manger.h"
#include "Module/UI/UIBasePanel.h"

GPanelManger *GPanelManger::Get()
{
  static GPanelManger *l_PanelManger = nullptr;
  if(!l_PanelManger)
    l_PanelManger = new GPanelManger();
  return l_PanelManger;
}

UIBasePanel *GPanelManger::DCurrentTopPanelFromManager(){
  return nullptr;
}

void GPanelManger::DRemoveAllPanelFromManager(){
}


void GPanelManger::DAddPanelToManager(UIBasePanel *p_Panel){
}

void GPanelManger::DRemovePanelFromManager(UIBasePanel *p_Panel){
}

void GPanelManger::DDeleteTopWindow(){
}
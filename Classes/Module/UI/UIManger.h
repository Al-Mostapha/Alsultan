#pragma once
#include "Include/IncludeBase.h"
#include "UIBaseView.h"

class UIManger{
public:
  static UIManger *Get();
  void CloseAllUI(){}
  bool IsShow(const char *p_ViewName){ return true;}
  void Close(const char *p_ViewName){}
  template<typename T>
  T *Show(const char *p_ViewName);
  UIBaseView *GetProxy(const char *p_ProxyName){ return nullptr;}
};

template<typename T>
T *UIManger::Show(const char *p_ViewName)
{
  fairygui::UIPackage::addPackage("UiParts/FGUI/soldiersCampView");
  // UIPackage::addPackage("UI/Basics");

  auto _view = fairygui::UIPackage::createObject("soldiersCampView", "soldiersCampView")->as<fairygui::GComponent>();
  CityScene::Get()->_GRootNormal->addChild(_view);
  // local requiredComponent
  // function uiManager:show(viewName, param)
  //   if not requiredComponent then
  //     requiredComponent = true
  //     self:initLanguage()
  //     packageManager:addPackage("baseFguiPanel")
  //   end
  //   print("uiManager:show", viewName)
  //   local panelData = self:getPanelData(viewName)
  //   if not panelData then
  //     print("\232\175\183\229\174\154\228\185\137panelConfig", viewName)
  //     return
  //   end
  //   proxy = self:getOrCreateProxy(viewName)
  //   if proxy:showPanel(param) then
  //   end
  //   return proxy
  // end
  return nullptr;
}
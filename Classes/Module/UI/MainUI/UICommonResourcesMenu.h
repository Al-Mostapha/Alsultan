#pragma once 
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/CityResource/Resource.Enum.h" 


class UICommonResourcesMenu : public UIBasePanel
{

private:
  CREATE_FUNC(UICommonResourcesMenu);
  CreateUIPanel(UICommonResourcesMenu);
  CreateUICCSView(UICommonResourcesMenu);
public:

  static UICommonResourcesMenu *Create();
  void Ctor() override;
  void RunAnimation();
  void HiddleMainUI(bool p_IsHiddle = false);
  Node *GetResTarget(EResource p_ResType){
    return nullptr;
  }
  void SetNeedScale(bool p_){}

  void UpdateResources(){

  }
};

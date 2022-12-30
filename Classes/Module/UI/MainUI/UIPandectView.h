#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Module/UI/UICCSView.h"


class UIPandectView : public UIBaseView
{

private:
  CREATE_FUNC(UIPandectView);
  CreateUIPanel(UIPandectView);
  CreateUICCSView(UIPandectView);
public:
  UIPandectView(){};
  ~UIPandectView(){};
  void InitPanel(){};
  void Show(){};
  static UIPandectView *Create() {
    //TODO: sET Real path here
    return Create("UiParts/Panel/World/WorldMap/worldResourceMap.csb");
  };
};



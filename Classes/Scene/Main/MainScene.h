#pragma once

#include "Base/BaseTypeDef.h"
#include "cocos/ui/UILayout.h"
#include "FairyGUI.h"

USING_NS_CC;

class MainScene : public Scene
{

  
  public:
    fairygui::GRoot *_GRootNormal;
    GString _Name = "MainScene";
    ui::Layout *_PanelView = nullptr;
    ui::Layout *PanelView(){return _PanelView;};
};
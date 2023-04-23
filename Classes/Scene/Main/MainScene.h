#pragma once

#include "Include/IncludeBase.h"
#include "FairyGUI.h"

class MainScene : public Scene
{

  
  public:
    fairygui::GRoot *_GRootNormal;

    ui::Layout *_PanelView = nullptr;
    ui::Layout *PanelView(){return _PanelView;};
};
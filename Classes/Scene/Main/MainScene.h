#pragma once
#include "Include/IncludeBase.h"

class MainScene : public Scene
{
  public:
    ui::Layout *_PanelView = nullptr;
    ui::Layout *PanelView(){return _PanelView;};
};
#pragma once
#include "Include/IncludeBase.h"

class MainScene : public Scene
{
  public:
    ui::Layout *n_PanelView = nullptr;
    ui::Layout *PanelView(){return n_PanelView;};
};
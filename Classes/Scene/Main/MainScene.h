#pragma once
#include "Include/IncludeBase.h"

class MainScene : public Scene
{
  public:
    ui::Layout *m_PanelView = nullptr;
    ui::Layout *PanelView(){return m_PanelView;};
};
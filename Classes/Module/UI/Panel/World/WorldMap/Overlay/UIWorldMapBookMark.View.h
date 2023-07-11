#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"



class UIWorldMapBookMarkView : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapBookMarkView);
  CreateUIPanel(UIWorldMapBookMarkView);
  CreateUICCSView(UIWorldMapBookMarkView);
public: 
  Vec2 _TilePoint;

  static UIWorldMapBookMarkView* Create();
  void Ctor() override;
};
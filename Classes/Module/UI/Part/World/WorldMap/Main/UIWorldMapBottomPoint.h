#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"



class UIWorldMapBottomPoint : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapBottomPoint);
  CreateUIPanel(UIWorldMapBottomPoint);
  CreateUICCSView(UIWorldMapBottomPoint);
public: 
  Vec2 _TilePoint;

  static UIWorldMapBottomPoint* Create();
  void Ctor() override;
};
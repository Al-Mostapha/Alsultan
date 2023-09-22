#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"

class IWorldMapInstance;

struct RResourceDetailViewInit{
  Vec2 _ResPos;
  int32 _ResourceType;
  IWorldMapInstance* _MapInstance;
};


class UIWorldResourceDetailView : public UITouchBaseView{
  CREATE_FUNC(UIWorldResourceDetailView);
  CreateUIPanel(UIWorldResourceDetailView);
  CreateUICCSView(UIWorldResourceDetailView);
public: 
  static UIWorldResourceDetailView* Create();
  void InitData(const RResourceDetailViewInit &pData);
};
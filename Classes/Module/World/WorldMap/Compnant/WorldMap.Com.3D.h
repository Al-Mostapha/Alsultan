#pragma once
#include "IWorldMap.Com.h"
#include "ui/CocosGUI.h"

class WorldMapCom3D : public IWorldMapComponent{
  ui::ImageView *_TopFog;
  ui::ImageView *_BottomFog;
  public:
  void Init() override;
  void OnMessageListener() override;
  void Ctor();
  void Toggle3D(EventCustom *p_Event);
};
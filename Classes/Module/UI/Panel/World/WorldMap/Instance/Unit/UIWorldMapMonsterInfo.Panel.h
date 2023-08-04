#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"

class IWorldMapInstance;
class WorldMapMonster;

class UIWorldMapMonsterInfoPanel : public UITouchBaseView
{

  CREATE_FUNC(UIWorldMapMonsterInfoPanel);
  CreateUIPanel(UIWorldMapMonsterInfoPanel);
  CreateUICCSView(UIWorldMapMonsterInfoPanel);

  
public: 
  static UIWorldMapMonsterInfoPanel* Create(IWorldMapInstance *pWorldMapInstance);
  void Ctor() override;
  void SetTilePoint(const Vec2 &pTilePoint);
  void InitData(WorldMapMonster *pWorldMapInstance);
  void UpateInfoPanel(int32 pMonsterClassID);
};
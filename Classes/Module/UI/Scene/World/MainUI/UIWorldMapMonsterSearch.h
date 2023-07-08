#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldMap/WorldMap.Type.h"



class UIWorldMapMonsterSearch : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapMonsterSearch);
  CreateUIPanel(UIWorldMapMonsterSearch);
  CreateUICCSView(UIWorldMapMonsterSearch);
public:

  static UIWorldMapMonsterSearch* Create();
  void Ctor() override;
};
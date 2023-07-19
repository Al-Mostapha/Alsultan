#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/World/WorldMap/WorldMap.Type.h"

class IWorldMapInstance;

class UIWorldMapEmojiSeal : public UITouchBaseView
{
  CREATE_FUNC(UIWorldMapEmojiSeal);
  CreateUIPanel(UIWorldMapEmojiSeal);
  CreateUICCSView(UIWorldMapEmojiSeal);
public: 
  struct OtherData{

  };
  static UIWorldMapEmojiSeal* Create();
  void InitData(IWorldMapInstance *pInstance, int32 pMoveLineId);
  void Ctor() override;
};
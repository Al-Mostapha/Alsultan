#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/World/WorldMap/WorldMap.Type.h"



class UIWorldMapTroopsDetailsView : public UITouchBaseView
{
  CREATE_FUNC(UIWorldMapTroopsDetailsView);
  CreateUIPanel(UIWorldMapTroopsDetailsView);
  CreateUICCSView(UIWorldMapTroopsDetailsView);
public: 
  struct OtherData{

  };
  static UIWorldMapTroopsDetailsView* Create();
  void InitData(GVector<RMoveLineArmyData> pArmyData, const GString &pLeagueName, GOpt<OtherData> pOtherData = {});
  void Ctor() override;
};
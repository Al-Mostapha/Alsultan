#include "UIWorldMapMonsterInfo.Panel.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapMonster.h"

UIWorldMapMonsterInfoPanel *UIWorldMapMonsterInfoPanel::Create(IWorldMapInstance *pWorldMapInstance)
{
  return Create("UiParts/Panel/World/WorldMap/Instance/Unit/worldMapMonsterInfoPanel.csb");
}

void UIWorldMapMonsterInfoPanel::Ctor(){

}

void UIWorldMapMonsterInfoPanel::SetTilePoint(const Vec2 &pTilePoint){

}


void UIWorldMapMonsterInfoPanel::InitData(WorldMapMonster *pWorldMapInstance){

}

void UIWorldMapMonsterInfoPanel::UpateInfoPanel(int32 pMonsterClassID){

}

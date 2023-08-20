#include "WorldMap.Com.CommandHallNpc.h"


void WorldMapComCommandHallNpc::Ctor(){
  IWorldMapComponent::Ctor();
}

void WorldMapComCommandHallNpc::Init(){
  // worldMapComCommandHallNpc.super.init(self)
  IWorldMapComponent::Init();
  // self.worldMapCell = self.target_.currentInMapViewCell
  // self.currentShowTilesArray = {}
  // self.curLod = nil
  // self.moveLine = nil
  // self:initCommandHallNpc()
  // self:initCommandHallNpcQueue()
}

void WorldMapComCommandHallNpc::OnMessageListener(){}
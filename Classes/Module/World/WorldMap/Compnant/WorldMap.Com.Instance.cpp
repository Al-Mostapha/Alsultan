#include "WorldMap.Com.Instance.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"

void WorldMapComInstance::Ctor(){
  
}

void WorldMapComInstance::Init()
{
  _LodPreview = false;
  _LodFocus = false;
  _Builder->Init(_Target->_MapViewCellArray);
  _LodView = EWorldLodDef::LOD1;
}

void WorldMapComInstance::OnMessageListener()
{
  // SoraDAddMessage(self, "MESSAGE_SERVER_WORLD_MAP_GET_RECT_DATA", self:getCheckLodFun(self.serverMessage_AddMapInstace))
  // SoraDAddMessage(self, "MESSAGE_SERVER_WORLD_MAP_INSTANCE_ADD", self:getCheckLodFun(self.serverMessage_AddMapInstace))
  // SoraDAddMessage(self, "MESSAGE_SERVER_WORLD_MAP_INSTANCE_REMOVE", handler(self, self.serverMessage_RemoveMapInstace))
  // SoraDAddMessage(self, "MESSAGE_SERVER_WORLD_MAP_INSTANCE_MODIFY", self:getCheckLodFunKeep(self.serverMessage_ModifyMapInstace))
  // SoraDAddMessage(self, "MESSAGE_WORLD_MAP_REMOVE_MAPINSTANCE", handler(self, self.removeMapInstance))
  // SoraDAddMessage(self, "MESSAGE_WORLD_MAP_TOGGLE_3D", handler(self, self.toggle3D))
  // local handlerChange = handler(self, self.updateRelationChange)
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_RELATION_DATA_CHANGE", handlerChange)
  // SoraDAddMessage(self, "MESSAGE_ALLIACNE_BE_KICKED", handlerChange)
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_QUIT_SUCCESS", handlerChange)
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_JOIN_SUCCESS", handlerChange)
  AddEventListener(WorldMapEvent::Get()->EVENT_UPDATE_INFO, CC_CALLBACK_1(WorldMapComInstance::UpdateInfo, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_UPDATE_PIECE_DEL, CC_CALLBACK_1(WorldMapComInstance::UpdateViewPieceIds, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_LOD_CHANGE, CC_CALLBACK_1(WorldMapComInstance::UpdateLodChange, this));
}

void WorldMapComInstance::UpdateInfo(EventCustom *p_Event){}

void WorldMapComInstance::UpdateViewPieceIds(EventCustom *p_Event){}

void WorldMapComInstance::UpdateLodChange(EventCustom *p_Event){}
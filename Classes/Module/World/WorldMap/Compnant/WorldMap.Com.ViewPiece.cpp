#include "WorldMap.Com.ViewPiece.h"
#include "Module/World/WorldMap/WorldMap.Event.h"

void WorldMapComViewPiece::Ctor(){}

void WorldMapComViewPiece::Init(){
  IWorldMapComponent::Init();
}

void WorldMapComViewPiece::OnMessageListener(){
  AddEventListener(WorldMapEvent::Get()->EVENT_UPDATE_PIECE, CC_CALLBACK_1(WorldMapComViewPiece::SetViewPieceIds, this));
}

void WorldMapComViewPiece::ResetData(){
  _Lod = EWorldLodDef::None;
}

void WorldMapComViewPiece::SetViewPieceIds(EventCustom *pEvent){
  // local viewPieceIDs = event.viewPieceIDs
  // local curviewPieceIDs = {}
  // for kingdomId, v in pairs(viewPieceIDs) do
  //   if v then
  //     for _, id in pairs(v) do
  //       local strkey = kingdomId .. "-" .. tostring(id)
  //       curviewPieceIDs[strkey] = true
  //     end
  //   end
  // end
  // local curPieceIDS = self.viewPieceIDs
  // local delPieceIDS = {}
  // for k in pairs(curPieceIDS) do
  //   if not curviewPieceIDs[k] then
  //     delPieceIDS[k] = true
  //   end
  // end
  // self.viewPieceIDs = curviewPieceIDs
  // local lodChange = self.lod ~= event.lod
  // event_piece.delPieceIDS = delPieceIDS
  // event_piece.curPieceIDS = curviewPieceIDs
  // event_piece.lod = event.lod
  // event_piece.oldLod = self.lod
  // event_piece.lodChange = lodChange
  // if lodChange then
  //   self.lod = event.lod
  // end
  // self:dispatchEvent(event_piece)
}
#include "WorldMapEscort.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Activity/ActivityShow.Ctrl.h"
#include "Module/World/WorldMap/Floor/Escort/Escort.Ctrl.h"

void WorldMapEscort::Ctor() {
  _BgImage = GDisplay::Get()->NewSprite("Map_build_escort.png");
  addChild(_BgImage, -1);
  _InitData();
}

void WorldMapEscort::_InitData(){
  _IsSelfIn = false;
}

void WorldMapEscort::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.bgImage:setGroupID(groupID)
}

void WorldMapEscort::InitInstanceData(int32 pSiteClassID, void *pEscortData, int32 pObjData) {
  if(!pEscortData)
    return;
  auto escortData = (RWorldMapEscortInit *)pEscortData;
  UpdateData(*escortData);
}

void WorldMapEscort::UpdateData(const RWorldMapEscortInit &pInitData){
  _IsSelfIn = pInitData._IsSelfIn;
}

GString WorldMapEscort::GetFavoriteName(){
  return _PlayerName;
}

GTuple<UIBasePanel *, bool, Node*> WorldMapEscort::OnClickInstance(Node *pNode) {
  if(AllianceRead::Get()->GetPlayerConquestWarMigration())
    return {nullptr, false, nullptr};
  auto lCastleBCell = CityCtrl::Get()->GetBuildingCell(EBuilding::Castle, EBuildingIndex::None);
  auto lMinLv = EscortCtrl::Get()->GetEscortCityLevelMin();
  if(lCastleBCell->_Info.buildingLvl < lMinLv){
    GBase::DShowMsgTip("common_text_2483", "icon_escort_convey.png");
    return {nullptr, false, nullptr};
  }
  if(!ActivityShowCtrl::Get()->IsActivityOpen(EActivityTime::ESCORT)){
    GBase::DShowMsgTip("common_text_2486", "icon_escort_convey.png");
    return {nullptr, false, nullptr};
  }
  PlayClickSound();
  return OnShowWorldMapTip(pNode);
}

void WorldMapEscort::PlayClickSound() {
  GBase::PlaySound("worldmap", 5);
}

void WorldMapEscort::Req4Escort(){
  // local sendServer2Find = function(...)
  //   local gametop = gModuleMgr.getObject("gametop")
  //   local escortCtrl = gametop.playertop_:getModule("escortCtrl")
  //   escortCtrl:reqGetClosestBuild()
  //   SoraDShowLoading()
  // end
  // local local2Find = function(_fun)
  //   SoraDShowLoading()
  //   local gametop = gModuleMgr.getObject("gametop")
  //   local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  //   local _pos = cityCtrl:getCurCityPos()
  //   local worldObj = SoraDGetClosestInstanceInWorldMap(gMapObjTypeDef.mapObjTypeEscort, false, false, {point = _pos})
  //   if worldObj then
  //     local showTilePoint = worldObj:getTilePoint()
  //     SoraDGotoWorldMapPoint(showTilePoint, true)
  //     SoraDCloseLoading()
  //     SoraDRemoveAllPanelFromManager()
  //   else
  //     _fun()
  //   end
  // end
  // local gametop = gModuleMgr.getObject("gametop")
  // local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  // local castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
  // local escortCtrl = gametop.playertop_:getModule("escortCtrl")
  // local minLv = escortCtrl.dataMgr:getEscortCityLevelMin()
  // if minLv > tonumber(castleBcell.info.lv) then
  //   SoraDShowMsgTip(i18n("common_text_2483"), "#icon_escort_convey.png")
  // else
  //   local2Find(sendServer2Find)
  // end
}

GVector<RButtonTypeArray> WorldMapEscort::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  GVector<RButtonTypeArray> lButtonTypeArray;
  if(pIsSelfKingdom){
    lButtonTypeArray.push_back({EWorldMapTipButtonType::yayun});
    lButtonTypeArray.push_back({EWorldMapTipButtonType::tuijianlueduo});
    lButtonTypeArray.push_back({EWorldMapTipButtonType::junqing});
  }
  lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
  return lButtonTypeArray;
}

void WorldMapEscort::AddCacheBefore() {}
#include "City.Ctrl.h"
#include "City.Cell.h"
#include "Module/Building/Building.Cell.h"

CityCtrl *CityCtrl::Get(){
  static CityCtrl *l_Instance  = new CityCtrl();
  return l_Instance;
}

void CityCtrl::AddCity(Guid p_IdCity, CityCell *p_CityCell){
  m_CityList.emplace(p_IdCity, p_CityCell);
}

CityCell *CityCtrl::GetCurCity(){
  if(m_CityList.Contains(m_CID))
    return m_CityList[m_CID];
  return nullptr;
}

// THis function should return all buildings in the city
GHashMap<EBuildingIndex, BuildingCell> CityCtrl::GetBuildList(){
  auto l_CurrCity = GetCurCity();
  if(l_CurrCity)
    return l_CurrCity->BuildingList;
  return GHashMap<EBuildingIndex, BuildingCell>();
}

bool CityCtrl::GetCastleUpgradePopStatus(){
  return false;
}

BuildingCell *CityCtrl::GetBuildingCellByIndex(EBuildingIndex p_BuildingIndex){
  auto l_BuildList = GetBuildList();
  if(!l_BuildList.size())
    return nullptr;
  if(!l_BuildList.Contains(p_BuildingIndex))
    return nullptr;
  return &l_BuildList[p_BuildingIndex];
}

void CityCtrl::EnterGame(){
  // local queueCtrl = gametop.playertop_:getModule("queueCtrl")
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.free_build_queue), handler(self, self.buildQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.charge_build_queue), handler(self, self.buildQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.build_star_queue), handler(self, self.buildStarQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.build_star_queue_privilege), handler(self, self.buildStarQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.glorious_upgrade), handler(self, self.buildStatueBraveQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.magic_lamp_jinn_level), handler(self, self.buildMagicLampQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.magic_lamp_jinn_star), handler(self, self.buildMagicLampQueueCallback))
  // queueCtrl:addEventListener(tostring(gQueueTypeDef.magic_lamp_jinn_class), handler(self, self.buildMagicLampQueueCallback))
  // if not IsArClient then
  //   queueCtrl:addEventListener(tostring(gQueueTypeDef.build_mastery), handler(self, self.masteryQueueCallback))
  //   queueCtrl:addEventListener(tostring(gQueueTypeDef.construction_drawing), handler(self, self.drawingQueueCallback))
  // end
  // local backpackCtrl = gametop.playertop_:getModule("backpackCtrl")
  // backpackCtrl:addItemChangeEvent(300501, handler(self, self.toolCountChangeNotify))
  // backpackCtrl:addItemChangeEvent(300601, handler(self, self.toolCountChangeNotify))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_INIT_CITYDATA, handler(self, self.initCityDataRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_BUILD_BUILDING, handler(self, self.addBuildRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_BUILD_UPGRADE, handler(self, self.upgradeBuildRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_BUILD_STAR_UPGRADE, handler(self, self.upgradeBuildStarRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_BUILD_DEMOLISH, handler(self, self.demolishBuildRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_BUILD_EXCHANGE, handler(self, self.exchangePosRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_OPEN_GROUND, handler(self, self.openGroundRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_OPEN_CHARGE_QUEUE, handler(self, self.openChargeQueueRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_COLLECT_RES, handler(self, self.collectResRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_SPEED_UP_RES, handler(self, self.speedUpResRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_LEFT_CAN_GET_RES, handler(self, self.leftCanGetResRsp))
  // msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_SET_CITY_UPGRADE_POP_LV, handler(self, self.setUpgradePopLvRsp))
  // if not IsArClient then
  //   msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_UNLOCK_BUILD_MASTERY, handler(self, self.reqMasteryRsp))
  //   msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_UPGRADE_MASTERY_LEVEL, handler(self, self.reqMasteryRsp))
  //   msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_UPGRADE_MASTERY_BUFF, handler(self, self.reqMasteryRsp))
  //   msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_RESET_MASTERY_STAR, handler(self, self.reqMasteryRsp))
  //   msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_START_DRAWING, handler(self, self.reqMasteryDrawStartRsp))
  //   msgCtrl.register(gCmd.CMD_CITY_MODULE, gCmd.REQ_RECEIVE_DRAWING_REWARD, handler(self, self.reqMasteryDrawReceiveRsp))
  // end
  // msgCtrl.register(gCmd.CMD_KIPCHAKS_MODULE, gCmd.REQ_KIPCHAKS_INIT_DATA, handler(self, self.reqKipchaksInitRsp))
  // msgCtrl.register(gCmd.CMD_KIPCHAKS_MODULE, gCmd.REQ_KIPCHAKS_ATTACK, handler(self, self.reqKipchaksAttackRsp))
  // self:reqKipchaksInitReq()
  // self.resCalculate:EnterGame()
}

void CityCtrl::InitClientData(){
  // local _citycell = cityCell.new()
  // local cityinfo = data.cinfo
  // local buildlist = data.blist
  CityCell *l_CityCell = new CityCell();
  l_CityCell->AddBuilding(EBuildingIndex::ArrowTowerL, {{EBuilding::ArrowTower, EBuildingIndex::ArrowTowerL, 1}});
  l_CityCell->AddBuilding(EBuildingIndex::ArrowTowerR, {{EBuilding::ArrowTower, EBuildingIndex::ArrowTowerR, 1}});
  l_CityCell->AddBuilding(EBuildingIndex::WallGate, {{EBuilding::Wall, EBuildingIndex::WallGate, 1}});
  l_CityCell->AddBuilding(EBuildingIndex::WatchTower, {{EBuilding::WatchTower, EBuildingIndex::WatchTower, 1}});

  // for k, v in ipairs(buildlist) do
   //   local _buildcell = buildCell.new()
  //   v.binfo.starLv = v.binfo.starLv or 0
  //   _buildcell.info = v.binfo
  //   _citycell:addBuild(v.binfo.index, _buildcell)
  // end
  // _citycell.info = cityinfo
  // _citycell.demolishInfo = data.demolishInfo
  // _citycell.resList = data.reslist
  // _citycell.areaList = data.arealist
  // _citycell.dayMaxRes = data.dayMaxRes
  // _citycell.saferes = data.saferes
  // _citycell.mastery = data.mastery
  // _citycell:setDrawingData(data.drawingData)
  // self.upgradePopLv = data.upgradePopLv
  // local buildchargequeue = data.queue[tostring(gQueueTypeDef.charge_build_queue)]
  // if buildchargequeue then
  //   local starttime = buildchargequeue.starttime
  //   local totaltime = buildchargequeue.totaltime
  //   local nowtime = serviceFunctions.systemTime()
  //   local lasttime = nowtime - starttime
  //   local lefttime = totaltime - lasttime
  //   if lefttime <= 0 then
  //     lefttime = 0
  //   end
  //   _citycell:addBuildChargeQueue(gQueueTypeDef.charge_build_queue, starttime, totaltime, lefttime)
  // end
 
  // self:addCity(cityinfo.cid, _citycell)
  AddCity(1, l_CityCell);
  m_CID = 1;
  InitCrystalMine();
  RegisterNotify();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP");
}

void CityCtrl::InitCrystalMine(){
  // local bcell = self:getBuildCell(BUILDID.CRYSTAL_MINE, 0)
  // if bcell then
  //   if self:isCrystalMineUnlock() then
  //   else
  //     bcell.info.state = tostring(BUILD_STATE.LOCK)
  //   end
  //   local state = tonumber(bcell.info.state)
  //   if BUILD_STATE.LOCK == state then
  //     do
  //       local handle = ""
  //       local function buildListener(event)
  //         if self:isCrystalMineUnlock() then
  //           self:removeEventListener(handle)
  //           bcell.info.state = tostring(BUILD_STATE.NORMAL)
  //         end
  //       end
  //       local eventName = string.format(gEventName.event_city_build_level_up, BUILDID.CASTLE)
  //       handle = self:addEventListener(eventName, buildListener)
  //     end
  //   end
  // end
}
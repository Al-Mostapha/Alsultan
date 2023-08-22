#include "WorldMapAllianceResource.h"

void WorldMapAllianceResource::Ctor(){
  // self:_initUI()
  // self:_initData()
}

void WorldMapAllianceResource::_InitData(){
  // self.resourceClassID = nil
  // self.resourceType = nil
  // self.resourceLevel = 0
  // self.leagueID = 0
  // self.leagueName = nil
  // self.isSelfIn = false
  // self.leftTime = 0
  // self.buildPoint = 0
  // self.allianceResourceState = gMapObjStateTypeDef.gMapObjStateTypeFree
}

void WorldMapAllianceResource::_InitUI(){
  // self.occupyIcon = display.newSprite("#icon_map_res_me.png")
  // self.occupyIcon:setAnchorPoint(0.5, 0)
  // self.occupyIcon:setVisible(false)
  // self:addChild(self.occupyIcon, 2)
  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  // self.resourceImage = display.newSprite("#alliance_mineral_nongtian.png")
  // self:addChild(self.resourceImage, -1)
  // self.image_name = display.newSprite("#frame_map_07.png")
  // self.image_name:setAnchorPoint(cc.p(0.5, 0.5))
  // self.image_name:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 80))
  // self.image_name:addTo(self, 1)
  // self.image_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  // self.text_Name = SoraDCreateLabel({
  //   UILabelType = 2,
  //   text = "allianceResource",
  //   size = 20
  // })
  // self.text_Name:setAnchorPoint(cc.p(0.5, 0.5))
  // self.text_Name:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 80))
  // self.text_Name:addTo(self, 2)
  // self.text_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
}

void WorldMapAllianceResource::OnMessageListener() {}

void WorldMapAllianceResource::AddCacheBefore() {}

void WorldMapAllianceResource::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.resourceImage:setGroupID(groupID)
}

void WorldMapAllianceResource::InitInstanceData(int32 pResourceClassID, const RAllianceResourceInitData &pData){
  // self.resourceClassID = resourceClassID
  // self.resourceType = worldMapDefine.getAllianceResourceType(resourceClassID)
  // local imgName = worldMapDefine.getAllianceResourceImageName(resourceClassID)
  // self.resourceImage:setSpriteFrame(display.newSpriteFrame(imgName))
  // self:updateData(resourceData)
}

void WorldMapAllianceResource::UpdateData(const RAllianceResourceInitData &pData){
  // if not data then
  //   return
  // end
  // local selfLeagueID = allianceMgr:getOwnTeamID()
  // local resourceName = worldMapDefine.getAllianceResourceName(self.resourceClassID)
  // if data.level then
  //   self.resourceLevel = data.level
  //   self.instanceLevel = self.resourceLevel
  // end
  // self.leagueID = data.leagueID or 0
  // if self.leagueID == 0 then
  //   self.leagueName = nil
  // end
  // if data.leagueName then
  //   self.leagueName = data.leagueName
  // end
  // if data.isSelfIn ~= nil then
  //   self.isSelfIn = data.isSelfIn
  // else
  //   local isSelfIn = self:checkIsSelfIn()
  //   self.isSelfIn = isSelfIn
  // end
  // if data.status then
  //   self.allianceResourceState = data.status
  // end
  // if data.leftTime then
  //   self.leftTime = data.leftTime
  // end
  // self.superRes = data
  // self.occupyIcon:setVisible(self.isSelfIn)
  // if self.allianceResourceState == gMapObjStateTypeDef.gMapObjStateTypeWorking then
  //   self.text_Name:setString("(" .. self.leagueName .. ")" .. resourceName .. "(" .. i18n("common_text_2139") .. ")")
  // else
  //   self.text_Name:setString("(" .. self.leagueName .. ")" .. resourceName .. "(" .. i18n("common_text_830") .. ")")
  // end
  // if self.leagueID and self.leagueID > 0 then
  //   local nameColor = cc.c3b(0, 200, 200)
  //   if self.leagueID == selfLeagueID then
  //     nameColor = worldMapDefine.getLeagueManorLineColor(true)
  //   else
  //     local allianceRelationType = allianceRelationCtrl:getRelationTypeWith(self.leagueID)
  //     local selfSourceID = lordInfoCtrl:getMapSourceKid()
  //     local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
  //     local isMatchKingdom = conquestWarCtrl:isMatchKingdom(selfSourceID, self.kingdomID)
  //     if isMatchKingdom then
  //       allianceRelationType = gMapAllianceRelationType.ENEMY
  //     end
  //     nameColor = worldMapDefine.getLeagueManorLineColor(false, allianceRelationType)
  //   end
  //   self.text_Name:setColor(nameColor)
  // else
  //   self.text_Name:setColor(cc.c3b(200, 200, 200))
  // end
}

GString WorldMapAllianceResource::GetFavoriteName(){
  // local favoriteName
  // if self.leagueName then
  //   favoriteName = i18n("common_text_186", {
  //     abbr = self.leagueName,
  //     name = worldMapDefine.getAllianceResourceName(self.resourceClassID)
  //   })
  // else
  //   favoriteName = worldMapDefine.getAllianceResourceName(self.resourceClassID)
  // end
  // return favoriteName
}

void WorldMapAllianceResource::PlayClickSound() {
  // local sId = worldMapDefine.getAllianceResourceType(self.resourceClassID) + 1
  // if sId == 1 then
  //   SoraDPlaySound("worldmap", 6)
  // else
  //   SoraDPlaySound("innerbuildsound", 199 + sId)
  // end
}

int32 WorldMapAllianceResource::GetBuildPoint(){
  // local buildPoint = 0
  // if self.superRes then
  //   local surplusPoint = self.superRes.surplusPoint or 0
  //   if self.superRes.buildSpeed and 0 < self.superRes.buildSpeed and self.superRes.buildSpeedTime and 0 < self.superRes.buildSpeedTime then
  //     surplusPoint = self.superRes.surplusPoint - self.superRes.buildSpeed * (serviceFunctions.systemTime() - self.superRes.buildSpeedTime)
  //   end
  //   buildPoint = math.floor((self.superRes.totalPoint or 0) - surplusPoint)
  // end
  // return buildPoint
}

GVector<RButtonTypeArray> WorldMapAllianceResource::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){
  // local buttonTypeArray = {}
  // local selfLeagueID = not allianceMgr:getOwnTeamID() and 0
  // local isInWarKingdom = false
  // local gametop = gModuleMgr.getObject("gametop")
  // local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
  // if conquestWarCtrl:isPlayerConquestWarMigration() then
  //   isInWarKingdom = true
  // end
  // if selfLeagueID > 0 and selfLeagueID == self.leagueID then
  //   if self.isSelfIn then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_fanHui,
  //       isButtonEnabled = not isInWarKingdom
  //     })
  //   elseif self.allianceResourceState == gMapObjStateTypeDef.gMapObjStateTypeFree then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_caiji,
  //       isButtonEnabled = not isInWarKingdom
  //     })
  //   elseif self.allianceResourceState == gMapObjStateTypeDef.gMapObjStateTypeWorking then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_jianzao,
  //       isButtonEnabled = not isInWarKingdom
  //     })
  //   end
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_chakanxiangqing,
  //     isButtonEnabled = not isInWarKingdom
  //   })
  // else
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_shuoMing
  //   })
  // end
  // return buttonTypeArray
}

bool WorldMapAllianceResource::CheckIsSelfIn(){
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // if kingdomMapCtrl.kingdomMapCell:hasMyQueueToMapObj(self.instanceID, gMapMoveLineServerType.moveLineTypeSuperResource, gMapMoveLineStatusType.moveLineStatusTypeWorking) then
  //   return true
  // end
}
#include "WorldMapAncientTreasure.h"

void WorldMapAncientTreasure::Ctor() {
  // self:_initUI()
  // self:_initData()
}

void WorldMapAncientTreasure::_InitData(){
  // self.playerName = ""
  // self.playerID = 0
  // self.leagueID = 0
  // self.leagueName = nil
  // self.leagueAbbrName = nil
  // self.pos = nil
  // self.buildID = nil
  // self.buildType = 0
  // self.treasureState = gATBuildingStatus.AT_EXPLORE
  // self.emojiID = nil
}

void WorldMapAncientTreasure::_InitUI(){
  // self.image_LeagueFlag = display.newSprite(allianceDesRead.getFlagIcon(self.leagueFlag, true))
  // self.image_LeagueFlag:setScale(0.3)
  // self.image_LeagueFlag:setPosition(cc.p(self.centerPoint.x - 147, self.centerPoint.y - 10))
  // self.image_LeagueFlag:setVisible(false)
  // self.image_LeagueFlag:addTo(self, 1)
  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  // self.image_league_name = display.newSprite("#frame_map_07.png")
  // self.image_league_name:setAnchorPoint(cc.p(0.5, 0.5))
  // self.image_league_name:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 35))
  // self.image_league_name:setVisible(false)
  // self.image_league_name:addTo(self, 1)
  // self.image_league_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  // self.text_league_Name = SoraDCreateLabel({
  //   UILabelType = 2,
  //   text = "leagueName",
  //   size = 20
  // })
  // self.text_league_Name:setAnchorPoint(cc.p(0.5, 0.5))
  // self.text_league_Name:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 35))
  // self.text_league_Name:setVisible(false)
  // self.text_league_Name:addTo(self, 1)
  // self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  // self.image_player_name = display.newSprite("#frame_map_07.png")
  // self.image_player_name:setAnchorPoint(cc.p(0.5, 0.5))
  // self.image_player_name:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 80))
  // self.image_player_name:setVisible(false)
  // self.image_player_name:addTo(self, 1)
  // self.image_player_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  // self.text_player_Name = SoraDCreateLabel({
  //   UILabelType = 2,
  //   text = "playerName",
  //   size = 20
  // })
  // self.text_player_Name:setAnchorPoint(cc.p(0.5, 0.5))
  // self.text_player_Name:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 80))
  // self.text_player_Name:setVisible(false)
  // self.text_player_Name:addTo(self, 1)
  // self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  // self.treasureImg = display.newSprite("#Map_build_sgmk.png")
  // self:addChild(self.treasureImg, -1)
  // self.etNode = SoraDCreatAnimation("ancientTreasureEffect")
  // SoraDMixtureGLONEByParent(self.etNode)
  // self:addChild(self.etNode, 1)
}

void WorldMapAncientTreasure::OnMessageListener() {}

void WorldMapAncientTreasure::AddCacheBefore() {}

void WorldMapAncientTreasure::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.treasureImg:setGroupID(groupID)
}

void WorldMapAncientTreasure::InitInstanceData(const RAncientTreasureInitData &pData){
  // dump(treasureData, "treasureData=========")
  // if not treasureData then
  //   return
  // end
  // self.pos = self:getTilePoint()
  // if treasureData.buildID then
  //   self.buildID = treasureData.buildID
  // end
  // self:updateData(treasureData)
}

void WorldMapAncientTreasure::UpdateData(const RAncientTreasureInitData &pData){
  // dump(treasureData, "worldMapAncientTreasure1111", 5)
  // if not treasureData then
  //   return
  // end
  // if treasureData.playerID then
  //   self.playerID = treasureData.playerID
  // end
  // if treasureData.playerName then
  //   self.playerName = treasureData.playerName
  // end
  // local isOccupy = false
  // if treasureData.aid then
  //   if self.leagueID ~= 0 and self.leagueID ~= treasureData.aid then
  //     isOccupy = true
  //   end
  //   self.leagueID = treasureData.aid
  // end
  // if treasureData.leagueName then
  //   self.leagueName = treasureData.leagueName
  // end
  // if treasureData.leagueAbbrName then
  //   self.leagueAbbrName = treasureData.leagueAbbrName
  // end
  // if treasureData.buildType then
  //   self.buildType = treasureData.buildType
  // end
  // if treasureData.buildStatus then
  //   self.treasureState = treasureData.buildStatus
  // end
  // self:updateEmojiByData(treasureData)
  // self:updatePlayerInfo()
  // SoraDSendMessage({
  //   msg = "MESSAGE_SERVER_ANCIENT_TREASURE_UPDATE",
  //   instance = self,
  //   isOccupy = isOccupy
  // })
}

void WorldMapAncientTreasure::UpdatePlayerInfo(){
  // local selfLeagueID = allianceMgr:getOwnTeamID()
  // if self.leagueID and self.leagueID > 0 and self.playerID and 0 < self.playerID then
  //   if self.leagueID == selfLeagueID then
  //     local nameColor = worldMapDefine.getLeagueManorLineColor(true)
  //     self.text_league_Name:setColor(nameColor)
  //     self.text_player_Name:setColor(nameColor)
  //   else
  //     local allianceRelationCtrl = gametop.playertop_:getModule("allianceRelationCtrl")
  //     local allianceRelationType = allianceRelationCtrl:getRelationTypeWith(self.leagueID)
  //     local nameColor = worldMapDefine.getLeagueManorLineColor(false, allianceRelationType)
  //     self.text_league_Name:setColor(nameColor)
  //     self.text_player_Name:setColor(nameColor)
  //   end
  //   self.image_LeagueFlag:setVisible(true)
  //   self.image_league_name:setVisible(true)
  //   self.text_league_Name:setVisible(true)
  //   self.image_player_name:setVisible(true)
  //   self.text_player_Name:setVisible(true)
  //   if allianceDesRead.getFlagIcon(self.leagueFlag) then
  //     self.image_LeagueFlag:setSpriteFrame(allianceDesRead.getFlagIcon(self.leagueFlag))
  //   end
  //   self.text_league_Name:setString(self.leagueName)
  //   local textName = self.playerName
  //   if self.leagueID and self.leagueID > 0 and self.leagueAbbrName then
  //     textName = i18n("common_text_186", {
  //       abbr = self.leagueAbbrName,
  //       name = self.playerName
  //     })
  //   end
  //   self.text_player_Name:setString(textName)
  // else
  //   self.image_LeagueFlag:setVisible(false)
  //   self.image_league_name:setVisible(false)
  //   self.text_league_Name:setVisible(false)
  //   self.image_player_name:setVisible(false)
  //   self.text_player_Name:setVisible(false)
  // end
}

GString WorldMapAncientTreasure::GetFavoriteName(){
  // local favoriteName = i18n("AncienTreasure_buildname_01")
  // return favoriteName
}

void WorldMapAncientTreasure::PlayClickSound() {
  // SoraDPlaySound("worldmap", 5)
}

GVector<RButtonTypeArray> WorldMapAncientTreasure::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  // local buttonTypeArray = {}
  // local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  // local selfPlayerID = gametop.playertop_:getPlayerID()
  // local playerID = self.playerID or 0
  // local leagueID = self.leagueID or 0
  // print("playerID,selfPlayerID,leagueID,selfLeagueID,self.treasureState===", playerID, selfPlayerID, leagueID, selfLeagueID, self.treasureState)
  // if isSelfKindom then
  //   if selfLeagueID == 0 or SoraDGetCastleLv() < 6 then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_shuoMing
  //     })
  //     return buttonTypeArray
  //   end
  //   local allianceRelationType = SoraDGetCtrl("allianceRelationCtrl"):getRelationTypeWith(leagueID)
  //   if allianceRelationType == gMapAllianceRelationType.ALLY then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_shuoMing
  //     })
  //     return buttonTypeArray
  //   end
  //   if self.treasureState == gATBuildingStatus.AT_EXPLORE then
  //     if selfLeagueID > 0 and leagueID == selfLeagueID then
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_tanmingmibao
  //       })
  //     end
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_shuoMing
  //     })
  //   elseif self.treasureState == gATBuildingStatus.AT_MINNING then
  //     if selfLeagueID > 0 and self.leagueID == selfLeagueID or self.leagueID == 0 then
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_wajuexiangqing
  //       })
  //       local haveHall = cityCtrl:getBuildCell(BUILDID.HALL_OF_WAR, 0)
  //       if haveHall then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_zuduiwajue
  //         })
  //       end
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_wajue
  //       })
  //     else
  //       print("self.leagueID,selfLeagueID===", self.leagueID, selfLeagueID)
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_gongJi,
  //         extra = {
  //           dispatchType = worldMapDefine.worldMapTipButtonType_zhanLing
  //         }
  //       })
  //       if self.leagueID and 0 < self.leagueID then
  //         local towerLv = cityCtrl:getBuildMaxLv(BUILDID.WATCH_TOWER)
  //         if towerLv > 1 then
  //           table.insert(buttonTypeArray, {
  //             buttonType = worldMapDefine.worldMapTipButtonType_zhenCha
  //           })
  //         end
  //       end
  //       local haveHall = cityCtrl:getBuildCell(BUILDID.HALL_OF_WAR, 0)
  //       if haveHall then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_xuanZhan
  //         })
  //       end
  //     end
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_shuoMing
  //     })
  //   end
  // else
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_shuoMing
  //   })
  // end
  // return buttonTypeArray
}
#include "WorldMapBattlefieldSite.h"
#include "Module/Player/Player.Top.h"
#include "Module/Guild/Alliance.Mgr.h"

void WorldMapBattlefieldSite::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapBattlefieldSite::_InitData(){

}

void WorldMapBattlefieldSite::_InitUI(){
  _CampsiteImg = GDisplay::Get()->NewSprite("Map_build_campsite.png");
  addChild(_CampsiteImg, -1);
}

void WorldMapBattlefieldSite::OnMessageListener() {
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", CC_CALLBACK_1(WorldMapBattlefieldSite::UpdateAllianceCounter, this));
}
void WorldMapBattlefieldSite::UpdateAllianceCounter(EventCustom *pEvent){
  if(!pEvent)
    return;
  if(!pEvent->getUserData())
    return;
  auto lData = (GPair<EGreenPointNoticeType, int32>*)pEvent->getUserData();
  if(lData->First == EGreenPointNoticeType::COUNTER_SYS)
    UpdateAllianceCounterAtkEffect(nullptr);
}

void WorldMapBattlefieldSite::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.campsiteImg:setGroupID(groupID)
}

void WorldMapBattlefieldSite::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  if(!pObjData)
    return;
  auto lData = (RBattelFieldSiteInit*)pObjData;
  UpdateData(*lData);
}

void WorldMapBattlefieldSite::UpdateData(const RBattelFieldSiteInit &pSiteData){
  _PlayerName = pSiteData._PlayerName;
  _PlayerID = pSiteData._PlayerID;
  _CampsiteState = pSiteData._Status;
 _LeagueID = pSiteData._LeagueID;
  _LeagueName = pSiteData._LeagueName;
  UpdateFireEffect(_CampsiteState);
  UpdateEmojiByData(pSiteData._PlayerID, pSiteData._EmojiID);
  UpdateAllianceCounterAtkEffect(nullptr);
}

void WorldMapBattlefieldSite::AddCacheBefore() {}

GString WorldMapBattlefieldSite::GetFavoriteName(){
  auto lFavoriteName = _PlayerName;
  if(!_LeagueName.empty())
    lFavoriteName = 
      Translate::i18n("common_text_186", {
        {"abbr", _LeagueName}, 
        {"name", _PlayerName}
      });
  return lFavoriteName;
}

void WorldMapBattlefieldSite::PlayClickSound() {
  GBase::PlaySound("worldmap", 20);
}

GVector<RButtonTypeArray> WorldMapBattlefieldSite::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lPlayerID = _PlayerID;
  auto lLeagueID = _LeagueID;

  if(lPlayerID == lSelfPlayerID){
    lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui});
    lButtonTypeArray.push_back({EWorldMapTipButtonType::buDuiXiangqing});
    if(CanHasEmojiOperator()){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
    }
  } else if(pIsSelfKingdom){
    auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
    if(lSelfLeagueID > 0 && lSelfLeagueID == lLeagueID){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
    }else{
      //     local atlantis = {}
      //     do
      //       local isEnable = true
      //       local msgTipsKey
      //       if worldMapDefine.isRadianceKingdomID(self.kingdomID) then
      //         isEnable = false
      //         function msgTipsKey()
      //           local radianceWarUtil = include("radianceWarUtil")
      //           radianceWarUtil.showGuildToBuild(self:getTilePoint())
      //         end
      //       elseif worldMapDefine.isInAtlantis() then
      //         local atlantisWarUtil = include("atlantisWarUtil")
      //         atlantis = atlantisWarUtil.checkAreaState(self:getTilePoint())
      //         isEnable = atlantis.isCanZhanling
      //         msgTipsKey = atlantis.clickTips
      //       elseif worldMapDefine.isInNebula() then
      //         local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
      //         if nebulaActivityCtrl:getCurRound() <= 3 then
      //           isEnable = false
      //           msgTipsKey = i18n("nebula_war_text_0194")
      //         end
      //       end
      //       table.insert(buttonTypeArray, {
      //         buttonType = worldMapDefine.worldMapTipButtonType_gongJi,
      //         isButtonEnabled = isEnable,
      //         msgTipsKey = msgTipsKey
      //       })
      //     end
      //     local cityCtrl = gametop.playertop_:getModule("cityCtrl")
      //     local towerLv = cityCtrl:getBuildMaxLv(BUILDID.WATCH_TOWER)
      //     if towerLv > 1 then
      //       local isEnable = true
      //       local msgTipsKey
      //       if worldMapDefine.isInAtlantis() then
      //         isEnable = atlantis.isCanZhencha
      //         msgTipsKey = atlantis.zhenchaTips
      //       elseif worldMapDefine.isInNebula() then
      //         local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
      //         if nebulaActivityCtrl:getCurRound() <= 3 then
      //           isEnable = false
      //           msgTipsKey = i18n("nebula_war_text_0194")
      //         end
      //       end
      //       table.insert(buttonTypeArray, {
      //         buttonType = worldMapDefine.worldMapTipButtonType_zhenCha,
      //         isButtonEnabled = isEnable,
      //         msgTipsKey = msgTipsKey
      //       })
      //     end
      lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
    }
  } else {
    lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
  }
  return lButtonTypeArray;
}
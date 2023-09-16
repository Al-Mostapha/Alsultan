#include "WorldMapTreasure.h"
#include "Base/Functions/ServiceFunction.h"
#include "Base/Utils/XTransition.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"

void WorldMapTreasure::Ctor() {
  _TreasureState = EMapObjStateTypeDef::Free;
  _EmojiID = 0;
  _TreasureImg = GDisplay::Get()->NewSprite("Map_build_treasure.png");
  addChild(_TreasureImg, -1);

  _ImageTimeBg = GDisplay::Get()->NewSprite("title_main_build.png");
  _ImageTimeBg->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y - 30));
  addChild(_ImageTimeBg, 1);

  auto lSizeTimeBg = _ImageTimeBg->getContentSize();

  // self.text_StateTime = cc.ui.UILabel.new({
  //   UILabelType = 2,
  //   text = "00:00:00",
  //   size = 20
  // })
  // self.text_StateTime:setAnchorPoint(cc.p(0.5, 0.5))
  // self.text_StateTime:setPosition(cc.p(size_TimeBg.width / 2, size_TimeBg.height / 2))
  // self.text_StateTime:addTo(self.image_TimeBg, 1)
  // self.text_StateTime = SoraDCreateTimerLabel(self, self.text_StateTime)
  // self.text_StateTime:setTimeEndListener(function(...)
  // end)
  
  _WorkManImg = GDisplay::Get()->NewSprite("kuanggong_01.png");
  _WorkManImg->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y + 20));
  addChild(_WorkManImg, 1);
  auto lFrames = GDisplay::Get()->NewFrames("kuanggong_0%d.png", 1, 8);

  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.15);
  XTransition::Get()->PlayAnimationForever(_WorkManImg, lAnimation);
}

void WorldMapTreasure::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.treasureImg:setGroupID(groupID)
}

void WorldMapTreasure::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) {
  if(pObjData == nullptr) {
    return;
  }
  
  auto lTreasureData = (RUnitTreasureInit *)pObjData;
  _PlayerName = lTreasureData->_PlayerName;
  _PlayerID = lTreasureData->_PlayerID;
  UpdateData(*lTreasureData);
}

void WorldMapTreasure::UpdateData(const RUnitTreasureInit &pData){
  _LeagueID = pData._LeagueID;
  _LeagueName = pData._LeagueName;
  if(pData._DigEndTime > 0){
    _StateTime = pData._DigEndTime - GServiceFunction::Get()->SystemTime();
    if(_StateTime >= 0){
      _TextStateTime->setVisible(true);
      _TextStateTime->BeginTime(_StateTime);
    }else{
      _TextStateTime->setVisible(false);
    }
  }
  
  UpdateFireEffect(_TreasureState);
  UpdateEmojiByData(pData._PlayerID, pData._EmojiID);
}

GString WorldMapTreasure::GetFavoriteName(){
  auto lFavoriteName = _PlayerName;
  if(_LeagueName.length() > 0){
    lFavoriteName = Translate::i18n("common_text_186", 
    {
      {"abbr", _LeagueName},
      {"name", _PlayerName}
    });
  }
  return lFavoriteName;
}

void WorldMapTreasure::PlayClickSound() {
  GBase::PlaySound("worldmap", 5);
}

GVector<RButtonTypeArray> WorldMapTreasure::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  // local buttonTypeArray = {}
  // local gametop = gModuleMgr.getObject("gametop")
  // local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  // local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  // local selfPlayerID = gametop.playertop_:getPlayerID()
  // local playerID = self.playerID or 0
  // local leagueID = self.leagueID or 0
  // if playerID == selfPlayerID then
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_fanHui
  //   })
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_buDuiXiangqing
  //   })
  //   if self:canHasEmojiOperator(selfPlayerID) then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_biaoqingyinzhang
  //     })
  //   end
  // elseif isSelfKindom then
  //   if selfLeagueID > 0 and selfLeagueID == leagueID then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_yongHuXinxi
  //     })
  //   else
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_gongJi
  //     })
  //     local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  //     local towerLv = cityCtrl:getBuildMaxLv(BUILDID.WATCH_TOWER)
  //     if towerLv > 1 then
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_zhenCha
  //       })
  //     end
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_yongHuXinxi
  //     })
  //   end
  // else
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_yongHuXinxi
  //   })
  // end
  // return buttonTypeArray
}

void WorldMapTreasure::AddCacheBefore() {

}

#include "WorldMapStronghold.h"
#include "Base/Base.create.h"
#include "Base/Functions/ServiceFunction.h"
#include "Module/Guild/AllianceStrongholdMine.Read.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapTilesRolygon.h"

void WorldMapStronghold::Ctor() {
  _InitData();
  _InitUI();
}

void WorldMapStronghold::_InitData(){
  _ObjID = 0;
  _Status = EKingdomWarStatusType::close;
  // self.playerID = nil
  // self.playerName = ""
  _Size = 2;
  _Radioation = 4;
}

void WorldMapStronghold::_InitUI(){
  _ModelImage = GDisplay::Get()->NewSprite("alliance_mineral_nongtian.png");
  _ModelImage->setPosition(Vec2(-70, 30));
  addChild(_ModelImage, -1);
  _ImageNameBg = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageNameBg->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageNameBg->setPosition(_CenterPoint + Vec2(0, -60));
  addChild(_ImageNameBg, 1);
  // self.image_name_bg:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  GBase::RCreateLabelParm lParm;
  lParm._Text = "";
  lParm._FontSize = 20;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  
  _TextName = GBase::DCreateLabel(lParm);
  _TextName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextName->setPosition(_CenterPoint + Vec2(0, -62));
  addChild(_TextName, 1);
  // self.text_Name:setGroupID(worldMapDefine.GROU_ID.group_text)

  _ImageZlBg = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageZlBg->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageZlBg->setPosition(_CenterPoint + Vec2(0, -98));
  addChild(_ImageZlBg, 1);
  // self.image_zl_bg:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  _TextZl = GBase::DCreateLabel(lParm);
  _TextZl->setAnchorPoint(Vec2(0.5, 0.5));
  _TextZl->setPosition(_CenterPoint + Vec2(0, -101));
  addChild(_TextZl, 1);
  // self.text_zl:setGroupID(worldMapDefine.GROU_ID.group_text)
  
  _ImageLvBg = GDisplay::Get()->NewSprite("frame_rydt_lsxk_lv.png");
  _ImageLvBg->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageLvBg->setPosition(_CenterPoint + Vec2(-130, -83));
  addChild(_ImageLvBg, 1);
  // self.image_lv_bg:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  lParm._FontSize = 22;
  _TextLevel = GBase::DCreateLabel(lParm);
  _TextLevel->setAnchorPoint(Vec2(0.5, 0.5));
  _TextLevel->setPosition(_CenterPoint + Vec2(-130, -83));
  addChild(_TextLevel, 1);
  // self.text_level:setGroupID(worldMapDefine.GROU_ID.group_text)
  
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect();
  _ImageProtect->setScale(0.7);
  _ImageProtect->setPosition(_CenterPoint + Vec2(0, 70));
  addChild(_ImageProtect, 4);
  _ImagePtBg = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePtBg->setAnchorPoint(Vec2(0.5, 0.5));
  _ImagePtBg->setPosition(_CenterPoint + Vec2(0, -20));
  addChild(_ImagePtBg, 1);
  // self.image_pt_bg:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  // self.text_StateTime = cc.ui.UILabel.new({
  //   UILabelType = 2,
  //   text = "00:00:00",
  //   size = 20
  // })
  // self.text_StateTime:setAnchorPoint(cc.p(0.5, 0.5))
  // self.text_StateTime:setPosition(cc.p(self.centerPoint.x, self.centerPoint.y - 23))
  // self.text_StateTime:addTo(self, 1)
  // self.text_StateTime = SoraDCreateTimerLabel(self, self.text_StateTime)
  
  _ImagePicon = GDisplay::Get()->NewSprite("icon_ldjd_weikaiqi.png");
  _ImagePicon->setAnchorPoint(Vec2(0, 0.5));
  _ImagePicon->setPosition(_CenterPoint + Vec2(-80, -23));
  addChild(_ImagePicon, 1);

}

void WorldMapStronghold::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.modelImage:setGroupID(groupID)
}

void WorldMapStronghold::SetBuildSize(int32 pSize, int32 pRadioation){
  _Size = pSize;
  _Radioation = pRadioation;
}

void WorldMapStronghold::AddCacheBefore() {
  _ImageProtect->setVisible(false);
  _TextStateTime->RemoveTime();
}

void WorldMapStronghold::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  if(pObjData == nullptr) {
    return;
  }
  
  _ObjID = pClass;
  InitBuildInfo();
  UpdateData(*(RUnitStrongholdInit*)pObjData);
}

void WorldMapStronghold::InitBuildInfo(){
  auto lBuildInfo = AllianceStrongholdMineRead::Get()->GetGateClientCfg(_ObjID);
  if(lBuildInfo){
    _ModelImage->setSpriteFrame(lBuildInfo->_Image);
    SetHoldEffect(lBuildInfo->_Effects);
    _TextLevel->setString(std::to_string(AllianceStrongholdMineRead::Get()->GetGateLv(_ObjID)));
    _TextName->setString(lBuildInfo->_Name);
    _TextName->setColor(Color3B(255, 255, 255));
  }
}

void WorldMapStronghold::SetHoldEffect(int32 pEffect){
  if(_HoldEffect){
    auto lEffect = _HoldEffect->getUserData();
    if( *((int32 *)lEffect) == pEffect){
      return;
    }
    _HoldEffect->removeFromParent();
    _HoldEffect = nullptr;
  }

  auto lCsb = "";
  auto lOffset = Vec2(0, 0);
  if(pEffect == 1){
    lCsb = "Node_hold_et1.csb";
  } else if(pEffect == 3){
    lCsb = "Node_hold_et3.csb";
  } else if(pEffect == 4){
    lCsb = "Node_hold_et2.csb";
  }else{
    return;
  }

  static int32 lEffects;
  lEffects = pEffect;
  auto [lEtHold, _] = GBase::DCreateAnimation(lCsb);
  addChild(lEtHold);
  lEtHold->setPosition(lOffset + _ModelImage->getPosition());
  lEtHold->setUserData((void *)&lEffects);
  _HoldEffect = lEtHold;
}

int32 WorldMapStronghold::GetBuildClassID(){
  return _ObjID;
}

void WorldMapStronghold::UpdateData(const RUnitStrongholdInit &pData){
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL"/*,   
    //     relatedTilePoints = {
    //       self.tilePoint
    //     }*/
  );
  _Status = pData._Status;
  _WarStatus = _WarStatus;
  if(_WarStatusEndTime > 0){
    _WarStatusEndTime = pData._WarStatusEndTime;
    _TextStateTime->RemoveTime();
    _TextStateTime->SetTimeLast([this](GString pTimeS, GTime pTime){
      if(_WarStatus == EKingdomWarStatusType::rule){
        return Translate::i18n("alliance_stronghold_text_040", {{"var", pTimeS}});
      } else {
        return Translate::i18n("alliance_stronghold_text_042", {{"var", pTimeS}});;
      }
    });
    _TextStateTime->BeginTime(_WarStatusEndTime - GServiceFunction::Get()->SystemTime());
    _ImagePicon->setPositionX(_TextStateTime->getPositionX() - _TextStateTime->getContentSize().width / 2 - 20);
  }
  
  SetProtectTimeVisible(_WarStatusEndTime > 0 && _WarStatus != EKingdomWarStatusType::close);
  _Npc = pData._Npc;
  _Occupy = pData._Occupy;
  
  if(_Occupy){
    _PlayerID = _Occupy->_Uid;
    _PlayerName = _Occupy->_Name;
    _ColorID = _Occupy->_ColorID;
  }
  UpdatePlayerInfo();
  GBase::DSendMessage("MESSAGE_WORLD_MAP_UPDATE_INSTANCE"/*,  instance = self*/);
}

void WorldMapStronghold::SetProtectTimeVisible(bool pVisible){
  _ImagePtBg->setVisible(pVisible);
  _TextStateTime->setVisible(pVisible);
  _ImagePicon->setVisible(pVisible);

  auto lImage = "";
  auto lColor = Color3B(255, 255, 255);
  if(_WarStatus == EKingdomWarStatusType::close){
    lImage = "icon_ldjd_weikaiqi.png";
  } else if(_WarStatus == EKingdomWarStatusType::inWar){
    lImage = "icon_ldjd_kegongji_02.png";
    lColor = Color3B(230, 50, 50);
  } else if(_WarStatus == EKingdomWarStatusType::rule){
    lImage = "icon_ldjd_baohuzhong_02.png";
  }

  _ImagePicon->setSpriteFrame(lImage);
  _TextStateTime->setColor(lColor);
}

void WorldMapStronghold::UpdatePlayerInfo(){
  auto lNameColor = Color3B(255, 255, 255);
  _ImageProtect->setVisible(_WarStatus != EKingdomWarStatusType::inWar);
  _RolygonColor = lNameColor;
  if(_WarStatus == EKingdomWarStatusType::close){
    _TextZl->setString(Translate::i18n("alliance_stronghold_text_038"));
  }else if(_WarStatus == EKingdomWarStatusType::inWar){
    _TextZl->setString(Translate::i18n("alliance_stronghold_text_036"));
    if(_Occupy && _Occupy->_Aid > 0){
      _TextZl->setString(
        Translate::i18n(
          "alliance_stronghold_text_037", 
          {
            {"var", _Occupy->_Abbr}, 
            {"var", _Occupy->_AName}
          }
        )
      );
      
      if(_Occupy->_Aid == AllianceManager::Get()->GetOwnAid()){
        _TextZl->setColor(WorldMapDefine::Get()->GetLeagueManorLineColor(true));
        lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
      } else {
        auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_Occupy->_Aid);
        if(lAllianceRelationType == EMapAllianceRelationType::None) 
          lAllianceRelationType = EMapAllianceRelationType::NORMAL;
        lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lAllianceRelationType);
        _TextZl->setColor(lNameColor);
      }
    }else{
      _TextZl->setString(Translate::i18n("pyramid_text_02"));
      _TextZl->setColor(Color3B(255, 255, 255));
    }
  } else if(_WarStatus == EKingdomWarStatusType::rule){
    if(_Occupy && _Occupy->_Aid > 0){
      _TextZl->setString(
        Translate::i18n(
          "common_text_186", 
          {
            {"var", _Occupy->_Abbr}, 
            {"var", _Occupy->_AName}
          }
        )
      );
      
      if(_Occupy->_Aid == AllianceManager::Get()->GetOwnAid()){
        _TextZl->setColor(WorldMapDefine::Get()->GetLeagueManorLineColor(true));
        lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
        if(_ColorID > 0){
          _RolygonColor = AllianceRead::Get()->GetTerritoryColor(_ColorID);
        } else {
          _RolygonColor = lNameColor;
        }
      }else{
        auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_Occupy->_Aid);
        if(lAllianceRelationType == EMapAllianceRelationType::None) 
          lAllianceRelationType = EMapAllianceRelationType::NORMAL;
        lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lAllianceRelationType);
        _TextZl->setColor(lNameColor);
        if((lAllianceRelationType == EMapAllianceRelationType::SELF || lAllianceRelationType == EMapAllianceRelationType::NORMAL) && _ColorID > 0){
          _RolygonColor = AllianceRead::Get()->GetTerritoryColor(_ColorID);
        } else {
          _RolygonColor = lNameColor;
        }
      }
    }else{
      _TextZl->setString(Translate::i18n("pyramid_text_02"));
      _TextZl->setColor(Color3B(255, 255, 255));
    }
  }
}

GString WorldMapStronghold::GetFavoriteName(){
  GString lFavoriteName = "";
  if(_ObjID){
    auto lBuildInfo = AllianceStrongholdMineRead::Get()->GetGateClientCfg(_ObjID);
    lFavoriteName = Translate::i18n("LV%{lv} %{name}", {
      {"lv", std::to_string(AllianceStrongholdMineRead::Get()->GetGateLv(_ObjID))},
      {"name", Translate::i18n(lBuildInfo->_Name.c_str())}
    });
  }
  return lFavoriteName;
}

void WorldMapStronghold::PlayClickSound() {
  GBase::PlaySound("innerbuildsound", 119);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapStronghold::OnClickInstance(Node *pNode) {
  PlayClickSound();
  auto [lSelectShowPanel, _1, _2] = OnShowWorldMapTip(pNode);
  auto lTilesRolygon = WorldMapTilesRolygon::Create(_Size + 2 * _Radioation);
  lTilesRolygon->SetRolygonColor(_RolygonColor);
  return {lSelectShowPanel, true, lTilesRolygon};
}

bool WorldMapStronghold::IsBeOccupied(){
  auto lRet = true;
  for(auto &lNpcLife : _Npc->_NormalNpcLifes){
    if(lNpcLife.second > 0){
      lRet = false;
      break;
    }
  }
  return lRet && 0 >= _Npc->_LeaderNpcLeftLife;
}

GVector<RButtonTypeArray> WorldMapStronghold::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);

  if(pIsSelfKingdom){
    if(_WarStatus == EKingdomWarStatusType::close){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
    } else if(_WarStatus == EKingdomWarStatusType::inWar){
      if(_Npc && !IsBeOccupied()){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
      }else if(_Occupy){
        if(_Occupy->_Aid == AllianceManager::Get()->GetOwnAid()){
          if(_Occupy->_IsIn){
            if(std::get<0>(CheckHasArmy())){
              lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui});
            }
            if(CanHasEmojiOperator()){
              lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
            }
            lButtonTypeArray.push_back({EWorldMapTipButtonType::shibingYuabzhu});
            if(lHaveHall && lSelfLeagueID > 0)
              lButtonTypeArray.push_back({EWorldMapTipButtonType::zuduiYuanzhu});
            lButtonTypeArray.push_back({EWorldMapTipButtonType::buDuiXiangqing});
          }else{
            lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
            if(lHaveHall && lSelfLeagueID > 0)
              lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
          }
        } else {
          lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
          if(_Occupy->_IsIn && lHaveHall && lSelfLeagueID > 0)
            lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
          auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
          if(lTowerLv > 1){
            lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
          }
        }
      } else {
        lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
        if(lHaveHall && lSelfLeagueID > 0)
          lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
    }else{
      lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
    }
  }else{
    lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
  }
  return lButtonTypeArray;
}

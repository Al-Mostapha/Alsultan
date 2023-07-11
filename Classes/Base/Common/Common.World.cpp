#include "Common.World.h"
#include "Base/Base.Lib.h"
#include "Game/Config/FunUnLock/FunUnlock.Read.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Module/Player/Player.Top.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldWar/WorldWar.Def.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/City/City.Ctrl.h"
#include "Scene/Scene.Type.h"

#include "Scene/CityScene.h"

bool GBase::DGotoWorldMapPoint(
  GOpt<Vec2> pPoint, bool pIsSelected, int32 pKingdomID,
  EWorldMapLayInstance pLayInstance, GOpt<RLayInstanceData> pLayInstanceData,
  bool pInPyramid, bool pIsShowHand)
{
  auto lUnlockLv = FunUnlockRead::Get()->GetUnlockLevel(EFunID::WORLD_CITY);
  if(GBase::DGetCastleLv() < lUnlockLv)
  {
    GBase::DShowMsgTip(Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("common_text_528")},
      {"lv", std::to_string(lUnlockLv)}
    }));
    return false;
  }
  
  auto lChangeType = pInPyramid;
  pKingdomID = pKingdomID ? pKingdomID : PlayerTop::Get()->GetMapID();
  if(pKingdomID != WorldMapDefine::Get()->CurrentMapKindomID){
    auto lToClassType = WorldMapWarDef::Get()->GetKingdomMapClassByKingdomId(pKingdomID);
    EKingdomClassType lFromClassType;
    if(WorldMapDefine::Get()->CurrentMapKindomID)
      lFromClassType =  WorldMapWarDef::Get()->GetKingdomMapClassByKingdomId();
    else
      lFromClassType = KingdomMapCtrl::Get()->GetKingdomClass() != EKingdomClassType::None ? KingdomMapCtrl::Get()->GetKingdomClass() : EKingdomClassType::Normal;
    
    if(lToClassType != lFromClassType){
      if(lToClassType == EKingdomClassType::Pyramid || lToClassType == EKingdomClassType::Remains){
        if(pInPyramid /*or _G.SoraDIsAnchor()*/)
          lChangeType = true;
        else{
          GBase::DShowMsgTip(Translate::i18n("common_text_3249"));
          return false;
        }
      }else if(pInPyramid)
        lChangeType = true;
      else if(
        (lToClassType == EKingdomClassType::LegendLord 
        && lFromClassType == EKingdomClassType::Normal)
        || (lFromClassType == EKingdomClassType::LegendLord
        && lToClassType == EKingdomClassType::Normal)){
          lChangeType = true;
      }else{
        if(lToClassType == EKingdomClassType::Radiance){
          GBase::DShowMsgTip(Translate::i18n("brightWar_text_79"));
        }else{
          GBase::DShowMsgTip(Translate::i18n("common_text_3249"));
        }
        return false;
      }
    } else if(
      lToClassType == EKingdomClassType::Pyramid 
      || lToClassType == EKingdomClassType::Remains
      || lToClassType == EKingdomClassType::Radiance
      || lToClassType == EKingdomClassType::Nebula){
      if(!pInPyramid)
        pKingdomID = WorldMapDefine::Get()->CurrentMapKindomID;
    }else if(lToClassType == EKingdomClassType::LegendLord){
      lChangeType = true;
    }
  }

  if(!pPoint)
    pPoint = CityCtrl::Get()->GetCurCityPos();
  WorldMapDefine::Get()->CurrentMapKindomID = pKingdomID ? pKingdomID : WorldMapDefine::Get()->CurrentMapKindomID;
  auto lCurrentScene = Director::getInstance()->getRunningScene();
  if(lCurrentScene->getName() == "MainScene"){
    if(CityScene::Get() || lChangeType){
      static RShowMainCityView sMainCityView;
      sMainCityView.ViewType = EScene::World;
      sMainCityView.OtherData.kingdomID = pKingdomID;
      sMainCityView.OtherData._TilePoint = *pPoint;
      sMainCityView.OtherData._IsSelected = pIsSelected;
      sMainCityView.OtherData._LayInstance = pLayInstance;
      sMainCityView.OtherData._LayInstanceData = *pLayInstanceData;
      GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", &sMainCityView);
    }else{
      static RGotoTilePointEvAr sGotoTilePointEvAr;
      sGotoTilePointEvAr._IsShowHand = pIsShowHand;
      sGotoTilePointEvAr._KingdomID = pKingdomID;
      sGotoTilePointEvAr._TilePoint = *pPoint;
      sGotoTilePointEvAr._IsSelected = pIsSelected;
      sGotoTilePointEvAr._LayInstance = pLayInstance;
      sGotoTilePointEvAr._LayInstanceData = *pLayInstanceData;
      GBase::DSendMessage("MESSAGE_WORLD_MAP_GOTO_TILEPOINT", &sGotoTilePointEvAr);
    }
  }
  return true;
}
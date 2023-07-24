#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

USING_NS_CC;

class WorldMapDefine{
public: 

  enum class Z_ORDER_CELL{
    selectBgView = 0,
    borderLine = 5,
    rolygonView = 10,
    objBgView = 20,
    objView = 30,
    grayLayer = 35,
    moveLineBg = 40,
    moveLine = 45,
    transView = 50,
    otherTipView = 100
  };

  static WorldMapDefine * Get();
  int32 CurrentMapKindomID = 0;
  cocos2d::Size _WorldMapViewSize;
  int32 _CurSelectNodeInfo = 1;
  
  bool IsInWar();
  bool IsInLegendLord();
  bool IsInRemains();
  bool IsInRadiance();
  bool IsInAtlantis();
  bool IsInNebula();
  bool IsInPyramid();
  bool InInCrossWar();
  bool IsInKingdomBattle();
  bool IsInWarForbid(bool p_NoShowTips = false, bool p_Activity = false);
  bool IsInWarForbidSoldier(bool p_NoShowTips = false, bool p_Activity = false);
  void ShowWarTips(bool p_Activity = false);
  bool IsNebulaKingdomID();
  bool IsLegendLordKingdomID(int32 pKingdomID = 0);
  bool IsPyramidKingdomID(int32 pKingdomID = 0);
  Color3B GetMoveLineColor(EMapMoveLineColor pColor);
};
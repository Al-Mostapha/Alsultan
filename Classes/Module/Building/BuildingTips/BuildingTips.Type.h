#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Building/Building.Enum.h"

struct RBuildingTipsBtnListData{
  int32 bid;
  EBuilding idBuilding;
  GString BuildingName;
  GString PicFile;
  GString ImgFile;
  Vec2 Offset;
  Vec2 OffsetByzantine;
  bool bIsInnerBuilding;
  bool bCanBuild;
  GVector<int32> NormalOperateList;
  GVector<int32> CoolingOperateList;
  GVector<int32> TrainingOperateList;
  void FromJson(GJson *p_Json){
    BuildingName = "Test";
  }
};
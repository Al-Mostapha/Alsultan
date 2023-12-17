#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"
#include "Base/Type/XEngine.h"
#include "Module/Building/Building.Enum.h"
#include "BuildingTips.Enum.h"
#include "Base/Type/XJson.h"


struct RBuildingTipsBtnListData{
  int32 bid;
  EBuilding idBuilding;
  ECityBuildingState cityBuildingState = ECityBuildingState::None;
  GString BuildingName = "buildDes_name_101";
  GString PicFile;
  GString ImgFile;
  Vec2 Offset;
  Vec2 OffsetByzantine;
  bool bIsInnerBuilding;
  int bCanBuild = 1;
  GVector<EBuildingTips> NormalOperateList = {
    EBuildingTips::OpDetails,
    EBuildingTips::OpUpgrade,
    EBuildingTips::OpArena,
    EBuildingTips::OpAllianceBattle
  };
  GVector<EBuildingTips> CoolingOperateList;
  GVector<EBuildingTips> TrainingOperateList;
  bool FromJson(const XJson &pJson){
		bid = pJson.value("bid", 0);
    idBuilding = static_cast<EBuilding>(pJson.value("buildingID", 0));
    cityBuildingState = static_cast<ECityBuildingState>(pJson.value("cityBuildingState", 0));
    BuildingName = pJson.value("BuildingName", "buildDes_name_101").c_str();
		PicFile = pJson.value("PicFile", "icon_building_details.png").c_str();
		ImgFile = pJson.value("ImgFile", "icon_building_details.png").c_str();
		Offset.x = pJson.at("Offset").at("x").get<float>();
		Offset.y = pJson.at("Offset").at("y").get<float>();
		OffsetByzantine.x = pJson.at("OffsetByzantine").at("x").get<float>();
		OffsetByzantine.y = pJson.at("OffsetByzantine").at("y").get<float>();
    bIsInnerBuilding = pJson.value("bIsInnerBuilding", false);
    bCanBuild = pJson.value("bCanBuild", 1);
    for(auto lOp : pJson["NormalOperateList"])
			NormalOperateList.push_back(static_cast<EBuildingTips>(lOp.get<int>()));
    for(auto lOp : pJson["CoolingOperateList"])
			CoolingOperateList.push_back(static_cast<EBuildingTips>(lOp.get<int>()));
		for(auto lOp : pJson["TrainingOperateList"])
			TrainingOperateList.push_back(static_cast<EBuildingTips>(lOp.get<int>()));
    return true;
  }
};

struct RBuildingTipConfig
{
	uint32 btnId = 1003;
	EBuildingTips btnEnum = EBuildingTips::OpDetails;
	GString OpName = "common_text_059";
	GString Desc = "common_text_059";
	GString PicFile = "icon_building_details.png";
	uint32 OpSortIndex = 30;
	float scale = 0;
	Vec2 offset = {5, 0};

	bool FromJson(const XJson &pJson){
		btnId = pJson.value("btnId", 0);
    btnEnum = static_cast<EBuildingTips>(pJson.value("btnEnum", 0));
    OpName = pJson.value("OpName", "None");
    Desc = pJson.value("Desc", "None");
    PicFile = pJson.value("PicFile", "None.png");
    OpSortIndex = pJson.value("OpSortIndex", 0);
    scale = pJson.value("scale", 0);
    offset.x = pJson.at("offset").value("x", 0);
    offset.y = pJson.at("offset").value("y", 0);
    return true;
	}
};
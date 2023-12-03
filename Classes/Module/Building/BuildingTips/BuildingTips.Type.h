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
  ECityBuildingState _CityBuildingState = ECityBuildingState::None;
  GString BuildingName = "buildDes_name_101";
  GString PicFile;
  GString ImgFile;
  Vec2 Offset;
  Vec2 OffsetByzantine;
  bool bIsInnerBuilding;
  bool bCanBuild;
  GVector<EBuildingTips> NormalOperateList = {
    EBuildingTips::OpDetails,
    EBuildingTips::OpUpgrade,
    EBuildingTips::OpArena,
    EBuildingTips::OpAllianceBattle
  };
  GVector<EBuildingTips> CoolingOperateList;
  GVector<EBuildingTips> TrainingOperateList;
  void FromJson(const XJson &pJson){
    BuildingName = "Test";
  }
};

struct RBuildingTipConfig
{
	uint32 btnId = 1003;
	EBuildingTips btnEnum = EBuildingTips::OpDetails;
	GString ActionName = "common_text_059";
	GString BtnDesc = "common_text_059";
	GString PicFile = "icon_building_details.png";
	uint32 OpSortIndex = 30;
	float scale = 0;
	Vec2 offset = {5, 0};

	// bool fromJsonObject(GJsonObject &JsonObject)
	// {

	// 	btnId = JsonObject.HasMember("btnId") ? JsonObject["btnId"].GetInt() : -1;
	// 	btnEnum = static_cast<ECityBtnAction>(JsonObject.HasMember("btnEnum") ? JsonObject["btnEnum"].GetInt() : 0);
	// 	ActionName = JsonObject.HasMember("ActionName") ? JsonObject["ActionName"].GetString() : "";
	// 	BtnDesc = JsonObject.HasMember("BtnDesc") ? JsonObject["BtnDesc"].GetString() : "";
	// 	BtnImage = JsonObject.HasMember("BtnImage") ? JsonObject["BtnImage"].GetString() : "";
	// 	ActionSortIndex = JsonObject.HasMember("ActionSortIndex") ? JsonObject["ActionSortIndex"].GetInt() : 0;
	// 	scale = JsonObject.HasMember("scale") ? JsonObject["scale"].GetInt() : 0;

	// 	if (JsonObject.HasMember("offset") && JsonObject["offset"].IsObject())
	// 	{
	// 		offset.x = (float) JsonObject["offset"].HasMember("x") ? (float) JsonObject["offset"]["x"].GetInt() : 0.0f;
	// 		offset.x = (float) JsonObject["offset"].HasMember("y") ? (float) JsonObject["offset"]["y"].GetInt() : 0.0f;
	// 	}
	// }

	// GString toString()
	// {

	// 	return cocos2d::StringUtils::format(
	// 		"RCityBtnAction :\
	// 		 {btnId: %d, btnEnum: %d, ActionName: %s, BtnDesc: %s, BtnImage: %s, ActionSortIndex: %d, scale: %d, offset: %s}",
	// 		btnId, 
	// 		int(btnEnum),
	// 		 ActionName.c_str(),
	// 		  BtnDesc.c_str(), 
	// 			BtnImage.c_str(),
	// 			ActionSortIndex, 
	// 			scale,
	// 		cocos2d::StringUtils::format("{x: %d, y: %d}", offset.x, offset.y).c_str());
	// }
};
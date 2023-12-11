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
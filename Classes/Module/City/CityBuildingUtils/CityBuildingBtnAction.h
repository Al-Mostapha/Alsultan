
#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"

enum class ECityBtnAction
{
	OpNone = 0,
	OpBoostByTool = 1001,
	OpBoost = 1002,
	OpDetails = 1003,
	OpSpeedUpByGold = 1004,
	OpSpeedUpByTool = 1005,
	OpUpgrade = 1006,
	OpTrade = 1007,
	OpAuction = 1008,
	OpResearch = 1009,
	OpBuild = 1010,
	OpTrain = 1011,
	OpHelp = 1012,
	OpReinforcements = 1013,
	OpWish = 1014,
	OpAllianceBattle = 1015,
	OpDefend = 1016,
	OpMilitaryInfo = 1017,
	OpCityInfo = 1018,
	OpCityDecorate = 1019,
	OpCityGift = 1020,
	OpAllianceTreasure = 1021,
	OpCityBuff = 1022,
	OpHeal = 1023,
	OpCollect = 1024,
	OpForging = 1025,
	OpStoragebox = 1026,
	OpPyramid = 1027,
	OpBadgeBourse = 1028,
	OpFriend = 1029,
	OpMilitaryPoint = 1030,
	OpWar = 1031,
	OpMonthGift = 1032,
	OpDaylySign = 1033,
	OpResuscitate = 1034,
	OpDailyReward = 1035,
	OpPet = 1036,
	OpPetMap = 1037,
	OpPetExchange = 1038,
	OpPremiumVipMall = 1039,
	OpWarGem = 1040,
	OpWarTechnology = 1041,
	OpArena = 1042,
	OpDiscuss = 1043,
	OpSupport = 1044,
	OpSpringOfLife = 1045,
	OpFaction = 1046,
	OpInfoCenter = 1047,
	OpMonument = 1048,
	OpTrainHall = 1049,
	OpPrison = 1050,
	OpMastery = 1051,
	OpMainMastery = 1052,
	OpDrawing = 1053,
	OpArtifact = 1054,
	OpMonumentLegend = 1055,
	OpIntetior = 1056,
	OpCounterSys = 1057,
	OpExclusiveVip = 1058,
	OpStarUpgrade = 1059,
	OpStarSpeedUp = 1060,
	OpEndlessTreasure = 1061,
	OpProcessStudy = 1062,
	OpWarframeForg = 1063,
	OpWarframeStoreroom = 1064,
	OpstatueBrave = 1065,
	OpMilitaryFortress = 1066
};

struct RCityBtnAction : GStruct
{

	uint32 btnId;
	ECityBtnAction btnEnum;
	GString ActionName;
	GString BtnDesc;
	GString BtnImage;
	uint32 ActionSortIndex;
	uint32 scale;
	Vec2 offset;

	bool fromJsonObject(GJsonObject &JsonObject)
	{

		btnId = JsonObject.HasMember("btnId") ? JsonObject["btnId"].GetInt() : -1;
		btnEnum = static_cast<ECityBtnAction>(JsonObject.HasMember("btnEnum") ? JsonObject["btnEnum"].GetInt() : 0);
		ActionName = JsonObject.HasMember("ActionName") ? JsonObject["ActionName"].GetString() : "";
		BtnDesc = JsonObject.HasMember("BtnDesc") ? JsonObject["BtnDesc"].GetString() : "";
		BtnImage = JsonObject.HasMember("BtnImage") ? JsonObject["BtnImage"].GetString() : "";
		ActionSortIndex = JsonObject.HasMember("ActionSortIndex") ? JsonObject["ActionSortIndex"].GetInt() : 0;
		scale = JsonObject.HasMember("scale") ? JsonObject["scale"].GetInt() : 0;

		if (JsonObject.HasMember("offset") && JsonObject["offset"].IsObject())
		{
			offset.x = (float) JsonObject["offset"].HasMember("x") ? (float) JsonObject["offset"]["x"].GetInt() : 0.0f;
			offset.x = (float) JsonObject["offset"].HasMember("y") ? (float) JsonObject["offset"]["y"].GetInt() : 0.0f;
		}
		return true;
	}

	GString toString()
	{

		return cocos2d::StringUtils::format(
			"RCityBtnAction :\
			 {btnId: %d, btnEnum: %d, ActionName: %s, BtnDesc: %s, BtnImage: %s, ActionSortIndex: %d, scale: %d, offset: %s}",
			btnId, 
			int(btnEnum),
			 ActionName.c_str(),
			  BtnDesc.c_str(), 
				BtnImage.c_str(),
				ActionSortIndex, 
				scale,
			cocos2d::StringUtils::format("{x: %f, y: %f}", offset.x, offset.y).c_str());
	}
};
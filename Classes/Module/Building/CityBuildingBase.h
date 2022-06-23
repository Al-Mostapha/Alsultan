#pragma once

#include "cocos2d.h"
#include "Include/IncludeBase.h"
#include "Module/City/CityBuildingUtils/CityBuildingBtnAction.h"
USING_NS_CC;

struct DSBuilding : public GStruct
{
	int idBuilding;
	GString BuildingName;
	GString BuildingIcon;
	GString BuildingImg;
	GString BuildingImg_byzt;
	GString BuildingBrief;
	GString UpgradeBrief;
	GString Desc;
	GString WarDesc;
	GString StarDesc;
	GString AliasName;
	struct
	{
		int32 x, y;
	} TipsOffset;

	bool bIsInnerBuilding;
	bool bCanBuild;
	GArray<DSCityBtnAction> ActionBtnList;
	struct
	{
		int32 x, y;
	} offset;
	struct
	{
		int32 x, y;
	} offsetByzantine;
};

class CityBuildingBase : public cocos2d::Node
{

public:
	CREATE_FUNC(CityBuildingBase);

	Sprite *BuildingSprite;
	Sprite *UpgradeSprite;
	Label *BuildingLvText;
	Sprite *BuildingLvBg;
	struct
	{
		int32 x = 110, y = -17;
	} LvlBgOffset;
	GString BuildingSpriteImage;
	GString BuildingIconMiracle;
	struct
	{
		int32 x, y;
	} BuildingSpriteOffset;

	virtual bool init();
	virtual void onEnter();
	virtual void setBuildingSprite();
	virtual void setUpgradeSprite();
	virtual void setBuildingLvBg();
	virtual void setBuildingLvlText();
	virtual void setBuildingSleepSprite();
	virtual void setBuildingIconMiracle();
	virtual void setBuildingParticle();
	virtual void setBuildingAnimation();

	static Vector<SpriteFrame *> getAnimation(GString Frame, int32 start, int32 end);
};
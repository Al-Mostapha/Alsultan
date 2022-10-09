#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Building/Building.Const.h"
#include "Module/City/CityBuildingUtils/CityBuildingBtnAction.h"
#include "ui/UILayout.h"
#include "Module/Translation/Translate.h"
#include "Module/City/City.Lib.h"

USING_NS_CC;
using namespace ui;

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
	GArray<RCityBtnAction> ActionBtnList;
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
	Label  *BuildingLvText;
	Sprite *BuildingLvBg;
	Layout *BuildingBtn;
	
	RCityBuildingUnit BuildingUnitData;

	Vec2    LvlBgOffset;
	GString BuildingSpriteImage;
	GString BuildingIconMiracle;
	Vec2    BuildingSpriteOffset;

  Node *m_CurrentSelectTip = nullptr;
  bool m_TouchIsMoveOnBuild = false;
  bool m_IsBuildBtnEnabled = true;
  EBuildingIndex m_BuildingIndex;
 

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
	virtual void setBuildingBtn();
	void setBuildingUnitData(RCityBuildingUnit &_CBUD);
  virtual void Clicked(Touch* p_Touch, Event* p_Event);
  virtual void InitEvents();
  virtual void InitTouchEvents();
  virtual void RemoveBuildingTip();
  virtual void CancelTint();
  virtual bool IsLocked(){ return false;}
  virtual bool IsLockVisible(){ return false;}
  virtual void ShowTintOnce(){}
  virtual bool IsCanSpeedUpStrongFree(){ return false; }
  virtual bool IsCanSpeedUpFree(){ return false; }
  virtual bool IsCanSpeedUpResearchFree(){ return false; }
  virtual bool IsNeedRequestHelp(){ return false; }
  virtual bool IsFignting() { return  false; }
  virtual bool HasAnyAllianceHelpList(){ return false; }
  virtual bool AllianceHelpAll(){ return false; }
  virtual bool RequestHelp(){ return false; }
  virtual bool SpeedUpStrongFree(){ return true; }
  virtual bool SpeedUpFree(){ return true; }
  virtual bool SpeedUpResearchFree(){ return true; }
  virtual bool IsCanHarvest() { return false; } // can harvest resource or army or any other tip
  virtual bool HarvestAll(){ return false; } // can harvest resource or army or any other tip
  virtual EBuildingState GetState() { return EBuildingState::None;}
	static Vector<SpriteFrame *> getAnimation(GString Frame, int32 start, int32 end);
private:
  virtual bool IgnoreClickEvent(Touch* p_T, Event* p_E) const;
};
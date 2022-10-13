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

class IBuilding : public cocos2d::Node
{

public:
	CREATE_FUNC(IBuilding);

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
  bool m_SingleIsMoved = false;
  bool m_IsCancelled = false;
  bool m_IsReconnected = false;
  bool m_hasNpcTip = false;
  bool m_UdpateIsCanUpGrade = false;
  GTime m_UdpateIsCanUpGradeTime = 0;
  EBuildingState m_blockState = EBuildingState::None;
  EHarvestState m_HarvestState = EHarvestState::None;
  EBuildingIndex m_BuildingIndex =  EBuildingIndex::None;
  uint32 m_BuffId = 0;
  bool m_IsShowBuff = false;
  bool m_IsCanSpeedUpFree = false;
  bool m_IsCanResearchFree = false;
  bool m_QueueDirty = false;
  Vec2 m_PosEtUpgradeOffset = Vec2(0, 0);
  bool m_IsTraining = false;
  bool m_IsHowWarLv = false;
  

	virtual bool init() override;
  virtual void InitStateMachine(){}
	virtual void onEnter();
  virtual void OnMessageListener(); // InitEvents
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

  virtual void SMsgRemoveBuff(EventCustom *p_Event);
  virtual void SMsgUpdateBuildCanUpgrade(EventCustom *p_Event);
  virtual void SMsgTrainArmyImmediatelyBack(EventCustom *p_Event);
  virtual void SMsgBuildTrainFailed(EventCustom *p_Event);
  virtual void UpdateStarLvl(EventCustom *p_Event);

  virtual void UpdateStarLvl(){}
  virtual void UpdateLvl(){}
  virtual void UpdateIsCanUpgrade(){}
  virtual void StartTimer(){}
  virtual void EndTimer(){}
  virtual void UpdateTimer(){}
  virtual void ShowTopTip();
  virtual void HideTopTip();
  virtual bool IsOpen(){ return false; }
  virtual void ShowAnimBuildWorker(){ }
  virtual void ShowBuildLock(){ }
  virtual void ShowBuildLvl(){ }
  virtual void ShowWorkDone();
  virtual void ShowAnimWorking(){}
  virtual void HideAnimWorking(){}
  virtual void ShowGlow(){}
  virtual void ShowBrightParticle(){}
  virtual void HideBrightParticle(){}
  virtual void ShowZAnimation(){}
  virtual void HideZAnimation(){}
  virtual void ShowGlow(){}
  virtual void OnAfterInitWithBuildCell(){ } //PostInit

private:
  virtual bool IgnoreClickEvent(Touch* p_T, Event* p_E) const;
};
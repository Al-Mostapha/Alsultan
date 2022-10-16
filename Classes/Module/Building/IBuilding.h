#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Include/IncludeConfig.h"
#include "Module/Building/Building.Const.h"
#include "Module/City/CityBuildingUtils/CityBuildingBtnAction.h"
#include "ui/UILayout.h"
#include "Module/Translation/Translate.h"
#include "Module/City/City.Lib.h"
#include "Module/City/City.Ctrl.h"
#include "State/Building.State.h"

USING_NS_CC;
using namespace ui;

class IBuilding : public cocos2d::Node
{

public:
	CREATE_FUNC(IBuilding);

	Sprite *BuildingSprite;
	Sprite *n_UpgradeSprite;
	Label  *n_BuildingLvText;
	Sprite *n_BuildingLvBg;
	Layout *BuildingBtn;
	
	RCityBuildingUnit BuildingUnitData;

	Vec2    LvlBgOffset;
	GString BuildingSpriteImage;
	GString BuildingIconMiracle;
	Vec2    BuildingSpriteOffset;

  Node *m_CurrentSelectTip = nullptr;
  Node *n_BuildStarLight = nullptr;
  Sprite *n_SpStarLight = nullptr;
  Node *n_BuildGlowWar = nullptr;

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
  bool m_IsSHowWarLv = false;
  bool m_IsCanUpgrade = false;
  bool m_IsCanUpgradeStar = false;
  RBuildingTask *m_BuildingTask = nullptr;
  GHashMap<EBuildingState, IState*> m_States;
	virtual bool init() override;
  virtual void InitStateMachine();
	virtual void onEnter();
  virtual void OnMessageListener(); // InitEvents
	virtual void setBuildingSprite();
	virtual void setUpgradeSprite();
	virtual void setBuildingLvBg();
	virtual void setBuildingLvlText();
	virtual void setBuildingSleepSprite();
	virtual void setBuildingIconMiracle();
	virtual void ShowNormalParticle();
	virtual void HideNormalParticle();
	virtual void ShowAnimWorking(bool p_ShowGlow = false);
	virtual void setBuildingBtn();
	void setBuildingUnitData(RCityBuildingUnit &_CBUD);
  virtual void Clicked(Touch* p_Touch, Event* p_Event);
  virtual void InitEvents();
  virtual void InitTouchEvents();
  virtual void RemoveBuildingTip();
  virtual void CancelTint();
  virtual Node *GetBuildingCell(){ return nullptr;}
  virtual EBuildingIndex GetBuildingIndex(){ return EBuildingIndex::None;}

  virtual bool IsLocked(){ return false;}
  virtual bool IsLockVisible(){ return false;}
  virtual void ShowTintOnce(){}
  virtual bool IsCanSpeedUpStrongFree(){ return false; }
  virtual bool IsTraining(){ return m_IsTraining; }
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

  EBuilding GetBuildingId(){ return BuildingUnitData.eBuildingType; }
  virtual void SetIsCanUpgrade(bool p_IsCan = false);
  virtual void SetIsCanUpgradeStar(bool p_IsCan = false){}

  virtual void SetQueueDirty(bool p_IsCan = false){}
  
 
  virtual void UpdateIsCanUpgrade();
  virtual void UpdateIsCanUpgradeStar();
  virtual void StartTimer(){}
  virtual void EndTimer(){}
  virtual void UpdateTimer(){}
  virtual void ShowTopTip();
  virtual void HideTopTip();
  virtual void UpdateTopTip();
  virtual bool IsOpening(){ return false; }

  virtual void ShowAnimBuildWorker();
  virtual void HideAnimBuildWorker();

  virtual void ShowBuildLock(){ }

  virtual uint32 GetBuildingLvl(){ return 0;}
  virtual uint32 GetStarLvl(){ return 0;}
  virtual void ShowBuildLvl();
  virtual void UpdateLvl();
  virtual void HideBuildLvl();
  virtual void UpdateStarLvl(){}
  virtual void SetTextLvl(const GString &p_Lvl){}
  virtual void UpdateTextLvl();
  virtual void UpdateLvlPos(){}
  virtual void UpdateStarLvl(EventCustom *p_Event);
  virtual void UpdateStarLvlBgLight();
  virtual void UpdateStarLvlPos(){}
  virtual void RefreshBuildStarState(void * p_Temp);

  virtual void UpdateIsLock(){}
  virtual void UpdateViewModel(){}

  virtual void ShowWorkDone();
  virtual void HideWorkDone();
  virtual void HideAnimWorking();
  virtual void ShowAnimBoost();
  virtual void HideAnimBoost();

  virtual void HideAnimBuildWorker(){}
  virtual void ShowGlow();
  virtual void HideGlow();

  virtual void ShowCoolingPanel();
  virtual void HideCoolingPanel();

  virtual void ShowEffectUpgrade(){}
  virtual void HideEffectUpgrade(){}

  virtual void ShowWorkingEffect(){}
  virtual void HideWorkingEffect(){}

  virtual void ShowBrightParticle(){}
  virtual void HideBrightParticle(){}
  virtual void ShowZAnimation(){}
  virtual void HideZAnimation(){}
  virtual void OnAfterInitWithBuildCell(){ } //PostInit
  virtual void SetHarvestState(EHarvestState p_HarvestState, bool p_IsAnim = false){ } 
  virtual void SetBlockState(EBuildingState p_BuildingState){ m_blockState = p_BuildingState; } 

  virtual void UpdateViewAfterBuild() {};
  virtual void ChangeState();
private:
  virtual bool IgnoreClickEvent(Touch* p_T, Event* p_E) const;
};
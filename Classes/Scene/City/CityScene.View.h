#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Base/Containers/HashMap.h"
#include "Base/Base.View.h"
#include "Module/Building/Building.Enum.h"

class MainCityView : public BaseView
{
GHashMap<GString, Node *> n_BufferNodeArray;

public:
  bool m_IsNeedFirstFight = false;
  bool m_IsFinishInit = false;
  Ext::ScrollView *n_ViewScrollView = nullptr;
  bool m_IsBuildBtnEnable = false;
  Scheduler *m_TimeHandler = nullptr;
  Scheduler *m_TimeHandlerPerFrame = nullptr;
  bool m_IsLogin = false;
  void Ctor();
  void PreLoadImages();
  bool IsNeedFirstFight();
  void AddToBufferNodeArrayByName(const char *p_Name, Node *p_Node){
    if(!p_Node)
      return;
    n_BufferNodeArray[p_Name] = p_Node;
  }
  void FinishLoadImages();
  void OnMessageListener_FinishLoadImage();
  virtual void InitAfterCreate() = 0;
  void InitCelebrateGift(){
    //effectMainCityView.initCelebrateGift(self, target, data)
  }
  void MsgUpdateLion(){
    //mainCityMsg.msgUpdateLion(self, target, data)
  }
  void AddBuild(EBuildingIndex p_Index, EBuilding p_BuildingId){
    //mainCityFunctions.addBuild(self, buildBtnId, buildCfgId)
  }

  void LoadFixedBuilds();
  void SetMainCityEnabled(bool p_Enabled);
  void UpdateBuildTiles();
  void AutoUpdateViewScrollViewPos(float p_Delay = 0);
  void SetZoomScale(float p_ZoomScale, bool p_Animated = false, float p_duration = 0.0f, bool p_CustomAnim = false);
  void LoadSoldiers();
  void UpdateTime(float p_Time);
  void UpdateTimePerFrame(float p_Time);
  void RefreshCastleSkin(bool p_IsInit = false);


  void InitVisibleArea();
  void EnableShack();
};
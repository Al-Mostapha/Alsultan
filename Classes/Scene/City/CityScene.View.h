#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Base/Containers/HashMap.h"
#include "Module/UI/UIBaseView.h"
#include "Module/UI/UICCSView.h"
#include "Module/Building/Building.Enum.h"


struct RShowMainCityView{
  bool isJudgeCurScene = false;
  EScene ViewType = EScene::None;
  bool isFromLogin = false;
  bool isFactionSwitch = false;
  RViewOtherData OtherData;
};

class MainCityView : public UIBaseView
{
  GHashMap<GString, Node *> n_BufferNodeArray;
  CREATE_FUNC(MainCityView);
  CreateUIPanel(MainCityView);
  CreateUICCSView(MainCityView);
  RViewOtherData m_Param;
public:
  static MainCityView *Create(RViewOtherData p_Data);
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
  virtual void InitAfterCreate(){};
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
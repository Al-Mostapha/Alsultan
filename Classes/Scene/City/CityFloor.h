#pragma once
#include "CityCommon.h"
#include "CityBuildings.h"

class CityFloor : public CityBuildings {
  ui::Layout *_ButtonMilitaryInfo  = nullptr;
  ui::Layout *_ButtonMerchante     = nullptr;
  ui::Layout *_ButtonActivity      = nullptr;
  ui::Layout *_ButtonEpicBattle    = nullptr;
  ui::Layout *_ButtonMonument      = nullptr;
  ui::Layout *_ButtonPyramidBattle = nullptr;
  ui::Layout *_ButtonLion          = nullptr;
  ui::Layout *_ButtonMaTou         = nullptr;
  ui::Layout *_ButtonConquer       = nullptr;
  ui::Layout *_ButtonBulletInBoard = nullptr;
  ui::Layout *_ButtonLeisureCenter = nullptr;
  ui::Layout *_ButtonHuoChuang     = nullptr;
  ui::Layout *_ButtonPetCenter     = nullptr;
  ui::Layout *_ButtonResurrectionHall = nullptr;
  ui::Layout *_ButtonServiceCenter = nullptr;
  ui::Layout *_BtnHuoChuang    = nullptr;
  ui::Layout *_BtnPetCenter    = nullptr;
  public:
  void Ctor();
  void CreateBatchNodes();
  void InitBufferNodeArray();
  virtual void AddToBufferNodeArrayByName(const char *p_Name, Node *p_Node) = 0;
  virtual Node *GetBufferNodeByName(const char *p_NodeName) = 0;
  virtual Vec2 GetDefaultMainCityPos() = 0;
  virtual void UpdatePeriod() = 0;
  void ViewOnClick(Ref* p_Ref, ui::Widget::TouchEventType p_Type){
  }
  void InitBuild();
  void InitOriginBuild();
  void InitMainCityPos();

  void BuildButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
    CityBuildings::BuildingButtonCallFun(p_Build, p_Ref, p_Touch);
  }
  void KipchaksButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch){}
  void KipchaksUpdate(){}
  void OtherBuildButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch){}
  void InitWithBuildData();
  void InitWithHuoChuangData();
  void InitMatouData();
  void CreateInnerCityBuilds();
  void CreateOuterCityBuilds();
  void DelayInitWithBuildData();
  bool InitPlayerLevelOffLine();
  void CheckCastleGift();
  void CheckEndlessTreasure();
  void CheckAllianceTreasure();
  void CheckFriend();
  void CheckEpicWar();
  void CheckPromoteArmy();
  void CheckMastery();
  class IBuilding *AddBuilding(EBuildingIndex p_Index, EBuilding p_IdBuilding);
};
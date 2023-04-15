#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Task/Task.Enum.h"
#include "Module/CityResource/Resource.Enum.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Building/Building.Task.h"


class UIBuildingCreateSingle : public UIBasePanel
{
public:
  enum class EBuildingCondType {
    Building = 1,
    Res = 2,
    Tool = 3,
    Time = 4,
    We = 5,
    Star = 6,
    Item = 7,
    NebulaTower = 8
  };

  struct RBuildingCondData{
    ETask _QType;
    int32 _BLvl;
    int32 _NeedLvl;
    int32 _StarLvl;
    int32 _IdItem;
    int32 _CurCount;
    int32 _ItemCount;
    int32 _ResCount;
    EResource _Resid;
    bool _IsReach;
    bool _IsNormal;
    struct  
    {
      EBuilding _Bid;
      EBuildingIndex _Iid;
      RBuildingTask _Task;
    }_Data;
  };

  CREATE_FUNC(UIBuildingCreateSingle);
  CreateUIPanel(UIBuildingCreateSingle);
  CreateUICCSView(UIBuildingCreateSingle);
  
  ui::ImageView *_ImgIcon;
  ui::Text *_LabelDes;
  ui::Button *_BtnJump;
  ui::ImageView *_ImgState;
  Sprite *_SpriteLuckLine;
  ui::Text *_LabelLuckValue;
  ui::ScrollView *_Scroll;
  Scheduler *_Timer;
  bool _IsMet;
  bool _SingleIsMoved = false;
  EBuildingCondType _Type;
  RBuildingCondData _SingleData;
  std::function<void (RBuildingCondData &)> _HandleCallBack;
public: 

  static UIBuildingCreateSingle* Create();
  void Ctor() override;
  void SetBtnCallBack(std::function<void (RBuildingCondData &)> p_CallBack){
    _HandleCallBack = p_CallBack;
  }
  void SetScroll(ui::ScrollView *p_Scroll){_Scroll = _Scroll;}
  void InitData(EBuildingCondType p_Type, RBuildingCondData p_Data = RBuildingCondData());
  void BtnJumpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  
  void NeedSpeedUp();
  void NeedUpgrade();
  void NeedResource();
  void CollegeOpen();
  bool LuckBlessOpen(bool p_IsOpen);
  bool RadiantBlessOpen(bool p_IsOpen, bool p_IsState = false, bool p_LuckIsOpen = false);
  void NeedTools();
  void NeedNebulaTower();

  void OpenTimeUpMastery(float p_Dt);
  void OpenTimeUpStar(float p_Dt);
  void OpenTimeUpStarSecond(float p_Dt);
  void OpenTimeUp(float p_Dt);

  void BuildTimerEnd();

  void RefreshLabelDes(const GString &p_Str);
  void IsConditionMet(bool p_IsMet);
  bool GetIsMet(){ return _IsMet; }
};
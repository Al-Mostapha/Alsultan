#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/Building/BuildingTips/BuildingTips.Type.h"
#include "UIBuildingTipButton.h"

class UIBuildingTipPanel : public UIBaseView
{
  CREATE_FUNC(UIBuildingTipPanel);
  CreateUIPanel(UIBuildingTipPanel);
  CreateUICCSView(UIBuildingTipPanel);
public: 

  static float ACTION_TIME ;
  static float TIME_DELAY_INIT;
  static int32 tag_act_init_view;
  static int32 tag_act_single_btn;
  static int32 tag_act_tip_show_end;
  static UIBuildingTipPanel* Create();
  int32 _RelyBuildBtnId = 1;
  EBuilding _RelyBuildCfgId = EBuilding::None;
  EBuildingIndex _RelyBuildIid = EBuildingIndex::None;
  int32 _RelyBuildUId = 1;
  float _CircleRadius = 260;
  class IBuilding *_RelyBuildEntity = nullptr;
  float _CircleOffsetNormal = 170;
  float _CircleOffsetCooling = 115;
  float _CircleOffsetY = _CircleOffsetNormal;

  class Sprite *_CircleFrameBg;
  ui::ImageView *_BuildingNameFrame;
  ui::Text *_LabelBuildName;
  GVector<UIBuildingTipButton *> _ButtonList;
  // self.tbBtnInuse = {}
  // self.tbBtnNotUse = {}
  void CreateUI();
  void Ctor() override;
  void SetRelyBuildBtnId(int32 p_Tag);
  void SetRelyBuildUId(int32 p_Tag);
  void SetRelyBuildCfgId(EBuilding p_Building);
  void SetRelyBuildIid( EBuildingIndex p_Index);
  void SetRelyBuildEntity(class IBuilding *);
  void InitView();
  void RecycleAllBtns();
  void DelayInitView();
  void HideTip();
  GHashMap<EBuildingTips, bool> FillBtnOpList(GHashMap<EBuildingTips, bool> pOpList, GVector<EBuildingTips> pBaseConfig);
  GHashMap<EBuildingTips, bool> FillBtnOpList(GHashMap<EBuildingTips, bool> pOpList, const GString &pBaseConfig);
  GVector<UIBuildingTipButton *>GetButtonArrayByOpList(GHashMap<EBuildingTips, bool> pTipsHash);
  UIBuildingTipButton *CreateButtonByOpType(EBuildingTips p_Tip);
  void RearrangeBtnByCircle(GVector<UIBuildingTipButton *> p_BtnList);
  bool CheckBuildMastery(EBuilding pBuildingID, EBuildingState pState);
  bool CheckExclusiveVip();
  bool GetHasAnySpeedUpTool();
};
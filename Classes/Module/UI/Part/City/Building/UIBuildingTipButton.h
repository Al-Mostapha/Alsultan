#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/Building/BuildingTips/BuildingTips.Type.h"
#include "Module/Building/BuildingTips/BuildingTips.Handle.h"
#include "Module/UI/Panel/Building/Common/Info/UIBuildingInfoPanel.h"


class IBuilding;

class UIBuildingTipButton : public UIBaseView
{
public:
  CREATE_FUNC(UIBuildingTipButton);
  CreateUIPanel(UIBuildingTipButton);
  CreateUICCSView(UIBuildingTipButton);
public: 
  EBuildingTips _OpType = EBuildingTips::OpNone;
  IBuilding *_BuildEntity;
  bool  _IsActive;
  ui::Button *_Button;
  ui::ImageView *_Icon;
  ui::ImageView *_TextBgL;
  ui::ImageView *_TextBgR;
  Node *_TextTopBg;
  Node *_TextBg;
  Node *_TextBottomBg;
  Sprite *_IconSmall;
  ui::Text *_Text;
  ui::Text *_TextMiddle;
  ui::Text *_TextTop;
  ui::Text *_TextBottom;
  Sprite *_RedPoint;
  static UIBuildingTipButton* Create();
  void Ctor();
  void CreateUI();
  void InitWithData(EBuildingTips p_Tip, IBuilding *p_Building);
  void ShowLowGuideEffect(){}
  void ShowPremiumVipEffect(){}
  void BeginTime(){}
  void UpdateBoostGold(){}
  void UpdateBoostTool(){}
  void UpdateTime(){}
  void UpdateCastleGift(){}
  void BtnClickCallBack(Ref* p_Ref, Widget::TouchEventType p_Touch){
    BuildingTipsHandle::Get()->Handle(this, p_Touch, _OpType);
  }
};
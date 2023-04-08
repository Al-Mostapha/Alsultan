#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIBuildingInfoPanel : public UIBasePanel
{

  CREATE_FUNC(UIBuildingInfoPanel);
  CreateUIPanel(UIBuildingInfoPanel);
  CreateUICCSView(UIBuildingInfoPanel);

  bool _FirstRunWar;
  float _NamePosY;
  Node *_NodeTitle;
  Node *_NodeTop;
  Node *_NodeCenter;
  Node *_NodeBottom;
  Node *_NodeLeft;
  Node *_NodeNameBg;
  ui::Text *_LabelInfo;
  ui::Text *_LabelTitle;
  ui::Text *_LabelName;
  ui::Text *_LabelWarCur;
  ui::Button *_BtnMore;
  ui::Button *_BtnCancell;
  ui::ScrollView *_ScrollInfo;
  ui::ScrollView *_ScrollDes;
  ui::Text *_LabelDes;
  Node *_NodeWar;
  ui::ImageView *_ImgWarBg;
  Node *_NodeProgressBar;
  Node *_NodeEffect;
  Node *_EffectWar;
  ProgressTimer *_WarBarTo;
  ProgressTimer *_WarBarCur;
  Sprite *_IconWarCur;
  Sprite *_IconWarTo;
  ui::Text *_LabelWarPro;
  EBuildingIndex _BuildingIndex;
  EBuildingState _BuildingState;
  IBuilding *_Building;

  int32 _WarLvl;
  int32 _WarProgress;
  int32 _WarToLv;
  int32 _StarLvl;

  static int32 WELevelProMin;
  static int32 WELevelProMax;
  static int32 maxDemolishNum;
  
public: 
  static UIBuildingInfoPanel* Create();
  void Ctor() override;
  void InitData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
private:
  void UpdateState();
  void BtnMoreCallBack(Ref *p_Ref, ui::Widget::TouchEventType p_Touch);
  void BtnCancelCallBack(Ref *p_Ref, ui::Widget::TouchEventType p_Touch);
  void BuildQueueCallback(EventCustom *p_Event){}
  void CloseByBuildLock(EventCustom *p_Event){}
  void RefreshLabelDes(const GString &p_Label);
  Node *WarLvBarEffect();
  void InitWarView();
  void RefreshCancelStarBtn();
};
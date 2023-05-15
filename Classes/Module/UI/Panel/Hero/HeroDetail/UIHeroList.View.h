#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Hero/Hero.Enum.h"
#include "Module/UI/Part/Common/Frame/UICommonFramTitle.h"

class UIHeroListView : public UIBasePanel
{
  CREATE_FUNC(UIHeroListView);
  CreateUIPanel(UIHeroListView);
  CreateUICCSView(UIHeroListView);

  bool _Switcher;
  int _RankIndex;
  //   self.curClass = gHeroListViewAllClass
  EHeroClass _CurClass;
  EHeroSortType _CurSortType;
  GVector<ui::Button *> _Btns;
  //   self.tableSpare = {}
  GVector<GPair<EHeroID, Vec2>> _TableSingle;
  //   self.tableCheckBox = {}
  UICommonFramTitle *_NodeTitle;
  Node *_NodeTop;
  ui::Button *_BtnClass;
  ui::ScrollView *_Scroll;
  Node *_NodeHave;
  Node *_NodeNoHave;
  Node *_BottomNode;
  Node *_NodeSort;
  ui::Text *_TextFriendNum;
  ui::Text *_TxtNum;
  Node *_NodeChooseList;
  ui::ImageView *_ImageBorder;
  ui::Text *_TextChoose;
  ui::Button *_ButtonChoose;
  ui::Button *_ButtonPower;
  ui::Button *_ButtonCastle;
  ui::Button *_ButtonRare;
  ui::Button *_ButtonStory;
  Node *_NodeRed;
  ui::Text *_TextPoint;
  GVector<EHeroID> _HaveHeros;
  GVector<EHeroID> _NoHaveHeros;
  bool _InitScrollEvent = false; 
public:
  static UIHeroListView *Create();  
  void Ctor() override;
  void InitData(EHeroClass p_Class, EHeroSortType p_SortType, bool p_NoJump= false);
  void OnChooseClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnPowerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnCastleClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnRareClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnStoryClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void Show();
  void OnMessageListener();
  void InitBtns();
  void SetSwitcher();
  void BtnClassClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type, bool p_NodSound = true);
  void UpdateHeroStory(EventCustom *p_Event);
  void PrepareScrollData(bool p_NoJump);
  void CleanOld();
  void InitScrollList();
};
#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/Mail/Mail.Enum.h"

class UIMailScrollView : public UIBaseView
{

  CREATE_FUNC(UIMailScrollView);
  CreateUIPanel(UIMailScrollView);
  CreateUICCSView(UIMailScrollView);

  int32 _TimeCount = 1;
  int32 _TimeDelta = 6;
  int32 _NextIndex = 1;
  int32 _TopPadding = 0;
  int32 _PaddingXLoadingSprite = 25;
  int32 _HeightNotice = 52;
  int32 _HeightEnableNotice = 55;
  int32 _CellHeight = 132;
  int32 _HeightTopAutoScroll = 100;
  bool _IsRequesting = true;
  bool _HasMore = false;
  EMailSetType _MailSetType = EMailSetType::None;
  const char *_MailSetKey = "key";
  // self.recycledList = {}
  // self.itemsData = {}
  ui::ScrollView *_ScrollView = nullptr;
  ui::Text *_LabelNotice = nullptr;
  Sprite *_LoadingSprite = nullptr;
  Scheduler *_TimeHandler = nullptr;

public: 
  static UIMailScrollView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
  void ScrollEventCallBack(Ref *p_Sender, ui::ScrollView::EventType p_Type){}
  void TurnJumpRedPointBy6Second(float p_Delta){}
};
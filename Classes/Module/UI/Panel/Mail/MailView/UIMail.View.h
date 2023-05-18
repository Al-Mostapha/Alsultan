#pragma once
#include "UIMailScroll.View.h"
#include "Module/Mail/Mail.Enum.h"
#include "Module/UI/Part/Common/Frame/UICommonFramTitle.h"
#include "Module/UI/Part/Common/Input/UICommonDropDownBox.h"

struct RMailInitData{

};

class UIMailView : UIBasePanel{
  CREATE_FUNC(UIMailView);
  CreateUIPanel(UIMailView);
  CreateUICCSView(UIMailView);

  GVector<Node *> _NodeTabs;
  float _JudgeHMove = 3 * TOUCH_MOVED_ERROR_VALUE;
  float _JudgeVMove = 3 * TOUCH_MOVED_ERROR_VALUE;
  int32 _TabIndex = 0;
  const char *_MailSetKey = "key";
  EMailSetType _MailSetType = EMailSetType::INFO_MAIL;
  UICommonFramTitle *_Title = nullptr;
  UIMailScrollView *_ScrollView = nullptr;
  ui::Layout *_TouchPanel = nullptr;
  Node *_EmptyTipNode = nullptr;
  ui::Text *_TextEmptyTip = nullptr;
  ui::ScrollView *_ScrollTab = nullptr;
  EBattelMailType _BattleMailType = EBattelMailType::None;
  UICommonDropDownBox *_DropDownBox = nullptr;
  ui::Button *_BtnDelet = nullptr;
  ui::Button *_BtnReadAndReceive = nullptr;

public:
  static UIMailView* Create();
  void Ctor() override ;
  void Show();
  void InitWithData(RMailInitData *p_InitData = nullptr);
  void CreateRedPointLayer(){}
  void OnSelDropDownBox(int32 p_Tag){}
  void OnTouchPanel(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void OnBottomMenuEvent(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}

};
#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"
#include "UICollegeScrollSingle.h"

class UICollegeWaitSingle : public UIBasePanel
{
  CREATE_FUNC(UICollegeWaitSingle);
  CreateUIPanel(UICollegeWaitSingle);
  CreateUICCSView(UICollegeWaitSingle);
  
  Node *_NodeState1;
  Node *_NodeState2;
  ui::Text *_TextName;
  ui::Text *_TextPower;
  ui::Button *_ButtonSub;
  UICollegeScrollSingle *_CCSWait;

public: 
  static UICollegeWaitSingle* Create();
  void Ctor() override;
  void InitWidget();
  void InitData(EScience);
  void SetStateWait(){}
  void SetStateFree(){}
  void RefrehState();
  void BtnSubClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
};
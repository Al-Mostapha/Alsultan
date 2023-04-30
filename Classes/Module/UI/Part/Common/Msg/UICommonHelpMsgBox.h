#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

struct RStyleFormat{
  TextHAlignment _Float = TextHAlignment::LEFT;
  TextHAlignment _Align = TextHAlignment::LEFT;
  bool _AddLine = false;
  bool _CloseBtn = false;
  bool _Title = false;
  int32 _ActivityId = 0;
};

class UICommonHelpMsgBox : public UIBasePanel
{
  
  private:
  CREATE_FUNC(UICommonHelpMsgBox);
  CreateUIPanel(UICommonHelpMsgBox);
  CreateUICCSView(UICommonHelpMsgBox);

  
public: 
  static UICommonHelpMsgBox* Create();
  void Ctor() override ;
  void InitData(){}
  void SetMsg(const GString &p_Msg, const RStyleFormat &p_Style){}
};
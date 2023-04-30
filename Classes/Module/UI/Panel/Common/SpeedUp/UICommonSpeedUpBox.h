#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class ITask;

class UICommonSpeedUpBox : public UIBasePanel
{

  CREATE_FUNC(UICommonSpeedUpBox);
  CreateUIPanel(UICommonSpeedUpBox);
  CreateUICCSView(UICommonSpeedUpBox);
  
public: 
  static UICommonSpeedUpBox* Create();
  void Ctor() override;
  void InitData(GString p_Msg, const GFunc<void(EMsgBoxCallBack)> &p_CB, ITask *p_Q, const GHashMap<GString, GString> &p_ArgV){}
  void InitWidget();
};
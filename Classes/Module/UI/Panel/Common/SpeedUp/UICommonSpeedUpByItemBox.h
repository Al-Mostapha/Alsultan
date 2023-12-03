#pragma once
#include "Base/Type/XFunction.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

enum class ETask;
class UICommonSpeedUpByItemBox : public UIBasePanel
{

  CREATE_FUNC(UICommonSpeedUpByItemBox);
  CreateUIPanel(UICommonSpeedUpByItemBox);
  CreateUICCSView(UICommonSpeedUpByItemBox);
  
public: 
  static UICommonSpeedUpByItemBox* Create();
  void Ctor() override;
  void InitData(ETask, GFunc<void(EMsgBoxCallBack)>){}
  void InitWidget();
};
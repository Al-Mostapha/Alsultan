#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Army/Army.Enum.h"


class UIDissolveSoldiersView : public UIBasePanel
{

  CREATE_FUNC(UIDissolveSoldiersView);
  CreateUIPanel(UIDissolveSoldiersView);
  CreateUICCSView(UIDissolveSoldiersView);

  
public: 
  static UIDissolveSoldiersView* Create();
  void InitData(EArmy, ETrainType){}
  void Ctor() override;
};
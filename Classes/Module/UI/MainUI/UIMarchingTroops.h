#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIMarchingTroops : public UIPanelBase
{

private:
  CREATE_FUNC(UIMarchingTroops);
public:
  UIMarchingTroops(){};
  ~UIMarchingTroops(){};
  void InitPanel() override{};
  void Show() override {};
  static UIMarchingTroops *Create() {return create();};
};

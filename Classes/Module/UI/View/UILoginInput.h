#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"

class UILoginInput : public UIBasePanel
{
public:
  static UILoginInput *Create(){
    return nullptr;
  };
  void Ctor(){};
  void SetModel(int32 p_Model){}
};



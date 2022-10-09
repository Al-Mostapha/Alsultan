#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeBuildingBase.h"


class UIMatrialFactoryView : public UIPanelBase
{

private:

public:
  UIMatrialFactoryView(){};
  ~UIMatrialFactoryView(){};
  void InitPanel() override{};
  void Show() {};
  static UIMatrialFactoryView *Create() {return create();};
  CREATE_FUNC(UIMatrialFactoryView);

};



#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonSharePic : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonSharePic);
public:
  UICommonSharePic(){};
  ~UICommonSharePic(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(RenderTexture *p_Textrure, int32 p_Type){}
  static UICommonSharePic *Create() {return create();};
};



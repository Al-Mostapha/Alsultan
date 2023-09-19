#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"

struct RAnniversaryFlamFireInit{
  int32 _FireNum;
  GString _OwerName;
  int32 _CreateUid;
  int32 _FlameStage;
};

class UIAnniversaryFlameExplainView : public UITouchBaseView{
  CREATE_FUNC(UIAnniversaryFlameExplainView);
  CreateUIPanel(UIAnniversaryFlameExplainView);
  CreateUICCSView(UIAnniversaryFlameExplainView);
public: 
  static UIAnniversaryFlameExplainView* Create();
  void InitData(const RAnniversaryFlamFireInit &pData);
};
#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "Module/Guild/Alliance.Type.h"

class UIAllianceBuildNoticeView : public UITouchBaseView
{
CREATE_FUNC(UIAllianceBuildNoticeView);
CreateUIPanel(UIAllianceBuildNoticeView);
CreateUICCSView(UIAllianceBuildNoticeView);
public:
  static UIAllianceBuildNoticeView* Create();
  void Ctor() override;
  void InitData(int32 pBuildID, int32 pAID, int32 pKID);
};
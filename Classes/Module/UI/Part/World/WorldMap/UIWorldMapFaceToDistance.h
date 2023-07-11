#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapFaceToDistance : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapFaceToDistance);
public:
  static UIWorldMapFaceToDistance *Create();
  void Ctor() override;
  void AddSubViews() override;
  void UpdateData(int32 pDistance){}
  void SetArrowRotation(float pRotation){}
};



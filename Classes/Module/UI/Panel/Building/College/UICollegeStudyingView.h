#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "UICollegeScrollView.h"
#include "Module/Science/Science.Enum.h"
#include "Module/UI/Part/Common/Frame/UICommonFramTitle.h"

class UICollegeStudyingView : public UIBasePanel
{
  CREATE_FUNC(UICollegeStudyingView);
  CreateUIPanel(UICollegeStudyingView);
  CreateUICCSView(UICollegeStudyingView);
  
  EScienceType _Type = EScienceType::Resource;
  Node *_NodeTop = nullptr;
  UICommonFramTitle *_NodeTitle = nullptr;
  Node *_SizeImageShadow = nullptr;
  ui::ImageView *_ImageL = nullptr;
  ui::ImageView *_ImageR = nullptr;
  Node *_SizeImageBase = nullptr;
  ui::Button *_BtnCloseRight = nullptr;
  UICollegeScrollView *_Scroll = nullptr;
public: 
  static UICollegeStudyingView* Create();
  void Ctor() override;
  void InitData(EScienceType);
  void JumpToTechnologyByID(EScience p_ScienceID);
};
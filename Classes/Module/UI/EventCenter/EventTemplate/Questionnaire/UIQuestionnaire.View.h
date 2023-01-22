#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeGlobal.h"
#include "Questionnaire.Ctrl.h"
#include "Module/UI/UICCSView.h"

class UIQuestionnaireView : UIBaseView{
  CREATE_FUNC(UIQuestionnaireView);
  CreateUIPanel(UIQuestionnaireView);
  CreateUICCSView(UIQuestionnaireView);
public:
  static UIQuestionnaireView* Create();
  void Show();
};
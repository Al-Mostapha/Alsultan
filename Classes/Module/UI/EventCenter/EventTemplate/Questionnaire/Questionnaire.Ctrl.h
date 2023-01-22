#pragma once
#include "Include/IncludeBase.h"

class QuestionnaireCtrl{
  public:
    static QuestionnaireCtrl *Get();
    void ReqGetQuestData();
    int32 GetReceiveStatusAndNum();
};
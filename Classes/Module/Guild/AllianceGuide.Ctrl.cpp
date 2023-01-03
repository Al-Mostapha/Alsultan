#include "AllianceGuide.Ctrl.h"

AllianceGuideCtrl *AllianceGuideCtrl::Get()
{
  static AllianceGuideCtrl *s_AllianceGuideCtrl = new AllianceGuideCtrl();
  return s_AllianceGuideCtrl;
}

bool AllianceGuideCtrl::IsShowEnterPoint()
{
  return true;
}
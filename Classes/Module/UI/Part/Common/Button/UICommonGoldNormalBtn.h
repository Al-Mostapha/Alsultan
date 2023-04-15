#pragma once 
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/CityResource/Resource.Enum.h" 

class UICommonGoldNormalBtn : public UIBasePanel
{
public:
  struct RInitDataParm{
    GString _Text;
    GString _Title;
    GString _Icon;
    int32 _Gold;
  };

  enum class EShowType{
    Normal = 0,
    Gold = 1,
    Resource = 2,
    Item = 3
  };

private:
  CREATE_FUNC(UICommonGoldNormalBtn);
  CreateUIPanel(UICommonGoldNormalBtn);
  CreateUICCSView(UICommonGoldNormalBtn);
public:

  static UICommonGoldNormalBtn *Create();
  void Ctor() override;
  void InitData(RInitDataParm p_Parm, EShowType p_ShowType);
  void SetGoldText(const GString &p_Gold){}
  void SetTitleStr(const GString &p_Str){}
};

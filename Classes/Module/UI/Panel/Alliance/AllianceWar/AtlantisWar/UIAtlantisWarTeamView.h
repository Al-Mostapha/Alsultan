#pragma once
#include "Module/UI/UICCSView.h"

class UIAtlantisWarTeamView : public UIBaseView
{
CREATE_FUNC(UIAtlantisWarTeamView);
CreateUIPanel(UIAtlantisWarTeamView);
CreateUICCSView(UIAtlantisWarTeamView);
public:
  void Show();
  static UIAtlantisWarTeamView *Create();

};

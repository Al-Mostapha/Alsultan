#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

struct RAllianceMemberInit{
  Vec2 _InviteMoveCityPos;
};

class UIAllianceMemberList : public UIBasePanel
{

  CREATE_FUNC(UIAllianceMemberList);
  CreateUIPanel(UIAllianceMemberList);
  CreateUICCSView(UIAllianceMemberList);

  
public: 
  static UIAllianceMemberList* Create();
  void Ctor() override;
  void InitData(int32 pAID = 0, const RAllianceMemberInit &pData = {});
  void InitWidget();
};
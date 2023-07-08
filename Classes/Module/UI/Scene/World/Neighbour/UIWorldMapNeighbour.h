#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldMap/WorldMap.Type.h"



class UIWorldMapNeighbour : public UIBasePanel
{
  CREATE_FUNC(UIWorldMapNeighbour);
  CreateUIPanel(UIWorldMapNeighbour);
  CreateUICCSView(UIWorldMapNeighbour);
public: 
  GVector<Node *> _NodeKingdomList;

  static UIWorldMapNeighbour* Create();
  void Ctor() override;
};
#pragma once
#include "IWorldMap.Com.h"

class UIWorldMapTroopsDetailsView;

class WorldMapComButton : public IWorldMapComponent
{
public:
  bool _IsReqClosestBuild;


    UIWorldMapTroopsDetailsView *_CurrentTroopBindingPanel = nullptr;

  void Init() override;
  void OnMessageListener() override;
  void Ctor() override;

  void TipButtonTouchCall(EventCustom *pEvent);
  void RemoveTroopBindingPanel(EventCustom *pEvent);
  void ServerMessage_reqClosestBuild(EventCustom *pEvent);
  void ServerMessage_LordInfo(EventCustom *pEvent);
  void ServerMessage_AllianceBuildInfo(EventCustom *pEvent);
};
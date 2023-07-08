#pragma once
#include "IWorldMap.Com.h"
#include "ui/CocosGUI.h"

class UITimerLabel;
class WorldMapComNormal : public IWorldMapComponent
{
public:
  ui::Button *_BtnMonsterSearch = nullptr;
  Sprite *_SeaMonsterRedPoint = nullptr;
  Sprite *_SpMonsterBg = nullptr;
  Sprite *_SpMonsterLock = nullptr;
  Node *_NodeParticle = nullptr;
  UITimerLabel *_LabelLockTime = nullptr;
  Node *_EffectMonster = nullptr;

  void Init() override;
  void OnMessageListener() override;
  void Relogin() override;
  void Ctor();
  void BtnMonsterSearchCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void MonsterSearchLock(EventCustom *p_Event);
  void ShowOrHideGuideView(EventCustom *p_Event);
  void JudgeOpen(EventCustom *p_Event);
};
#pragma once
#include "Base/Type/XTuple.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBaseView.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Module/City/CityBuilding/CommandHall/CommandHall.Enum.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Floor/Troops/WorldMapMoveLine.h"
#include "Module/UI/Panel/World/WorldMap/Floor/UIWorldMapEmoji.h"

struct RMoveTimeSpan
{
  GTime _Time = 0;
  float _DistancePrecent = 0.f;
};

struct LRMoveData
{
  Vec2 _Point;
  GTime _Time;
};

struct RMoveLineUserData{
  int32 _PlayerID = 0;
  bool _IsMainQueue = true;
  bool _IsRecall = false;
  bool _IsLegendLord = false;
  bool _IsLegendLordForSep = false;
  EWorldMapCastleEffectID _EffectId = EWorldMapCastleEffectID::None;
  bool _HasJoin = false;
  bool _IsNOClick = false;
  int32 _LeagueID = 0;
  EMapMoveLineType _MoveLineType = EMapMoveLineType::None;
  EMapMoveLineColor _MoveLineColor = EMapMoveLineColor::None;
  EMapMoveLineModel _MoveLineModel = EMapMoveLineModel::None;
  EWorldMapCastleEffectID _MarchArmyEffectId = EWorldMapCastleEffectID::None;
  int32 _Emoji = 0;
  EMapMoveLineStatusType _MatrixState = EMapMoveLineStatusType::Rally;
  int32 _OrgQueueId = 0;
  EMapMoveLineServerType _ToObjectType = EMapMoveLineServerType::None;
  ECommandHallTaskType _CommandHallTaskType = ECommandHallTaskType::None;
};

struct RMoveTimeData{
  GVector<RMoveTimeSpan> _MoveTimeSpan;
  GTime _CurrentMoveTime = 0.f;
};

class WorldMapTroopInstance : public UIBaseView/**, virtual public IWorldMapInstance*/
{

  CREATE_FUNC(WorldMapTroopInstance);
  CreateUIPanel(WorldMapTroopInstance);
  CreateUICCSView(WorldMapTroopInstance);



public: 
  int32 _PlayerID = 0;
  int32 _SourceID = 0;
  int32 _MoveLineID  = 0;
  int32 _OrgQueueId  = 0;
  int32 _LeagueID = 0;
  int32 _EmojiID = 0;
  int32 _Emoji = 0;
  int32 _CurTimerNum = 0;
  int32 _CurTimerMax = 0;

  bool _IsMainQueue = true;
  bool _IsRecall = false;
  bool _IsKing = false;
  bool _IsLegendLord = false;
  bool _IsLegendLordForSep = false;
  bool _HasJoin = false;

  EWorldMapCastleEffectID _MarchArmyEffectId = EWorldMapCastleEffectID::None;
  EMapMoveLineType _MoveLineType = EMapMoveLineType::AttackLord;
  EMapMoveLineColor _MoveLineColor = EMapMoveLineColor::White;
  EMapMoveLineModel _MoveLineModel = EMapMoveLineModel::GoOut;
  EWorldMapCastleEffectID _EffectId = EWorldMapCastleEffectID::None;
  EMapMoveLineServerType _ToObjectType = EMapMoveLineServerType::None;
  ECommandHallTaskType _CommandHallTaskType = ECommandHallTaskType::None;
  WorldMapMoveLine *_MoveLine = nullptr;
  UIWorldMapEmoji *_WorldMapEmoji = nullptr;
  GVector<RMoveTimeSpan> _MoveTimeSpan;
  GTime _CurrentMoveTime = 0;
  GTime _TotalMoveTime = 0;
  bool _IsLod = false;
  EMapMoveLineStatusType _MatrixState = EMapMoveLineStatusType::Rally;
  Vec2 _BeginPoint;
  Vec2 _EndPoint;
  Vec2 _BeginTilePoint;
  Vec2 _EndTilePoint;
  RMoveLineArmyData _ArmyData;

  Node *_SoliderNode = nullptr;
  Sprite *_LodNode = nullptr;
  Sprite *_SoldierLod = nullptr;
  RMoveLineUserData _UserData;
  GOpt<Rect> _ClickRect;
  Rect _Rect;

  static WorldMapTroopInstance* Create(Size pSize);
  void Ctor() override;
  void InitData(
    Vec2 pBeginPoint, Vec2 pEndPoint, Vec2 pBeginTilePoint, 
    Vec2 pEndTilePoint, RMoveLineArmyData pData);
  void onExit() override;
  void BeginMove(float pDelayTime, bool pUpdate);
  void BeginWork();
  void FinishWork(float pDelayTime);
  GTuple<GVector<LRMoveData>, float> GetMapMoveDataArray();
  void ViewOnClick(Ref *pSender, Widget::TouchEventType type);
  void OnMovelineClick();
  void SetUserData(const RMoveLineUserData &pData);
  void SetMoveTimeData(const RMoveTimeData &pData);
  void SetMoveLinePoints(Vec2 beginPoint, Vec2 endPoint){
    _BeginPoint = beginPoint;
    _EndPoint = endPoint;
  }
  void SetMoveLineColor(EMapMoveLineColor pColor);
  void SetMatrixState(EMapMoveLineStatusType pState, float pDelayTime = 0.f, bool pUpdate = false);
  bool CheckClickMoveLine(Vec2 pPos);
  Size GetTroopContentSize(){ return UIBaseView::getContentSize(); }
  void ToggleClickPriority();
  void InitCheckVisible();
  void UpdateCheckVisible();
  void SetSoliderVisible(bool pIsVisible);
  void RemoveSoliderNode();
  void SetEmojiID(int32 pEmojiID);
  bool IsHasEmoji();
  bool CanHasEmojiOperator(int32 pPlayerID);
  void AddEmoji(int32 pEmojiID, GOpt<Vec2> pPos = {});
  void ShowEmoji(int32 pEmojiID);
  void HideEmoji();
  void DoScaleZoom(float pScale){
    if(_LodNode) 
      _LodNode->setScale(pScale);
  }
  void UpdateModelState(float pScale);
  void CreateTroopIcon(float pScale = 0);
  bool SwitchMoveLineModel(bool pIsLod, bool pForce = false);
  bool IsSelfTroop(int32 pPlayerID);

  // void OnMessageListener() override{};
  // void OnEnterOther() override{};
};
#pragma once
#include "ui/cocosGUI.h"
#include "IWorldMap.Com.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

class UIWorldMapBottomPoint;
class UIWorldMapFaceToDistance;

class WorldMapComUI : public IWorldMapComponent{
public:
  EKingdomClassType _MapClassType;
  Vec2 _DisplayCenterPoint;
  Size _TileSize;
  Vec2 _MyCityTilePoint;
  bool _IsHideDis;
  int32 _MyKindomID;
  Vec2 _MapViewCenterPoint;
  Node *_NodeBottom;
  UIWorldMapBottomPoint *_BottomPointNode;
  UIWorldMapFaceToDistance *_FaceToDistanceNode;
  ui::Button *_ButtonWorldResouce;
  ui::Button *_ButtonFavorite;
  ui::ImageView *_ButtonFavoriteStar;
  ui::Button *_ButtonMyCity;

  void Ctor();
  void Init() override;
  void OnMessageListener() override; 
  void Relogin() override;
  void ResetData() override;
  void BottomPointOnClick(Ref* pSender, ui::Widget::TouchEventType pType);
  void ButtonWorldResouceCall(Ref* pSender, ui::Widget::TouchEventType pType);
  void ButtonFavoriteCall(Ref* pSender, ui::Widget::TouchEventType pType);
  void ButtonMyCityCall(Ref* pSender, ui::Widget::TouchEventType pType);
  void FaceToDistanceOnClick(Ref* pSender, ui::Widget::TouchEventType pType);

  void ServerMessage_LeagueMembersInfo(EventCustom *pEvent);
  void ServerMessage_AddBookMark(EventCustom *pEvent);
  void ServerMessage_UpdateSelfPoint(EventCustom *pEvent);
  void ShowOrHideGuideView(EventCustom *pEvent = nullptr);
  void ShowOrHideDistance(EventCustom *pEvent);
  void UpdateFaceToDistance(EventCustom *pEvent = nullptr);
};

#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "UIWorldMap.TipButton.h"

class WorldMapCell;

struct RCollectSpan{
  int32 _CostTime;
  int32 _CurrentSourceNum;
  int32 _CurrentCollectSpeed;
};

class UIWorldMapTip : public UIBaseView
{

  CREATE_FUNC(UIWorldMapTip);
  CreateUIPanel(UIWorldMapTip);
  CreateUICCSView(UIWorldMapTip);

  
public: 

  Vec2 _TilePoint;
  Vec2 _TilePointShow;
  WorldMapCell *_WorldMapCell;
  ui::Text *_TilePointText;
  ui::ImageView *_TilePointImage;
  GString _CollectTimer;
  GString _WajueTimer;
  GVector<RCollectSpan> _CollectSpanArray;
  int32 _CollectSpanTime;
  int32 _CollectSpanIndex;
  int32 _ResourceCount;
  int32 _CollectSpeed;
  int32 _WajueCount;
  int32 _WajueSpeed;

  ui::Text *_ResourceCountText;
  ui::ImageView *_ResourceIconImg;
  ui::ImageView *_PlayerNameBg;
  ui::Text *_PlayerNameLable;
  ui::Text *_MoveTypeNameLable;
  Sprite *_FrameProtectTime;
  GVector<UIWorldMapTipButton*> _TipButtonsArray;
  GString _FavoriteName;
  bool _IsCanZhanling;
  //   self.msgTipsKey = nil
  ui::Button *_ButtonFavorites1;
  ui::Button *_ButtonFavorites3;
  ui::Button *_ButtonCopy;
  ui::Button *_BtnShare;
  ui::ImageView *_ImgCopyBg;
  //   self.mapInstance = nil
  int32 _KingdomID;
  bool _IsSelfKindom;
  bool _IsInWar;
  bool _InstanceKID;

  static UIWorldMapTip* Create(int32 p_KingdomID);
  void Ctor() override;
  void SetTilePoint(Vec2 p_TilePos);
  void SetWorldMapCell(WorldMapCell *p_Cell);
  void SetFavoriteName(const GString &p_Name);
  void SetIsCanZhanling(bool p_IsCanZhanling, GString p_MsgTipsKey);
  void InitMapData(Node *p_TileInstance);
  void InitMoveLineData();
  void SetPosition(Vec2 p_CoverShowPoint);

  void ButtonTilePointCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void ButtonFavoritesCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void ButtonShareCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void ButtonCopyCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

};
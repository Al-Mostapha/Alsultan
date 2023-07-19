#include "UIWorldMap.Tip.h"
#include "Base/Common/Common.Teml.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Player/Player.Top.h"

UIWorldMapTip *UIWorldMapTip::Create(int32 p_KingdomID)
{
  auto lPanel = Create("UiParts/Panel/World/WorldMap/Floor/worldMapTip.csb");
  lPanel->_KingdomID = p_KingdomID ? p_KingdomID : PlayerTop::Get()->GetMapID();
  return lPanel;
}

void UIWorldMapTip::Ctor(){
  // self.tilePointText = SoraDGetChildByName(self, "Text_point")
  _TilePointText = GBase::DGetChildByName<ui::Text *>(this, "Text_point");
  _TilePointText->setTouchEnabled(false);
  _TilePointText->setTouchScaleChangeEnabled(true);
  _TilePointText->addTouchEventListener(CC_CALLBACK_2(UIWorldMapTip::ButtonTilePointCall, this));

  _TilePointImage = GBase::DGetChildByName<ui::ImageView *>(this, "Image_textPoint_bottom");
  _TilePointImage->setVisible(false);
  
  _ResourceCountText = GBase::DGetChildByName<ui::Text *>(this, "Text_resourceNum");
  _ResourceCountText->setTouchEnabled(false);
  
  _ResourceIconImg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_resourceIcon");
  _ResourceIconImg->setScale(0.7f);
  _ResourceIconImg->setVisible(false);
  
  _PlayerNameBg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_NameBg");
  _PlayerNameBg->setVisible(false);
  _PlayerNameLable = GBase::DGetChildByName<ui::Text *>(this, "Text_Name");
  _PlayerNameLable->setVisible(false);
  _MoveTypeNameLable = GBase::DGetChildByName<ui::Text *>(this, "Text_type");
  _MoveTypeNameLable->setVisible(false);
  _FrameProtectTime = GBase::DGetChildByName<Sprite *>(this, "frame_map_pTime");
  _FrameProtectTime->setVisible(false);
  _IsCanZhanling = true;
  // self.msgTipsKey = nil

  _ButtonFavorites1 = GBase::DGetChildByName<ui::Button *>(this, "Button_favorite1");
  _ButtonFavorites3 = GBase::DGetChildByName<ui::Button *>(this, "Button_favorite3");
  if(_ButtonFavorites1 && _ButtonFavorites3){
    _ButtonFavorites1->setVisible(false);
    _ButtonFavorites3->setVisible(false);
    _ButtonFavorites1->addTouchEventListener(CC_CALLBACK_2(UIWorldMapTip::ButtonFavoritesCall, this));
    _ButtonFavorites3->addTouchEventListener(CC_CALLBACK_2(UIWorldMapTip::ButtonFavoritesCall, this));
  }
  
  auto lInPyramidWar = WorldMapDefine::Get()->IsInWar();
  if(lInPyramidWar){
    _ButtonFavorites1->loadTextures("icon_battlefield_collect.png", "icon_battlefield_collect.png", "icon_battlefield_collect.png", ui::Widget::TextureResType::PLIST);
  }
  
  ui::Button *_ButtonCopy = GBase::DGetChildByName<ui::Button *>(this, "Button_copy");
  ui::ImageView *_ImgCopyBg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_copyBg");
  if(_ButtonCopy){
    _ButtonCopy->setVisible(false);
    _ImgCopyBg->setVisible(false);
    _ButtonCopy->setPositionY(-140);
    _ButtonCopy->addTouchEventListener(CC_CALLBACK_2(UIWorldMapTip::ButtonCopyCall, this));
  }
  
  _BtnShare = GBase::DGetChildByName<ui::Button *>(this, "btn_share");
  _BtnShare->addTouchEventListener(CC_CALLBACK_2(UIWorldMapTip::ButtonShareCall, this));

  _IsSelfKindom = _KingdomID == PlayerTop::Get()->GetMapID();
  _IsInWar = _KingdomID != PlayerTop::Get()->GetKingdomID();
  _InstanceKID = _KingdomID;
}



void UIWorldMapTip::SetTilePoint(Vec2 p_TilePos){}

void UIWorldMapTip::SetWorldMapCell(WorldMapCell *p_Cell){}

void UIWorldMapTip::SetFavoriteName(const GString &p_Name){}

void UIWorldMapTip::SetIsCanZhanling(bool p_IsCanZhanling, GString p_MsgTipsKey){}

void UIWorldMapTip::InitMapData(Node *p_TileInstance){}

void UIWorldMapTip::SetPosition(Vec2 p_CoverShowPoint){}

void UIWorldMapTip::ButtonTilePointCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}

void UIWorldMapTip::ButtonFavoritesCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}

void UIWorldMapTip::ButtonShareCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}

void UIWorldMapTip::ButtonCopyCall(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}

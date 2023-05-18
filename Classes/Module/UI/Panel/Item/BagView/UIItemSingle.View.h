#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Item/Item.Type.h"

class UIItemSingleView : public Node
{

  CREATE_FUNC(UIItemSingleView);
  bool _SingleIsMoved = false;
  bool _IsRechargeUse = false;
  // self.target = nil
  ui::Button *_BtnItem;
  Sprite *_ImgFrame;
  Sprite *_SpriteNew;
  Sprite *_SpriteNumBg;
  ui::Text *_LabNum;
  // self.item = nil
  // self.itemsManagerHandle = nil
  // self.itemClickCallback = nil
public: 
  struct {
    RClassifyItem _ItemData;
    operator bool() const { return true; }
  } _TableItem;
  static UIItemSingleView* Create();
  void Ctor();
  void InitData(RClassifyItem, Vec2 );
  void InitWidget();
  void SetItemDelegate(std::function<void(UIItemSingleView *)> p_Delegate){}
  void SetScroll(ui::ScrollView *p_Scroll){}
  void SetNewVisible(bool p_Visible){}
  void AddItemUseEffect(bool){}

  void OnBtnItemClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
};
#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "UIItemSingle.Info.h"
#include "UIItemSingle.View.h"
#include "Base/Containers/HashMap.h"
#include "Module/Item/Item.Type.h"


class UIBagItemsView : public UIBasePanel
{

  CREATE_FUNC(UIBagItemsView);
  CreateUIPanel(UIBagItemsView);
  CreateUICCSView(UIBagItemsView);

  struct RItemsSingle{
    UIItemSingleView *_Point;
    Vec2 _Pos;
    RClassifyItem _Data;
    Vec2 _ItemPos;
    bool _Valid = true;
  };

  // timeLimitedItemCtrl:resetIndex()
  // self.tableItemsData = {}
  struct {
    GVector<RClassifyItem> _Data;
    int32 _BagCapacity;
  } _TableItemsData;
  // self.tableItemsSingle = {}
  GVector<RItemsSingle> _TableItemsSingle;
  GVector<UIItemSingleView *> _TableSpare;
  UIItemSingleView *_CurItem;
  // self.curItemID = nil
  EItemID _CurItemID = 0;
  bool _IsEffectRunning = false;
  ui::ScrollView *_Scroll;
  UIItemSingleInfo *_ItemInfo;
  GVector<Sprite *> _TableSpriteNew;
  // self.tableSpriteOne = {}
  // self.clickTab = {}
  GHashMap<EItemCategory, bool> _ClickTab;
  ui::Button *_BtnAll;
  ui::Button *_BtnRes;
  ui::Button *_BtnWar;
  ui::Button *_BtnBuf;
  ui::Button *_BtnOther;
  ui::Text *_TextTab0;
  ui::Text *_TextTab1;
  ui::Text *_TextTab2;
  ui::Text *_TextTab3;
  ui::Text *_TextTab4;
  ui::Button *_CurBtn;
  ui::ImageView *_LineLight;
  
public: 
  static UIBagItemsView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
  void RefreshBtnTextColor(ui::Button *btn);
  void UpdateData();
  void RecyclingAll();
  void ScrollEventCallBack(Ref *pSender, ui::ScrollView::EventType type){}
  void OnChangeClick(Ref *pSender, ui::Widget::TouchEventType type){}

  void UpdateScrollSize(float p_Line = 0.0f);
  void RefreshScroll();
  void InitTabNew();
  void CloseItem();
  void ClosedItemInfo();

  void SingleItemClick(UIItemSingleView *);
};
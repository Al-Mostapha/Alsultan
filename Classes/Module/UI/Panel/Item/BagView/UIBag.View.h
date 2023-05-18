#pragma once
#include "UIBagItems.View.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/Part/Common/Frame/UICommonFramTitle.h"
#include "Module/UI/Part/Common/Button/UICommonGoldTop.h"
class UIBagView : public UIBasePanel
{
  CREATE_FUNC(UIBagView);
  CreateUICCSView(UIBagView);
  CreateUIPanel(UIBagView);

  // self.tableItemsData = {}
  UICommonFramTitle *_Title;
  Node *_NodeTop;
  UICommonGoldTop *_NodeGold;
  ui::Button *_BtnShop;
  ui::Button *_BtnItems;
  UIBagItemsView *_BagItemsView;
  // self.bagShopView = nil
  Sprite *_IconNew;

  public:
    static UIBagView* Create();
    void Ctor() override;
    void OnBtnChangeClick(Ref *pSender, ui::Widget::TouchEventType type);

    void UpdateDiscount(EventCustom *event);
    void UpdateNewTag(EventCustom *event);
};
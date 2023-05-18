#include "UIBagItems.View.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Item/Item.Enum.h"
#include "Module/Item/Item.Ctrl.h"
#include "Module/Item/Config/ShopLt.Ctrl.h"

UIBagItemsView *UIBagItemsView::Create(){
  auto l_Panel = Create("UiParts/Panel/BagView/bagItemsView.csb");
  return l_Panel;
}

void UIBagItemsView::Ctor(){
  // timeLimitedItemCtrl:resetIndex()
  // self.tableItemsData = {}
  // self.tableItemsSingle = {}
  // self.tableSpare = {}
  // self.curItem = nil
  // self.curItemID = nil
  // self.isEffectRunning = false
  _IsEffectRunning = false;
  _Scroll = GBase::DGetChildByName<ui::ScrollView *>(this, "Size_ScrollView_bag");
  _Scroll->setContentSize(Size(620, GetPanelOffsetHeight() - 195));
  _Scroll->addEventListener(CC_CALLBACK_2(UIBagItemsView::ScrollEventCallBack, this));
  _ItemInfo = GBase::DGetExtendChildFromCCSByName<UIItemSingleInfo>(this, "CCS_itemSingleInfo_info");
  _ItemInfo->setVisible(false);
  // SoraDGetChildByName(self, "bg_tab"):setFillType(1)
  _BtnAll = GBase::DGetChildByName<ui::Button *>(this, "Button_right0");
  _BtnRes = GBase::DGetChildByName<ui::Button *>(this, "Button_right1");
  _BtnWar = GBase::DGetChildByName<ui::Button *>(this, "Button_right2");
  _BtnBuf = GBase::DGetChildByName<ui::Button *>(this, "Button_right3");
  _BtnOther = GBase::DGetChildByName<ui::Button *>(this, "Button_right4");
  _BtnAll->setPressedActionEnabled(false);
  _BtnRes->setPressedActionEnabled(false);
  _BtnWar->setPressedActionEnabled(false);
  _BtnBuf->setPressedActionEnabled(false);
  _BtnOther->setPressedActionEnabled(false);
  
  _TextTab0 = GBase::DGetChildByName<ui::Text *>(_BtnAll, "text_tab");
  _TextTab1 = GBase::DGetChildByName<ui::Text *>(_BtnRes, "text_tab");
  _TextTab2 = GBase::DGetChildByName<ui::Text *>(_BtnWar, "text_tab");
  _TextTab3 = GBase::DGetChildByName<ui::Text *>(_BtnBuf, "text_tab");
  _TextTab4 = GBase::DGetChildByName<ui::Text *>(_BtnOther, "text_tab");

  _BtnAll->setTag((int)EItemCategory::ALL);
  _BtnRes->setTag((int)EItemCategory::RESOURCE);
  _BtnWar->setTag((int)EItemCategory::WAR);
  _BtnBuf->setTag((int)EItemCategory::BUFF);
  _BtnOther->setTag((int)EItemCategory::Other);

  _BtnRes->loadTextureNormal("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnRes->loadTexturePressed("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnWar->loadTextureNormal("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnWar->loadTexturePressed("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnBuf->loadTextureNormal("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnBuf->loadTexturePressed("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnOther->loadTextureNormal("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _BtnOther->loadTexturePressed("bg_transparent.png", ui::Widget::TextureResType::PLIST);
  _TableSpriteNew.push_back(GBase::DGetChildByName<Sprite *>(_BtnRes, "Sprite_new"));
  _TableSpriteNew.push_back(GBase::DGetChildByName<Sprite *>(_BtnWar, "Sprite_new"));
  _TableSpriteNew.push_back(GBase::DGetChildByName<Sprite *>(_BtnBuf, "Sprite_new"));
  _TableSpriteNew.push_back(GBase::DGetChildByName<Sprite *>(_BtnOther, "Sprite_new"));
  _TableSpriteNew.push_back(GBase::DGetChildByName<Sprite *>(_BtnAll, "Sprite_new"));
  _TableSpriteNew[0]->setTag((int)EItemCategory::RESOURCE);
  _TableSpriteNew[1]->setTag((int)EItemCategory::WAR);
  _TableSpriteNew[2]->setTag((int)EItemCategory::BUFF);
  _TableSpriteNew[3]->setTag((int)EItemCategory::Other);
  _TableSpriteNew[4]->setTag((int)EItemCategory::ALL);
  _CurBtn = _BtnAll;
  _CurBtn->setTouchEnabled(false);
  _CurBtn->setBright(false);
  _TextTab0->setString(Translate::i18n("common_text_635"));
  _TextTab1->setString(Translate::i18n("common_text_123"));
  _TextTab2->setString(Translate::i18n("common_text_310"));
  _TextTab3->setString(Translate::i18n("common_text_311"));
  _TextTab4->setString(Translate::i18n("common_text_312"));
  RefreshBtnTextColor(_CurBtn);
  _LineLight = ui::ImageView::create("frame_item_checked.png", ui::Widget::TextureResType::PLIST);
  _LineLight->setScale9Enabled(true);
  _LineLight->setContentSize(Size(170, 170));
  _LineLight->setVisible(false);
  _LineLight->setPosition(Vec2(76, -75));
  _LineLight->retain();
  _BtnAll->addTouchEventListener(CC_CALLBACK_2(UIBagItemsView::OnChangeClick, this));
  _BtnRes->addTouchEventListener(CC_CALLBACK_2(UIBagItemsView::OnChangeClick, this));
  _BtnWar->addTouchEventListener(CC_CALLBACK_2(UIBagItemsView::OnChangeClick, this));
  _BtnBuf->addTouchEventListener(CC_CALLBACK_2(UIBagItemsView::OnChangeClick, this));
  _BtnOther->addTouchEventListener(CC_CALLBACK_2(UIBagItemsView::OnChangeClick, this));
  UpdateData();
}

void UIBagItemsView::RefreshBtnTextColor(ui::Button *p_Btn){
  
  auto l_ChooseColor = Color3B(255, 200, 100);
  auto l_UnChooseColor = Color3B(215, 195, 155);

  _TextTab0->setColor(l_UnChooseColor);
  _TextTab1->setColor(l_UnChooseColor);
  _TextTab2->setColor(l_UnChooseColor);
  _TextTab3->setColor(l_UnChooseColor);
  _TextTab4->setColor(l_UnChooseColor);

  if(_BtnBuf == p_Btn)
    _TextTab3->setColor(l_ChooseColor);
  else if(_BtnOther == p_Btn)
    _TextTab4->setColor(l_ChooseColor);
  else if(_BtnWar == p_Btn)
    _TextTab2->setColor(l_ChooseColor);
  else if(_BtnRes == p_Btn)
    _TextTab1->setColor(l_ChooseColor);
  else if(_BtnAll == p_Btn)
    _TextTab0->setColor(l_ChooseColor);
  _ClickTab[static_cast<EItemCategory>(p_Btn->getTag())] = true;

}

void UIBagItemsView::UpdateData(){

  auto l_Backpack = ItemCtrl::Get()->GetBackPack(EBackpackDef::PROPS);
  _TableItemsData._Data = l_Backpack->GetClassifyList(static_cast<EItemCategory>(_CurBtn->getTag()));
  _TableItemsData._BagCapacity = l_Backpack->GetShowUnitNum();
  RecyclingAll();
  for(auto iii  = 0; iii < _TableItemsData._Data.size(); iii++){
    _TableItemsSingle.push_back(RItemsSingle());
    _TableItemsSingle[iii]._Data = _TableItemsData._Data[iii];
    _TableItemsSingle[iii]._Valid = true;
  }

  if(_TableItemsData._Data.size() < MIN_BAG_CAPACITY){
    for(auto iii = _TableItemsData._Data.size(); iii < MIN_BAG_CAPACITY; iii++){
      _TableItemsSingle.push_back(RItemsSingle());
      _TableItemsSingle[iii]._Valid = false;
    }
  } else if( _TableItemsData._Data.size() % 4 != 0){
    for(auto iii = _TableItemsData._Data.size() + 1; iii < ceil(_TableItemsData._Data.size() / 4) * 4; iii++){
      _TableItemsSingle.push_back(RItemsSingle());
      _TableItemsSingle[iii]._Valid = false;
    }
  }
  
  UpdateScrollSize();
  RefreshScroll();
  InitTabNew();
  _IsEffectRunning = false;
  _ItemInfo->setVisible(false);
  CloseItem();
}

void UIBagItemsView::UpdateScrollSize(float p_Line){
  auto l_ScrollInner = _Scroll->getInnerContainer();
  auto l_OffsetY = l_ScrollInner->getPositionY();
  auto l_ScrollW = _Scroll->getContentSize().width;
  auto l_ScrollH = GMath::Max(std::ceil(float(_TableItemsSingle.size()) / 4.f) * 155 +
    (p_Line ? 230 : 0), _Scroll->getContentSize().height) + 15;
  for(auto iii = 1; iii <= _TableItemsSingle.size(); iii++){
    auto l_Index = iii % 4 == 0 ? 4 : iii % 4;
    auto l_Line = std::ceil(iii / 4.f) - 1;
    _TableItemsSingle[iii - 1]._ItemPos = Vec2(l_Index, l_Line);
    _TableItemsSingle[iii - 1]._Pos = Vec2(l_ScrollW - 155 * l_Index, l_ScrollH - l_Line * 155);
    if(p_Line && p_Line < l_Line)
      _TableItemsSingle[iii - 1]._Pos.y = l_ScrollH - l_Line * 155 - 230 - 15;
    else
      _TableItemsSingle[iii - 1]._Pos.y = l_ScrollH - l_Line * 155 - 15;
  }
  l_OffsetY = GMath::Min(0.f, l_OffsetY - (l_ScrollH - l_ScrollInner->getContentSize().height));
  _Scroll->setInnerContainerSize(Size(l_ScrollW, l_ScrollH));
  l_ScrollInner->setPositionY(l_OffsetY);
}

void UIBagItemsView::RefreshScroll(){
  auto l_ScrollInner = _Scroll->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_ScrollW = _Scroll->getContentSize().width;
  auto l_ScrollH = _Scroll->getContentSize().height;
  
  struct {
    float beginY;
    float endY;
  } l_TableShowH;
  l_TableShowH.beginY = GMath::Max(0.f, l_OffsetY - 0.5f * l_ScrollH);
  l_TableShowH.endY = l_OffsetY + 1.5f * l_ScrollH;

  auto l_Index = static_cast<EItemCategory>(_CurBtn->getTag());
  auto l_TableNewItems = ItemCtrl::Get()->GetNewItemInfoByType(l_Index);

  EItemID l_SameID = 0;
  for(auto iii = 0; iii < _TableItemsSingle.size(); iii++){
    auto v = _TableItemsSingle[iii];
    if(v._Point){
      if(v._Pos.y < l_TableShowH.beginY || v._Pos.y > l_TableShowH.endY){
        v._Point->setVisible(false);
        _TableSpare.push_back(v._Point);
        if(v._Point->_TableItem && v._Point->_TableItem._ItemData){
          auto l_ItemType = ShopLtCtrl::Get()->GetItemType(v._Point->_TableItem._ItemData._Id);
          if(l_ItemType == EItemType::TREASURE_CRYSTAL || l_ItemType == EItemType::PANDORABOX || l_ItemType == EItemType::TREASURE_MAP){
            if(v._Point->_TableItem._ItemData._IsLimitedItem){
              //    timeLimitedItemCtrl:addtLimitedItem(v.point.tableItem.itemData.id, v.point.tableItem.itemData.isLimitedItem)
            }else{
              //    timeLimitedItemCtrl:addtInUseLimitedItem(v.point.tableItem.itemData.id, v.point.tableItem.itemData.isInUseLimitedItem)
            }
            if(l_ItemType == EItemType::PANDORABOX){
              //    timeLimitedItemCtrl:addtBoxIndex(v.point.tableItem.itemData.id, v.point.tableItem.itemData.pandoraIndex)
            }
          }
        }
        v._Point = nullptr;
      }else{
        v._Point->setPosition(v._Pos);
      }
    } else if(l_TableShowH.beginY <= v._Pos.y && l_TableShowH.endY >= v._Pos.y){
      UIItemSingleView *l_SingleItem;
      if(_TableSpare.size() > 0){
        l_SingleItem = _TableSpare.back();
        _TableSpare.pop_back();
        l_SingleItem->setVisible(true);
      }else{
        l_SingleItem = UIItemSingleView::Create();
        l_SingleItem->SetItemDelegate(CC_CALLBACK_1(UIBagItemsView::SingleItemClick, this));
        l_SingleItem->SetScroll(_Scroll);
        _Scroll->addChild(l_SingleItem);
      }
      l_SingleItem->InitData(v._Data, v._ItemPos);
      l_SingleItem->setPosition(v._Pos);
      v._Point = l_SingleItem;
    }

    if(v._Point){
      v._Point->SetNewVisible(false);
      if(v._Data._Id && l_TableNewItems.Contains(v._Data._Id) && l_SameID != v._Data._Id){
        v._Point->SetNewVisible(true);
        l_SameID = v._Data._Id;
      }
      auto l_LightBorder = v._Point->getChildByName("lineLight");
      if(v._Data && _CurItemID && _CurItemID != v._Data._Id || !v._Data){
        if(l_LightBorder)
          l_LightBorder->setVisible(false);
        if(_CurItem)
          _CurItem->AddItemUseEffect(true);
      } else if(v._Data && _CurItemID && _CurItemID == v._Data._Id && l_LightBorder){
        l_LightBorder->setVisible(true);
      }
    }
  }
}

void UIBagItemsView::CloseItem(){
  ClosedItemInfo();
  _LineLight->setVisible(false);
  _LineLight->removeFromParentAndCleanup(false);
  //   self.curItem = nil
}

void UIBagItemsView::ClosedItemInfo(){

}

void UIBagItemsView::InitTabNew(){

}

void UIBagItemsView::RecyclingAll(){

}

void UIBagItemsView::InitData(){

}

void UIBagItemsView::InitWidget(){

}

void UIBagItemsView::SingleItemClick(UIItemSingleView *){
  CCLOG("UIBagItemsView::SingleItemClick");
}
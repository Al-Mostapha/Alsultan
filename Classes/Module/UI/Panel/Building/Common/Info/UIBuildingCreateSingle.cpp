#include "UIBuildingCreateSingle.h"
#include "Module/Building/Building.Read.h"
#include "Module/Item/Item.Read.h"
#include "Module/CityResource/Resource.Read.h"
#include "Module/Building/Building.Logic.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Science/Science.Ctrl.h"
#include "Base/Common/Common.Func.h"
#include "Module/CityResource/Resource.Ctrl.h"
#include "Module/Activity/LuckyBless/LuckyBless.Ctrl.h"
#include "Module/Effect/Effect.Ctrl.h"

UIBuildingCreateSingle *UIBuildingCreateSingle::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/Common/buildCreateSingle.csb");
  return l_Panel;
}

void UIBuildingCreateSingle::Ctor(){
  UIBasePanel::Ctor();
  _ImgIcon = GBase::DGetChildByName<ui::ImageView *>(this, "Image_icon");
  _LabelDes = GBase::DGetChildByName<ui::Text *>(this, "Text_des");
  _BtnJump = GBase::DGetChildByName<ui::Button *>(this, "Text_des");
  _ImgState = GBase::DGetChildByName<ui::ImageView *>(this, "Image_state");
  _SpriteLuckLine = GBase::DGetChildByName<Sprite *>(this, "Sprite_luckLine");
  _LabelLuckValue = GBase::DGetChildByName<ui::Text *>(this, "Text_luckValue");
  if(_BtnJump)
    _BtnJump->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateSingle::BtnJumpCallBack, this));
  _IsMet = false;
  _Timer = nullptr;
}

void UIBuildingCreateSingle::InitData(EBuildingCondType p_Type, RBuildingCondData p_Data){
  _Type = p_Type;
  _SingleData = p_Data;
  IsConditionMet(_SingleData._IsReach);
  _IsMet = _SingleData._IsReach;
  if(_Type == EBuildingCondType::Time){
    NeedSpeedUp();
  } else if(_Type == EBuildingCondType::Building || _Type == EBuildingCondType::Star ){
    NeedUpgrade();
  } else if(_Type == EBuildingCondType::Res){
    NeedResource();
    CollegeOpen();
  } else if(
    _Type == EBuildingCondType::Tool ||
    _Type == EBuildingCondType::We ||
    _Type == EBuildingCondType::Item){
      NeedTools();
  } else if(_Type == EBuildingCondType::NebulaTower){
    NeedNebulaTower();
  }
}

void UIBuildingCreateSingle::CollegeOpen(){
  auto l_ResReducePercent = 0;//technologyCtrl:getTechnologyPower(gTechnologyType.RADIANCE_WAR_RADIANCE_STRENGTHEN_COST_REDUCE) or 0
  auto l_HaveRes = ResourceCtrl::Get()->GetResCount(_SingleData._Resid);
  auto l_ResNeed = float(_SingleData._ResCount) * float(1 - l_ResReducePercent);
  if(!GBase::Const::Get()->IsArClient && _SingleData._IsNormal)
    l_ResNeed = _SingleData._ResCount;
  if(l_HaveRes < l_ResNeed){
    IsConditionMet(false);
    _IsMet = false;
  }else{
    IsConditionMet(true);
    _IsMet = true;
  }
  _SingleData._ResCount = l_ResNeed;
  _LabelDes->setString(GStringUtils::FormatK(l_ResNeed));
}

bool UIBuildingCreateSingle::LuckBlessOpen(bool p_IsOpen){
  auto l_ResCount = 0;
  auto l_HaveRes = 0;
  if(p_IsOpen){
    auto l_LabelW = _LabelDes->getVirtualRendererSize().width;
    l_HaveRes = ResourceCtrl::Get()->GetResCount(_SingleData._Resid);
    l_ResCount = LuckyBlessCtrl::Get()->GetResult(_SingleData._ResCount);
    auto l_SubPercent = EffectCtrl::Get()->GetBuffEffect(EEffect::UPGRADE_CASTLE_COST_RES_REDUCE_FOR_POW);
    l_ResCount = std::ceil(l_ResCount * (1 - l_SubPercent / 1000));
    _SpriteLuckLine->setVisible(true);
    _LabelLuckValue->setVisible(true);
    _SpriteLuckLine->setScaleX(l_LabelW/616);
    _LabelLuckValue->setString(GStringUtils::FormatK(l_ResCount));
    _LabelLuckValue->setPositionX(GBase::DFPosX(534 - (l_LabelW + 60), _LabelLuckValue));
    if(l_HaveRes < l_ResCount){
      _LabelLuckValue->setColor(GDisplay::Get()->COLOR_RED);
      IsConditionMet(false);
      _IsMet = false;
    }else {
      _LabelLuckValue->setColor(GDisplay::Get()->COLOR_GREEN);
      IsConditionMet(true);
      _IsMet = true;
    }
  }else{
    _SpriteLuckLine->setVisible(false);
    _LabelLuckValue->setVisible(false);
  }
  return l_HaveRes >= l_ResCount;
}

bool UIBuildingCreateSingle::RadiantBlessOpen(bool p_IsOpen, bool p_IsState, bool p_LuckIsOpen){
  //   local resCount = 0
  auto l_ResCount = 0;
  auto l_HaveRes = 0;
  if(p_IsOpen){
    //   self.spriteLuckLine:setVisible(true)
    //   self.labelLuckValue:setVisible(true)
    //   local radiantDecreeCtrl = SoraDGetCtrl("radiantDecreeCtrl")
    //   local labelW = self.labelDes:getVirtualRendererSize().width
    //   local toolid = self.tableInfoSingleData.singleData.toolid
    //   local subPercent = 0
    if(_Type == EBuildingCondType::Item /*and toolid == 311001 or toolid == 311101 */ ){
  //     local backpackCtrl = SoraDGetCtrl("backpackCtrl")
  //     haveRes = backpackCtrl:getItemCount(self.tableInfoSingleData.singleData.toolid)
  //     resCount = self.tableInfoSingleData.singleData.toolcount
  //     local effect, source = radiantDecreeCtrl:getEffectSouce(toolid == 311001 and 3 or 4, isStatue)
  //     subPercent = buffCtrl:getBuffEffect(effect, source) or 0
  //     if subPercent == 0 then
  //       self.spriteLuckLine:setVisible(false)
  //       self.labelLuckValue:setVisible(false)
  //     end
  //     resCount = math.ceil(resCount * (1 - subPercent / 1000))
    }else{
  //     haveRes = cityCtrl:getResCount(self.tableInfoSingleData.singleData.resid)
  //     resCount = luckyBlessIsOpen and luckyBlessCtrl:getResult(self.tableInfoSingleData.singleData.rescount) or self.tableInfoSingleData.singleData.rescount
  //     subPercent = buffCtrl:getBuffEffect(gBuffEffect.UPGRADE_CASTLE_COST_RES_REDUCE_FOR_POW) or 0
  //     local effect, source = radiantDecreeCtrl:getEffectSouce(1, isStatue)
  //     local radiantPer = buffCtrl:getBuffEffect(effect, source) or 0
  //     subPercent = subPercent + radiantPer
  //     if subPercent == 0 then
  //       self.spriteLuckLine:setVisible(false)
  //       self.labelLuckValue:setVisible(false)
  //     end
  //     resCount = math.ceil(resCount * (1 - subPercent / 1000))
    }

  //   if subPercent ~= 0 then
  //     self.spriteLuckLine:setScaleX(labelW / 616)
  //     self.labelLuckValue:setString(string.formatnumberthousands(resCount))
  //     self.labelLuckValue:setPositionX(SoraDFPosX(534 - (labelW + 60), self.labelLuckValue))
  //   end
  //   if haveRes < resCount then
  //     self.labelLuckValue:setColor(display.COLOR_RED)
  //     self:isConditionMet(false)
  //     self.isMet = false
  //   else
  //     self.labelLuckValue:setColor(display.COLOR_GREEN)
  //     self:isConditionMet(true)
  //     self.isMet = true
  //   end
  }else{
  //   self.spriteLuckLine:setVisible(false)
  //   self.labelLuckValue:setVisible(false)
  }
  return l_HaveRes >= l_ResCount;
}

void UIBuildingCreateSingle::NeedSpeedUp(){
  _BtnJump->setTitleText(Translate::i18n("common_text_018"));
  auto l_QType = _SingleData._QType;
  if(l_QType == ETask::BuildMastery){
    _ImgIcon->loadTexture("icon_tiny_paper.png", TextureResType::PLIST);
    OpenTimeUpMastery(0);
    _Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIBuildingCreateSingle::OpenTimeUpMastery, this));
  } else if(l_QType == ETask::BuildStarQueue){
    _ImgIcon->loadTexture("icon_hourglass.png", TextureResType::PLIST);
    _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
    OpenTimeUpStar(0);
    _Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIBuildingCreateSingle::OpenTimeUpStar, this));
  } else if(l_QType == ETask::BuildStarQueuePrivilege){
    _ImgIcon->loadTexture("icon_hourglass.png", TextureResType::PLIST);
    _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
    OpenTimeUpStarSecond(0);
    _Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIBuildingCreateSingle::OpenTimeUpStarSecond, this));
  }else{
    _ImgIcon->loadTexture("icon_hourglass.png", TextureResType::PLIST);
    _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
    OpenTimeUp(0);
    _Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIBuildingCreateSingle::OpenTimeUp, this));
  }
}

void UIBuildingCreateSingle::BuildTimerEnd(){
  if(_Type == EBuildingCondType::Time){
    GBase::DManagerRemoveTimer(_Timer);
    _Timer = nullptr;
    if(_HandleCallBack)
      _HandleCallBack(_SingleData);
  }
}

void UIBuildingCreateSingle::OpenTimeUp(float dt){
  
  auto l_BuildingName = BuildingRead::Get()->GetName(_SingleData._Data._Bid);
  auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(_SingleData._Data._Iid);
  auto l_QType = l_BuildingCell->_Info.state;
  GString l_TypeStr;
  if(l_QType == EBuildingState::Building){
    l_TypeStr = "common_text_753";
  }else if(l_QType == EBuildingState::Demolishing){
    l_TypeStr = "common_text_754";
  }else{
    l_TypeStr = "common_text_755";
  }

  RefreshLabelDes(Translate::i18n(l_TypeStr.c_str(), {{"name", l_BuildingName}}));
  GTime l_LeftTime = _SingleData._Data._Task.GetRemainTime(); 
  auto l_FreeTime = BuildingLogic::Get()->GetFreeSpeedUpTime(_SingleData._BLvl);
  if(l_LeftTime <= l_FreeTime){
    _BtnJump->setTitleText(Translate::i18n("common_text_049"));
    _BtnJump->loadTextureNormal("btn_alliance_green.png", Widget::TextureResType::PLIST);
    _BtnJump->setCapInsets(Rect(5, 5, 47, 47));
  }else{
    _BtnJump->setTitleText(Translate::i18n("common_text_018"));
    _BtnJump->loadTextureNormal("btn_alliance_red.png", Widget::TextureResType::PLIST);
    _BtnJump->setCapInsets(Rect(5, 5, 47, 47));
  }
  if(l_LeftTime <= 0)
    BuildTimerEnd();
}

void UIBuildingCreateSingle::OpenTimeUpMastery(float dt){
  GTime l_LeftTime = _SingleData._Data._Task.GetRemainTime();
  auto l_BuildingName = BuildingRead::Get()->GetName(_SingleData._Data._Bid);
  RefreshLabelDes(Translate::i18n("common_text_755", {{"name", l_BuildingName}}));
  _BtnJump->setTitleText(Translate::i18n("common_text_018"));
  _BtnJump->loadTextureNormal("btn_alliance_red.png", Widget::TextureResType::PLIST);
  _BtnJump->setCapInsets(Rect(5, 5, 47, 47));
  if(l_LeftTime <= 0)
    BuildTimerEnd();
}

void UIBuildingCreateSingle::OpenTimeUpStar(float dt){
  GTime l_LeftTime = _SingleData._Data._Task.GetRemainTime();
  auto l_BuildingName = BuildingRead::Get()->GetName(_SingleData._Data._Bid);
  RefreshLabelDes(Translate::i18n("Glory_text_13", {{"name", l_BuildingName}}));
  _BtnJump->setTitleText(Translate::i18n("common_text_018"));
  _BtnJump->loadTextureNormal("btn_alliance_red.png", Widget::TextureResType::PLIST);
  _BtnJump->setCapInsets(Rect(5, 5, 47, 47));
  if(l_LeftTime <= 0)
    BuildTimerEnd();
}

void UIBuildingCreateSingle::OpenTimeUpStarSecond(float dt){
  GTime l_LeftTime = _SingleData._Data._Task.GetRemainTime();
  auto l_BuildingName = BuildingRead::Get()->GetName(_SingleData._Data._Bid);
  RefreshLabelDes(Translate::i18n("Glory_text_13", {{"name", l_BuildingName}}));
  _BtnJump->setTitleText(Translate::i18n("common_text_018"));
  _BtnJump->loadTextureNormal("btn_alliance_red.png", Widget::TextureResType::PLIST);
  _BtnJump->setCapInsets(Rect(5, 5, 47, 47));
  if(l_LeftTime <= 0)
    BuildTimerEnd();
}

void UIBuildingCreateSingle::RefreshLabelDes(const GString &p_Str){
  GTime l_LeftTime = _SingleData._Data._Task.GetRemainTime();
  _LabelDes->setString(p_Str + " " + GBase::DConvertSecondToString(l_LeftTime));
  _LabelDes->setFontSize(20);
  if(_LabelDes->getContentSize().width > 230){
    _LabelDes->setString(p_Str + "\n" + GBase::DConvertSecondToString(l_LeftTime));
    _LabelDes->setFontSize(16);
  }
}

void UIBuildingCreateSingle::NeedUpgrade(){
  
  _BtnJump->setTitleText(Translate::i18n("common_text_382"));
  _ImgIcon->loadTexture(BuildingRead::Get()->GetIcon(_SingleData._Data._Bid), Widget::TextureResType::PLIST);
  _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
  auto l_BuildingName = BuildingRead::Get()->GetName(_SingleData._Data._Bid);

  if(_Type == EBuildingCondType::Star){
    if(_SingleData._Data._Bid == EBuilding::StarBraveStatue){
    //     local cityltCtrl = include("cityltCtrl")
    //     local info = cityltCtrl.getQualityByStarLv(self.tableInfoSingleData.singleData.starLv)
    //     self.labelDes:setString(i18n("Soldiers_armor_text_60", {
    //       quality = i18n(string.format("Soldiers_armor_qualityName_%.2d", info.quality)),
    //       lv = info.level
    //     }))
    }else{
      _LabelDes->setString(
        l_BuildingName + " " + Translate::i18n("Glory_text_24", {{
          "lv", std::to_string(_SingleData._StarLvl)
        }})
      );
    }
  } else {
    auto l_WarLvl = BuildingLogic::Get()->TransFormBuildLvToWarLv(_SingleData._BLvl);
    auto l_Bid = _SingleData._Data._Bid;
    if(l_Bid == EBuilding::Miracle && _SingleData._BLvl == GBase::Const::Get()->CASTLE_MAX_WARLV){
      _LabelDes->setString(Translate::i18n("common_text_2007"));
    } else if(l_WarLvl > 0){
      _LabelDes->setString(
          Translate::i18n("common_text_1957", {
          {"build", l_BuildingName}, {"lv", std::to_string(l_WarLvl)}
          })
        );
    }else{
    _LabelDes->setString(
        Translate::i18n("common_text_334", {
        {"build", l_BuildingName}, {"lv", std::to_string(_SingleData._BLvl)}
        })
      );
    }
  }
}

void UIBuildingCreateSingle::NeedTools(){
  _BtnJump->setTitleText(Translate::i18n("common_text_337"));
  _ImgIcon->loadTexture(ItemRead::Get()->GetIcon(_SingleData._IdItem), TextureResType::PLIST);
  _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
  _LabelDes->setString(
    ItemRead::Get()->GetName(_SingleData._IdItem) + " " +
    GStringUtils::FormatK(_SingleData._CurCount) + "/" + 
    GStringUtils::FormatK(_SingleData._ItemCount)
  );
}

void UIBuildingCreateSingle::NeedResource(){
  _BtnJump->setTitleText(Translate::i18n("common_text_337"));
  _ImgIcon->loadTexture(ResourceRead::Get()->GetIcon(_SingleData._Resid), TextureResType::PLIST);
  _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
  _LabelDes->setString(GStringUtils::FormatK(_SingleData._ResCount));
}

void UIBuildingCreateSingle::BtnJumpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  auto l_Btn = dynamic_cast<ui::Button *>(p_Sender);
  if(p_Touch ==  Widget::TouchEventType::ENDED){
    if(_Scroll && !GBase::DIsNodeVisibleOnScroll(l_Btn, _Scroll))
      return;
    if(_SingleIsMoved){
      _SingleIsMoved = false;
      return;
    }
    GBase::PlaySound();
    if(_HandleCallBack)
      _HandleCallBack(_SingleData);
  } else if(p_Touch == ui::Widget::TouchEventType::MOVED){
    auto l_TBPoint = l_Btn->getTouchBeganPosition();
    auto l_TMPoint = l_Btn->getTouchMovePosition();
    auto l_Distance = l_TBPoint.distance(l_TMPoint);
  if(l_Distance > TOUCH_MOVED_ERROR_VALUE)
    _SingleIsMoved = true;
  } else if(p_Touch == ui::Widget::TouchEventType::CANCELED){
    _SingleIsMoved = false;
  }
}

void UIBuildingCreateSingle::NeedNebulaTower(){
  _BtnJump->setTitleText(Translate::i18n("common_text_477"));
  _ImgIcon->loadTexture("icon_xyqy_xyt.png", TextureResType::PLIST);
  _ImgIcon->setScale(40 / _ImgIcon->getContentSize().height);
  _LabelDes->setString(
    Translate::i18n("common_text_334", {
      {"name", Translate::i18n("nebula_war_text_0152")},
      {"lv", std::to_string(_SingleData._NeedLvl)}
    })
  );
}

void UIBuildingCreateSingle::IsConditionMet(bool p_IsMet){
  if(p_IsMet){
    _ImgState->loadTexture("icon_yes.png", TextureResType::PLIST);
    _LabelDes->setColor(GDisplay::Get()->COLOR_WHITE);
  }else{
    _ImgState->loadTexture("icon_no.png", TextureResType::PLIST);
    _LabelDes->setColor(GDisplay::Get()->COLOR_RED);
  }
  _BtnJump->setVisible(!p_IsMet);
}


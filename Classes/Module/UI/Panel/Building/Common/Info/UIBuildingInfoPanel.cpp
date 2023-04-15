#include "UIBuildingInfoPanel.h"
#include "Base/Common/Common.Func.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Building/Building.Read.h"
#include "Module/Building/Building.Logic.h"
#include "Module/Building/IBuilding.h"
#include "UIBuildingInfoSingle.h"

int32 UIBuildingInfoPanel::WELevelProMin = 25;
int32 UIBuildingInfoPanel::WELevelProMax = 100;
int32 UIBuildingInfoPanel::maxDemolishNum = 10;

UIBuildingInfoPanel *UIBuildingInfoPanel::Create(){
  auto l_Panel = UIBuildingInfoPanel::Create("UiParts/Panel/Building/Common/buildInfoPanel.csb");
  return l_Panel;
}

void UIBuildingInfoPanel::Ctor(){
  BindBtnClose();
  _FadeInDelay = 0.3f;
  _FirstRunWar = true;
  _NamePosY = 260;
  _LabelInfo = GBase::GetChildByName<ui::Text *>(this, "Text_info");
  _NodeTitle = GBase::GetChildByName<Node *>(this, "Node_title");
  _LabelTitle = GBase::GetChildByName<ui::Text *>(this, "Text_title");
  _LabelName = GBase::GetChildByName<ui::Text *>(this, "Text_name");
  _BtnMore = GBase::GetChildByName<ui::Button *>(this, "Button_more");
  _BtnCancell = GBase::GetChildByName<ui::Button *>(this, "Button_cancel");
  _ScrollInfo = GBase::GetChildByName<ui::ScrollView *>(this, "ScrollView_info");
  _NodeCenter = GBase::GetChildByName<Node *>(this, "Center_Node");
  // self.tableBuildInfo = {
  //   buildInfo = {},
  //   bid = 0,
  //   iid = 0,
  //   btype = 0,
  //   bstate = 0
  // }
  _BtnMore->addTouchEventListener(CC_CALLBACK_2(UIBuildingInfoPanel::BtnMoreCallBack, this));
  _BtnCancell->addTouchEventListener(CC_CALLBACK_2(UIBuildingInfoPanel::BtnCancelCallBack, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_MAINCITYVIEW_BUILDINFO_QUEUE_END",CC_CALLBACK_1(UIBuildingInfoPanel::BuildQueueCallback, this));
  GBase::DAddMessage(this, "MESSAGE_BUILD_INFO_UPGRADE",CC_CALLBACK_1(UIBuildingInfoPanel::CloseByBuildLock, this));
  _BtnMore->setTitleText(Translate::i18n("common_text_376"));
  _LabelWarCur = GBase::GetChildByName<ui::Text *>(this, "Text_warCur");
  _NodeNameBg = GBase::GetChildByName<Node *>(this, "Node_nameBg");
  InitWidget();
}

void UIBuildingInfoPanel::InitWidget(){
  _ScrollDes = GBase::GetChildByName<ui::ScrollView *>(this, "ScrollView_des");
  _LabelDes  = GBase::GetChildByName<ui::Text *>(this, "Text_buildDes");
  _NodeWar   = GBase::GetChildByName<Node *>(this, "Node_war");
  _ImgWarBg  = GBase::GetChildByName<ui::ImageView *>(this, "Image_warProBg");
  _ImgWarBg->setLocalZOrder(-1);
  _NodeProgressBar = GBase::GetChildByName<Node *>(this, "Node_progressBar");
  _NodeEffect = GBase::GetChildByName<Node *>(this, "Node_effect");
  _WarBarTo = GDisplay::Get()->NewProgressTimer("frame_jzjz_jdt2.png", ProgressTimer::Type::RADIAL);
  _WarBarTo->setScaleX(GBase::DFIsRA() ? -1 : 1);
  _WarBarTo->setColor({152, 85, 26});
  _NodeProgressBar->addChild(_WarBarTo);
  _WarBarTo->setPercentage(WELevelProMin + 0.1 * (WELevelProMax - WELevelProMin));

  _WarBarCur = GDisplay::Get()->NewProgressTimer("frame_jzjz_jdt2.png", ProgressTimer::Type::RADIAL);
  _WarBarCur->setScaleX(GBase::DFIsRA() ? -1 : 1);
  _NodeProgressBar->addChild(_WarBarCur);
  _WarBarCur->setPercentage(WELevelProMin);
  _EffectWar = WarLvBarEffect();
  _EffectWar->setVisible(false);
  _NodeWar->setVisible(false);

  auto l_Bg = GBase::GetChildByName<ui::ImageView *>(this, "Image_bbg");
  // bg:setFillType(1)
  l_Bg->setScale9Enabled(false);
  _IconWarCur = GBase::GetChildByName<Sprite *>(this, "icon_warCur");
  _IconWarTo  = GBase::GetChildByName<Sprite *>(this, "icon_warTo");
  _LabelWarPro = GBase::GetChildByName<ui::Text *>(this, "Text_warPro");
  _LabelWarPro->setString("0%");
  _NodeLeft = GBase::GetChildByName<Node *>(this, "Center_Panel_left");
  _NodeTop = GBase::GetChildByName<Node *>(this, "Top_Panel");
  float l_H = GDisplay::Get()->height - (_NodeLeft->getPositionY() + 0.5 * _NodeLeft->getContentSize().height);
  _NodeTop->setContentSize({640.0f, l_H });
  _NodeBottom = GBase::GetChildByName<Node *>(this, "Bottom_Panel");
  float l_H_ = (_NodeLeft->getPositionY() - 0.5 * _NodeLeft->getContentSize().height);
  _NodeBottom->setContentSize({640.0f, l_H_});
  _NodeCenter->setPositionY(std::max(450.0f, GDisplay::Get()->height /2));
}

void UIBuildingInfoPanel::InitData(EBuildingIndex p_Index, IBuilding *p_Building){

  _Building = p_Building;
  _BuildingIndex = p_Index;
  _BuildingState = p_Building->GetState();

  auto l_BuildCell = CityCtrl::Get()->GetBuildingCellByIndex(p_Index);
  UpdateState();
  _NodeNameBg->setPositionY(_NamePosY);
  RefreshLabelDes(BuildingRead::Get()->GetDes(l_BuildCell->GetBuildingId()));
  auto l_IsWar = BuildingLogic::Get()->IsBuildIDWarLv(l_BuildCell->GetBuildingId(), l_BuildCell->_Info.buildingLvl);
  auto l_BuildLvlT = Translate::i18n("common_text_420", {{
    "level", std::to_string(std::min(l_BuildCell->_Info.buildingLvl, 30))
  }});
  auto l_IsNeedShow = false;
  if(_Building){
    if(_Building->GetState() == EBuildingState::Building || _Building->IsTraining()){
      if(BuildingLogic::Get()->BuildLvIsFull(_BuildingIndex))
        l_IsNeedShow = true;
    }
  }

  if(l_IsWar._IsWar && l_IsWar._WarLvl >= 0){
    _WarLvl = l_IsWar._WarLvl;
    _WarProgress = l_IsWar._Progress;
    _WarToLv = BuildingLogic::Get()->TransFormBuildLvToWarLv(l_BuildCell->_Info.buildingLvl + 10);
    if(l_IsWar._WarLvl > 0)
      l_BuildLvlT = Translate::i18n("common_text_1948", {{"lv", std::to_string(l_IsWar._WarLvl)}});
    if(l_IsNeedShow)
      InitWarView();
  }

  if(l_BuildCell->GetBuildingId() == EBuilding::StarBraveStatue)
    l_BuildLvlT = "";
  if(_StarLvl > 0)
    l_BuildLvlT = l_BuildLvlT + "\n" + Translate::i18n("Glory_text_24", {{"lv", std::to_string( _StarLvl)}});
  
  if(l_BuildCell->GetBuildingId() == EBuilding::StarBraveStatue){
    //   self.isHideCurrentSceneView = true
    //   local cityltCtrl = include("cityltCtrl")
    //   local qualityInfo = cityltCtrl.getQualityByStarLv(self.starLv)
    //   self.spBrave:setPositionY(390 - math.max(0, 1000 - self:getPanelOffsetHeight()))
    //   self.spBrave:setScale(self:getPanelOffsetHeight() / 1386)
    //   self.nodeNameBg:setPositionY(870)
    //   self.spBrave:setSpriteFrame(string.format("bg_armor_build_%.2d.png", qualityInfo.quality))
    //   self.labelName:setString(i18n("Soldiers_armor_text_60", {
    //     quality = i18n(string.format("Soldiers_armor_qualityName_%.2d", qualityInfo.quality)),
    //     lv = qualityInfo.level
    //   }))
    //   self:updateBraveStatueEffect(qualityInfo)
  }else{
    _LabelName->setString(
      l_BuildLvlT + "\n" + BuildingRead::Get()->GetName(l_BuildCell->GetBuildingId())
    );
  }
  if(l_BuildCell->GetBuildingId() == EBuilding::Depot){
    _LabelTitle->setString(Translate::i18n("lordskill_name_12021"));
    _NodeTitle->setVisible(true);
    _ScrollInfo->setPositionY(328.0f);
    _ScrollInfo->setContentSize({560, 225});
  } else {
    _NodeTitle->setVisible(false);
    _ScrollInfo->setPositionY(358.0f);
    _ScrollInfo->setContentSize({560, 225});
  }
  
  _BuildMoreInfoData = BuildingRead::Get()->GetMoreInfoData(_Building->GetBuildingIndex());
  if(_BuildMoreInfoData.size() == 0){
    _LabelInfo->setVisible(true);
    _LabelInfo->setString(BuildingRead::Get()->GetUpgradeDes(_Building->GetBuildingId()));
  }else{
    _LabelInfo->setVisible(false);
  }
  _LabelInfo->setVisible(false);
  InitScroll();
  RefreshCancelStarBtn();
}

void UIBuildingInfoPanel::BtnMoreCallBack(Ref *p_Ref, ui::Widget::TouchEventType p_Touch){
  CCLOG("Test BtnMoreCallBack");
}

void UIBuildingInfoPanel::BtnCancelCallBack(Ref *p_Ref, ui::Widget::TouchEventType p_Touch){
  CCLOG("Test BtnCancelCallBack");
}

Node *UIBuildingInfoPanel::WarLvBarEffect(){
  
  RCreatEffctParam l_Part_1;
  RCreatEffctParam l_Part_2;
  RCreatEffctParam l_Part_3;

  l_Part_1._PList = "et_battlelv01_01.plist";
  l_Part_1._Pos = {6.14f, 17.77f};
  l_Part_1._Scale = {1.72f, 1.72f};
  l_Part_1._Rotate = 20.77f;
  l_Part_1._Name = "effect1";
  l_Part_1._PosType = ParticleSystem::PositionType::FREE;
  l_Part_1._TpScale = 1;
  
  l_Part_2._PList = "et_battlelv01_02.plist";
  l_Part_2._Pos = {0.73f, 4.96f};
  l_Part_2._Scale = {0.76f, 0.76f};
  l_Part_2._Rotate = 30.27f;
  l_Part_2._Name = "effect2";
  l_Part_2._PosType = ParticleSystem::PositionType::FREE;
  l_Part_2._TpScale = 1;
  
  l_Part_3._PList = "et_battlelv01_03.plist";
  l_Part_3._Scale = {0.675f, 0.675f};
  l_Part_3._Rotate = 38.5f;
  l_Part_3._Name = "effect2";
  return GBase::DCreateEffectNode({l_Part_1, l_Part_2, l_Part_3});
}

void UIBuildingInfoPanel::InitWarView(){

}

void UIBuildingInfoPanel::UpdateState(){
  
  auto l_ViewState = EBuildingState::Normal;
  if(_Building)
    l_ViewState = _Building->GetState();
  _BtnCancell->setVisible(true);
  _BtnCancell->loadTextures("btn_red_normal_01.png", "", "", TextureResType::PLIST);

  if(l_ViewState == EBuildingState::Normal){
    auto l_QueueType = BuildingRead::Get()->GetQueueType(_Building->GetBuildingId());
    if(_Building->GetBuildingId() != EBuilding::ElitePalace && TaskCtrl::Get()->QueryQueue(l_QueueType)){
      if(TaskCtrl::Get()->IsHospitalQueue(l_QueueType)){
        _BtnCancell->setTitleText(Translate::i18n("common_text_386"));
        _BuildingState = EBuildingState::Training;
      } else if(l_QueueType == ETask::FrotressQueue){
        _BtnCancell->setTitleText(Translate::i18n("common_text_384"));
        _BuildingState = EBuildingState::TrapBuilding;
      } else if(
        l_QueueType == ETask::chariot_plant_queue || l_QueueType == ETask::stables_queue ||
        l_QueueType == ETask::range_queue || l_QueueType == ETask::barracks_queue
      ){
        _BtnCancell->setTitleText(Translate::i18n("common_text_383"));
        _BuildingState = EBuildingState::Training;
      } else if(l_QueueType == ETask::forge_equipment){
        _BtnCancell->setVisible(false);
        _BtnMore->setPositionX(320);
      } else if(l_QueueType == ETask::armor_forging){
        _BtnCancell->setTitleText(Translate::i18n("Soldiers_armor_text_46"));
        _BuildingState = EBuildingState::ArmorForg;
      } else if(l_QueueType == ETask::craft_study){
        _BtnCancell->setTitleText(Translate::i18n("Soldiers_armor_text_45"));
        // _BuildingState = EBuildingState::CRAFT_STUDY;
      } else {
        _BtnCancell->setTitleText(Translate::i18n("common_text_387"));
        _BuildingState = EBuildingState::Studying;
      }
    }

    
    if(BuildingLib::Get()->DGetBuildTypeByIndex(_BuildingIndex) == EBuildingPlace::Inner){
      _BtnCancell->setVisible(false);
      _BtnMore->setPositionX(320.0f);
    }else{
      auto l_IsDemolish = BuildingStatic::Get()->getBuildingSpecs(_Building->GetBuildingId()).isDemolish;
      if(!l_IsDemolish){
        _BtnCancell->setVisible(false);
        _BtnMore->setPositionX(320);
      }else{
        _BtnCancell->setTitleText(Translate::i18n("common_text_728"));
      }
    }
  } else if(l_ViewState == EBuildingState::Building)
    _BtnCancell->setTitleText(Translate::i18n("common_text_384")); 
  else if(l_ViewState == EBuildingState::Upgrading)
    _BtnCancell->setTitleText(Translate::i18n("common_text_385")); 
  else if(l_ViewState == EBuildingState::Demolishing)
    _BtnCancell->setTitleText(Translate::i18n("common_text_727"));
}

void UIBuildingInfoPanel::InitScroll(){
  _ScrollInfo->removeAllChildren();
  auto l_InfoCount = _BuildMoreInfoData.size();
  auto l_ScrollSize = _ScrollInfo->getContentSize();
  auto l_ScrollH = std::max(float(l_InfoCount * 40), l_ScrollSize.height);
  _ScrollInfo->setInnerContainerSize(Size(l_ScrollSize.width, l_ScrollH));

  for(auto iii = 0; iii < l_InfoCount; iii++){
    auto l_SingleInfo = UIBuildingInfoSingle::Create();
    l_SingleInfo->setPosition({280, l_ScrollH - (iii)*40});
    l_SingleInfo->InitData(_BuildMoreInfoData[iii]);
    _ScrollInfo->addChild(l_SingleInfo);
  }
  if(l_ScrollH > l_ScrollSize.height)
    _ScrollInfo->setBounceEnabled(true);
}

void UIBuildingInfoPanel::RefreshLabelDes(const GString &p_Label){
  _LabelDes->setString(p_Label);
  if(_ScrollDes){
    auto l_TextSize = _ScrollDes->getContentSize();
    auto l_TextH = GBase::DGetAutoHeightLabelNew(_LabelDes, l_TextSize.width);
    if(l_TextH > l_TextSize.height)
      _ScrollDes->setBounceEnabled(true);
    else{
      _ScrollDes->setBounceEnabled(false);
      GBase::DSetTextWidthHeight(_LabelDes, l_TextSize);
      l_TextH = l_TextSize.height;
    }
    _ScrollDes->setInnerContainerSize({l_TextSize.width, l_TextH});
    _LabelDes->setPositionY(l_TextH);
  }
}

void UIBuildingInfoPanel::RefreshCancelStarBtn(){
  // local buildEntity = self.tableBuildInfo.buildEntity
  // local buildStarState = tonumber(buildEntity:getBuildStarState())
  // if buildStarState == BUILD_STAR_STATE.UPGRADEING then
  //   if not self.btnCancelStar then
  //     local btn = self.btnCancel:clone()
  //     btn:addTo(self.btnCancel:getParent())
  //     btn:setPositionX(530)
  //     if self.tableBuildInfo.bid == BUILDID.STAR_BRAVE_STATUE then
  //       btn:setTitleText(i18n("Soldiers_armor_btn_02"))
  //     else
  //       btn:setTitleText(i18n("Glory_text_25"))
  //     end
  //     btn:addTouchEventListener(handler(self, self.btnCancelStarCallBack))
  //     btn:loadTextures("btn_red_normal_01.png", "", "", ccui.TextureResType.plistType)
  //     self.btnCancelStar = btn
  //   end
  //   self.btnCancelStar:setVisible(true)
  //   local viewState = self.tableBuildInfo.bstate
  //   if viewState == BUILD_STATE.NORMAL and self.tableBuildInfo.btype == 1 then
  //     self.btnCancel:setVisible(false)
  //   end
  //   if self.btnCancel:isVisible() then
  //     self.btnMore:setPositionX(SoraDFPosX(530, 640))
  //     self.btnCancel:setPositionX(320)
  //     self.btnCancelStar:setPositionX(SoraDFPosX(110, 640))
  //   else
  //     self.btnMore:setPositionX(SoraDFPosX(447, 640))
  //     self.btnCancelStar:setPositionX(SoraDFPosX(193, 640))
  //   end
  // elseif self.btnCancelStar then
  //   self.btnCancelStar:setVisible(false)
  // end
}
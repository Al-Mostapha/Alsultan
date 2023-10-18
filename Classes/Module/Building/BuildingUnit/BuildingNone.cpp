// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingNone.h"
#include "Base/Common/Common.Box.h"
#include "Module/City/City.Func.Parm.h"
#include "Module/Player/Player.Static.h"
#include "Module/Building/Building.Lib.h"
#include "Module/UI/Panel/Building/UIBuildCreatePanel.h"

BuildingNone::BuildingNone()
{
	BuildingSpriteImage  = "inner_city_building_tile.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 39};
}

bool BuildingNone::init()
{

	if (!IBuilding::init())
		return false;

	return true;
}

void BuildingNone::onEnter()
{
	IBuilding::onEnter();
  auto lBuildingPlace = BuildingLib::Get()->DGetBuildTypeByIndex(m_BuildingIndex);
  if (lBuildingPlace == EBuildingPlace::Inner)
		BuildingSpriteImage = "inner_city_building_tile.png";
	else if (lBuildingPlace == EBuildingPlace::Outer)
		BuildingSpriteImage = "res_tile.png";

	setBuildingSprite();
	// setBuildingLvBg();
	// setUpgradeSprite();
	// setBuildingLvlText();
	// setBuildingSleepSprite();
	// setBuildingIconMiracle();
}

bool BuildingNone::Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch){

  auto lBuildingIndex = GetBuildingIndex();
  auto lBuildingType = BuildingLib::Get()->DGetBuildTypeByIndex(lBuildingIndex);
  if(BuildingLib::Get()->DIsFixedBuild(lBuildingIndex)){
    GBase::DShowMsgTip(Translate::i18n("notice_0026"));
    return true;
  }

  auto lCallFuncCreate = CallFunc::create([&](){
    auto lIndex = getTag();
    if(GetBuildingIndex() == EBuildingIndex::MonumentRos)
      return;
    auto lPanel = UIBuildCreatePanel::Create();
    lPanel->Show();
    lPanel->SetBuildingTypeAndData(lBuildingType, GetBuildingIndex());
    //   if buildID then
    //     panel:selectWheelByBid(buildID)
    //   end
    static RDoOffestMoveParam p_Parm ;
    p_Parm._OffsetType = EMainCityViewOffsetType::Building;
    p_Parm._BuildIndex = GetBuildingIndex();
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_OFFSET_BUILD", &p_Parm);
  });

  //   local spriteTile
  //   if buildType == 0 then
  //     if buildIndex == cityBuildConstDef.buildIndexDef.index_Miracle then
  //       spriteTile = display.newSprite("#" .. "BG_miracle_01.png")
  //       if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //         spriteTile = display.newSprite("#" .. "BG_diaoxaing_byzantine_01.png")
  //       end
  //     else
  //       spriteTile = display.newSprite("#" .. "inner_city_building_tile.png")
  //     end
  //     if spriteTile then
  //       build:addChild(spriteTile)
  //       if buildIndex == cityBuildConstDef.buildIndexDef.index_Miracle then
  //         print("\229\136\176\232\191\153\233\135\140=====1")
  //         spriteTile:setPosition(cc.p(129, 51))
  //         if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //           spriteTile:setPosition(cc.p(70, 122))
  //         end
  //       else
  //         print("\229\136\176\232\191\153\233\135\140=====2")
  //         spriteTile:setPosition(cc.p(132, 62))
  //       end
  //     end
  //   else
  //     local spriteTileName = "res_tile" .. buildIndex
  //     spriteTile = self.batchNodeOuterTiles:getChildByName(spriteTileName)
  //   end
  //   build:setTouchEnabled(false)
  auto lCallFunc1 = CallFunc::create([&](){
    if(BuildingSprite)
      BuildingSprite->runAction(TintBy::create(0.1, -0.5, -0.5, -0.5));
    GBase::DShowLoading(nullptr, {}, 1000, true);
  });
  
  auto lDelay1 = DelayTime::create(0.2);
  auto lDelay2 = DelayTime::create(0.1);

  //   local callFunc2 = cca.callFunc(function()
  //     SoraDCloseLoading(nil, 1000)

  //   end)
  auto lCallFunc2 = CallFunc::create([&](){
    GBase::DCloseLoading(nullptr, "1000");
    if(lBuildingType == EBuildingPlace::Inner && BuildingSprite){
      auto lRemoveCall = CallFunc::create([&](){
        if(BuildingSprite)
          BuildingSprite->removeFromParent();
      });
      auto lFadeOut = FadeOut::create(0.1);
      BuildingSprite->runAction(Sequence::create(lFadeOut, lRemoveCall, nullptr));
    }
    //     build:setTouchEnabled(true)
    //     build:setSwallowTouches(false)
    m_IsBuildBtnEnabled = true;
  });
  //   self:buildCreatePanelShowBegin()
  m_IsBuildBtnEnabled = false;
  runAction(
    Sequence::create(
      lCallFunc1, lDelay1,
      lCallFuncCreate, lDelay2,
      lCallFunc2, nullptr
    )
  );
  return true;
} 

/**
void BuildingClassBarrack::setBarrackInfantry() {}


void ASBuildingClassBarrack::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/bubingying.bubingying'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassBarrack::showTrainSol() {

	UPaperFlipbook* InfantryFB = LoadObject<UPaperFlipbook>(nullptr, TEXT("PaperFlipbook'/Game/Animation/MainCity/MainCityNPC/bybubing.bybubing'"));
	if (InfantryFB) {
		TrainInfantry->SetFlipbook(InfantryFB);
	}
	else {

		GLog->Log("---------------------- Animation Not Found");
	}

}

void ASBuildingClassBarrack::hideTrainSol() {


}

void ASBuildingClassBarrack::BeginPlay() {

	Super::BeginPlay();
	showTrainSol();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
	setOperatingProgressBar();

}

void ASBuildingClassBarrack::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


	GLog->Log("------------------------------------------------------------------");

}

void ASBuildingClassBarrack::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBarrack::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBarrack::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTrain->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBarrack::OnBtnClickedTrain);

}


void ASBuildingClassBarrack::OnBtnClickedDetail() {

	GLog->Log("-----------------**************-----------------");

}


void ASBuildingClassBarrack::OnBtnClickedUpgrade() {

	GLog->Log("-----------------+++++++++++++++++++-----------------");

}


void ASBuildingClassBarrack::OnBtnClickedTrain() {

	GLog->Log("----------------------------------");

}

void ASBuildingClassBarrack::initBuilding() {}


void ASBuildingClassBarrack::setOperatingProgressBar() {


	static TSubclassOf<USWid_BuildingProgBar> ProgBar = LoadObject<UClass>(nullptr, *ProgBarClassPath);

	ProgressBarWid->SetWidgetClass(ProgBar);
	ProgressBarWid->SetDrawSize(FVector2D(260.0, 80.0));
	USWid_BuildingProgBar* Widget = Cast<USWid_BuildingProgBar>(ProgressBarWid->GetWidget());
	if (!Widget)
		return;
	static UTexture2D* IconSprite = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Icon/BuildingProgress/icon_main_build_02.icon_main_build_02'"));
	if (IconSprite)
	{
		FSlateBrush Brush;
		Brush.SetResourceObject(IconSprite);
		Brush.ImageSize = FVector2D(IconSprite->GetSizeX(), IconSprite->GetSizeY());
		Widget->OperationIcon->SetBrush(Brush);
	}
	else {

		GLog->Log("((((((((((((((((((((()))))))))))))))))))))))))");
	}
}


void ASBuildingClassBarrack::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataBarrack BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);


	}

}*/
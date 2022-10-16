// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFCastle.h"
#include "cocostudio/CocoStudio.h"

BuildingFCastle::BuildingFCastle()
{

	// BuildingSpriteImage = "zhucheng.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-110, 124};
}

bool BuildingFCastle::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	// BuildingSprite->setAnchorPoint(Point(0.5, 0.5));

	return true;
}

void BuildingFCastle::setBuildingSprite()
{

	auto CastleSkin = CSLoader::createNode("SceneParts/CastleSkin/castleSkin_1_bzt.csb");
	CastleSkin->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	addChild(CastleSkin);
}

void BuildingFCastle::onEnter()
{
}

void BuildingFCastle::UpdateLvl(){
  IBuilding::UpdateLvl();
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_LOCK_AREA");
  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl4){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_PET_CENTER_VIEW");
    _eventDispatcher->dispatchCustomEvent("MESSAGE_GREEN_POINT_UPDATE");
  }
  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl6){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_RESURRECTION_HALL_VIEW");
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_HISTORY_VIEW");
  }
  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl7){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_LOCK_TURRET");
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_EPICBATTLE_VIEW");
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_TRAIN_HALL_VIEW");
  }

  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl8){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_DEFENDWALL_VIEW");
  }

  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl16){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_ELITE_PALACE_VIEW");
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_PRISON_VIEW");
  }

  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl19){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_MONUMENT_VIEW");
  }

  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl15){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_MASTERY_VIEW");
  }

  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl10){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_BLACKSMITH_VIEW");
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_MATERIAL_WORKSHOP_VIEW");
  }

  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl25){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_COMMUNITY_VIEW");
  }
  if(GetBuildingLvl() >= GBase::Const::Get()->CastleLvl30){
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITY_UPDATE_CRYSTAL_MINE");
  }

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
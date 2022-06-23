// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFLeisureCenter.h"

BuildingFLeisureCenter::BuildingFLeisureCenter()
{

	BuildingSpriteImage = "BG_SPR.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {1, 14};
}

bool BuildingFLeisureCenter::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	setBuildingParticle();

	return true;
}

void BuildingFLeisureCenter::onEnter()
{

	CityBuildingBase::onEnter();
}

void BuildingFLeisureCenter::setBuildingParticle()
{

	auto Part1 = ParticleSystemQuad::create("Particle/et_pyramid_building_01.plist");
	Part1->setPosition(44, 80);
	Part1->setScaleX(1);
	Part1->setScaleY(1);
	Part1->setRotation(-11.22);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 10);

	auto Part2 = ParticleSystemQuad::create("Particle/et_pyramid_building_02.plist");
	Part2->setPosition(44.7, 57.0);
	Part2->setScaleX(1.37);
	Part2->setScaleY(1.533);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 10);

	auto Part3 = ParticleSystemQuad::create("Particle/et_pyramid_building_03.plist");
	Part3->setPosition(-13.3, -135.0);
	Part3->setScaleX(1.723);
	Part3->setScaleY(1.532);
	Part3->setRotation(-118.93);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 10);

	auto Part4 = ParticleSystemQuad::create("Particle/et_pyramid_building_03.plist");
	Part4->setPosition(122.7, 50.0);
	Part4->setScaleX(2.515);
	Part4->setScaleY(3.708);
	Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part4, 10);
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
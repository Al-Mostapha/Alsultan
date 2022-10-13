// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingIWishWell.h"


BuildingIWishWell::BuildingIWishWell() {

	BuildingSpriteImage  = "baozangzhichi.png";
	BuildingSpriteOffset = { 0 , 38 };


}


bool BuildingIWishWell::init() {

	
	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingParticle();
	

	//setBuildingIconMiracle();

	return true;
}


void BuildingIWishWell::setBuildingParticle() {

	auto Part1 = ParticleSystemQuad::create("Particle/et_xyc_01.plist");
	Part1->setPosition(5, 100);
	Part1->setScaleX(0.4615);
	Part1->setScaleY(0.4286);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 10);
	
	auto Part2 = ParticleSystemQuad::create("Particle/et_xyc_03.plist");
	Part2->setPosition(7.6, 60);
	Part2->setScaleX(1.4936);
	Part2->setScaleY(1.109);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 10);
	
	auto Part3 = ParticleSystemQuad::create("Particle/et_xyc_03.plist");
	Part3->setPosition(8.8, 100);
	Part3->setScaleX(1.13);
	Part3->setScaleY(1.13);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 10);
	
	auto Part4 = ParticleSystemQuad::create("Particle/et_xyc_05.plist");
	Part4->setPosition(8.4, -6);
	Part4->setScaleX(1.71);
	Part4->setScaleY(1.7315);
	Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part4, 10);

	auto Part5 = ParticleSystemQuad::create("Particle/et_xyc_06.plist");
	Part5->setPosition(6, 0);
	Part5->setScaleX(0.4);
	Part5->setScaleY(0.3726);
	Part5->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part5, 10);

	auto Part6 = ParticleSystemQuad::create("Particle/et_xyc_01.plist");
	Part6->setPosition(5, 100);
	Part6->setScaleX(0.4615);
	Part6->setScaleY(0.4286);
	Part6->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part6, 10);


	auto Part7 = ParticleSystemQuad::create("Particle/et_xyc_02.plist");
	Part7->setPosition(5, 30);
	Part7->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part7, 10);

	auto Part8 = ParticleSystemQuad::create("Particle/et_xyc_03.plist");
	Part8->setPosition(5, 62);
	Part8->setScaleX(1.1282);
	Part8->setScaleY(1.1282);
	Part8->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part8, 10);

	auto Part9 = ParticleSystemQuad::create("Particle/et_xyc_04.plist");
	Part9->setPosition(57, -8);
	Part9->setScaleX(0.47);
	Part9->setScaleY(0.47);
	Part9->setRotation(-4.3);
	Part9->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part9, 10);

	auto Part10 = ParticleSystemQuad::create("Particle/et_xyc_04.plist");
	Part10->setPosition(54, 40.5);
	Part10->setScaleX(0.35);
	Part10->setScaleY(0.35);
	Part10->setRotation(-14.96);
	Part10->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part10, 10);

	auto Part11 = ParticleSystemQuad::create("Particle/et_xyc_04.plist");
	Part11->setPosition(-48, -8);
	Part11->setScaleX(-0.47);
	Part11->setScaleY(0.4712);
	Part11->setRotation(4.3);
	Part11->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part11, 10);

	auto Part12 = ParticleSystemQuad::create("Particle/et_xyc_04.plist");
	Part12->setPosition(-46, 45);
	Part12->setScaleX(-0.35);
	Part12->setScaleY(0.35);
	Part12->setRotation(14.96);
	Part12->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part12, 10);

	auto Part13 = ParticleSystemQuad::create("Particle/et_xyc_05.plist");
	Part13->setPosition(6, -7);
	Part13->setScaleX(3.2);
	Part13->setScaleY(3.2);
	Part13->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part13, 10);

	auto Part14 = ParticleSystemQuad::create("Particle/et_xyc_06.plist");
	Part14->setPosition(5, -2);
	Part14->setScaleX(0.4675);
	Part14->setScaleY(0.4354);
	Part14->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part14, 10);



}

void BuildingIWishWell::onEnter() {
	IBuilding::onEnter();
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_WISHINGWELL_VIEW");
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
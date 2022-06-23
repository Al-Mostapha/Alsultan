// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingAStable.h"


BuildingAStable::BuildingAStable() {

	BuildingSpriteImage  = "qibingying.png";
	BuildingIconMiracle  = "armyicon_b_510.png";
	BuildingSpriteOffset = { 3, 33 };
	LvlBgOffset = {117, -8};

}


bool BuildingAStable::init() {

	
	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingIconMiracle();
	setBuildingAnimation();
	return true;
}

void BuildingAStable::onEnter() {
	CityBuildingBase::onEnter();
}


void BuildingAStable::setBuildingAnimation() {

	auto frames = getAnimation("shibing2_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto sprite2 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite3 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite4 = Sprite::createWithSpriteFrame(frames.front());
	
	sprite->setPosition(-18, 16);
	sprite2->setPosition(-42, 4);
	sprite3->setPosition(21, 0);
	sprite4->setPosition(-7, -11);

	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);

	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	sprite2->runAction(RepeatForever::create(Animate::create(animation)));
	sprite3->runAction(RepeatForever::create(Animate::create(animation)));
	sprite4->runAction(RepeatForever::create(Animate::create(animation)));

	addChild(sprite);
	addChild(sprite2);
	addChild(sprite3);
	addChild(sprite4);

}


void BuildingAStable::setBuildingIconMiracle() {

	auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
	SleepSprite2->setPosition(45, 0);
	SleepSprite2->setLocalZOrder(10);
	SleepSprite2->setScale(0.3);
	addChild(SleepSprite2);

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
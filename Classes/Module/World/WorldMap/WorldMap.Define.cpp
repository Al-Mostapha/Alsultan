#include "WorldMap.Define.h"
#include "Engine/Display.h"
#include "Base/Common/Common.Teml.h"

WorldMapDefine * WorldMapDefine::Get(){
  static WorldMapDefine * _WorldMapDefine = nullptr;
  if(_WorldMapDefine == nullptr){
    _WorldMapDefine = new WorldMapDefine();
  }
  return _WorldMapDefine;
}

bool WorldMapDefine::IsInWar(){
  return false;
}

bool WorldMapDefine::IsInLegendLord(){
  return false;
}

bool WorldMapDefine::IsInRemains(){
  return false;
}

bool WorldMapDefine::IsInRadiance(){
  return false;
}

bool WorldMapDefine::IsInAtlantis(){
  return false;
}

bool WorldMapDefine::IsInPyramid(){
  return false;
}

bool WorldMapDefine::InInCrossWar(){
  return false;
}

bool WorldMapDefine::IsInKingdomBattle(){
  return false;
}

bool WorldMapDefine::IsInNewTrial(){
  return false;
}

bool WorldMapDefine::IsInWarForbid(bool p_NoShowTips, bool p_Activity){
  return false;
}

bool WorldMapDefine::IsInWarForbidSoldier(bool p_NoShowTips, bool p_Activity){
  return false;
}

void WorldMapDefine::ShowWarTips(bool p_Activity){
  
}

bool WorldMapDefine::IsNebulaKingdomID(){
  return false;
}

bool WorldMapDefine::IsInNebula(){
  return false;
}

bool WorldMapDefine::IsLegendLordKingdomID(int32 pKingdomID){
  return false;
}

bool WorldMapDefine::IsPyramidKingdomID(int32 pKingdomID){
  return false;
}

Color3B WorldMapDefine::GetMoveLineColor(EMapMoveLineColor pColor){
  return Color3B();
}

GString WorldMapDefine::GetMonsterImageName(int32 pMonsterClassID){
  return "MonsterImage";
}

GString WorldMapDefine::GetMonsterName(int32 pMonsterClassID){
  return "MonsterName";
}

int32 WorldMapDefine::GetMonsterLevel(int32 pMonsterClassID){
  return 1;
}

GString WorldMapDefine::GetAttackEffectCsbName(const GString &pMonsterName, const GString &pDirection){
  return "";
}

int32 WorldMapDefine::GetBeginAnimationByName(const GString &pMonsterName){
  return 0;
}

bool WorldMapDefine::CheckIsWastelandMonster(int32 pMonsterClassID){
  //return monsterClassID and monsterClassID >= 3143 and monsterClassID <= 3152
  return pMonsterClassID >= 3143 && pMonsterClassID <= 3152;
}

WorldMapProtectNode *WorldMapDefine::CreateWorldMapProtect(bool pIsGreen){
  return WorldMapProtectNode::Create(pIsGreen);
}

WorldMapProtectNode *CreateWorldMapProtectNew(bool pIsGray = false){
  return WorldMapProtectNode::CreateNew(pIsGray);
}

EResourceType WorldMapDefine::GetResourceTypeID(int32 pResourceClassID){
  return EResourceType::Food;
}

const GString &WorldMapDefine::GetResourceImageName(int32 pResourceClassID){
  return "ResourceImageName";
}

int32 WorldMapDefine::GetResourceLevel(int32 pResourceClassID){
  return 1;
}

const GString &WorldMapDefine::GetResourceName(int32 pResourceClassID){
  return "ResourceName";
}

int32 WorldMapDefine::GetResourceCastleLv(int32 pResourceClassID){
  return 1;
}

// local lineColor_self = cc.c3b(0, 255, 0)
static const Color3B lineColor_self = Color3B(0, 255, 0);
// local lineColor_leader = cc.c3b(255, 0, 255)
static const Color3B lineColor_leader = Color3B(255, 0, 255);
// local lineColor_league = cc.c3b(0, 126, 255)
static const Color3B lineColor_league = Color3B(0, 126, 255);
// local lineColor_all = cc.c3b(0, 255, 255)
static const Color3B lineColor_all = Color3B(0, 255, 255);
// local lineColor_friend = cc.c3b(255, 255, 0)
static const Color3B lineColor_friend = Color3B(255, 255, 0);
// local lineColor_enemy = cc.c3b(255, 0, 0)
static const Color3B lineColor_enemy = Color3B(255, 0, 0);
// local lineColor_normal = cc.c3b(250, 250, 250)
static const Color3B lineColor_normal = Color3B(250, 250, 250);

const Color3B &WorldMapDefine::GetLeagueManorLineColor(bool pIsSelf , EMapAllianceRelationType pRelation){
  if(pIsSelf){
    return lineColor_self;
  }
  switch(pRelation){
    case EMapAllianceRelationType::ALLY:
      return lineColor_all;
    case EMapAllianceRelationType::FRIENDLY:
      return lineColor_friend;
    case EMapAllianceRelationType::ENEMY:
      return lineColor_enemy;
    case EMapAllianceRelationType::SELF:
      return lineColor_self;
    case EMapAllianceRelationType::NORMAL:
      return lineColor_normal;
    default:
      return lineColor_normal;
  }
}

Sprite *WorldMapDefine::CreateCityImageWithLevel(int32 pCityLevel, EFactionType pFaction, Sprite *pImage, Vec2 pOffset){
  if(!pImage)
    return GDisplay::Get()->NewSprite("Castle_lv1_base.png");
  return pImage;
}

Node *WorldMapDefine::GetCastleSkinEffect(EBuildingCastleModel pModel){
  // local node = display.newNode()
  // node:setName("skinBgEffectNode")
  // local data = worldMapDefine.castleSkinEffect[castleType]
  // if data then
  //   if data.effect then
  //     local par_node = SoraDCreateEffectNode(data.effect.param, nil, true)
  //     par_node:addTo(node)
  //   end
  //   if data.imgs then
  //     for k, v in pairs(data.imgs) do
  //       local sprite = display.newSprite("#" .. v.png)
  //       sprite:setPosition(v.pos)
  //       sprite:addTo(node)
  //       SoraDFadeINOUT(sprite)
  //     end
  //   end
  //   if data.frames then
  //     for k, v in pairs(data.frames) do
  //       local sprite = display.newSprite("#" .. v.png)
  //       sprite:setPosition(v.pos)
  //       sprite:addTo(node)
  //       local frames = display.newFrames(v.format, v.from, v.to)
  //       local animation = display.newAnimation(frames, v.time / #frames)
  //       sprite:playAnimationForever(animation)
  //     end
  //   end
  //   if data.offset then
  //     node:setPosition(data.offset)
  //   end
  //   if data.actSprite then
  //     for k, v in pairs(data.actSprite) do
  //       local sprite = display.newSprite("#" .. v.png)
  //       sprite:setPosition(v.pos)
  //       sprite:addTo(node)
  //       local seq = cca.seq({
  //         cca.moveBy(v.animationConfig[k].time, 0, v.animationConfig[k].offsetH),
  //         cca.moveBy(v.animationConfig[k].time, 0, -v.animationConfig[k].offsetH),
  //         cca.moveBy(v.animationConfig[k].time, 0, -v.animationConfig[k].offsetH),
  //         cca.moveBy(v.animationConfig[k].time, 0, v.animationConfig[k].offsetH)
  //       })
  //       sprite:runAction(cc.RepeatForever:create(seq))
  //     end
  //   end
  // end
  // return node
  return GDisplay::Get()->NewNode();
}

GOpt<RWarLevelConfig> WorldMapDefine::GetWarLevelData(int32 pWarLv){
  return {};
}

bool WorldMapDefine::IsRadianceKingdomID(int32 pKingdomID){
  return false;
}

bool WorldMapDefine::IsRemainsKingdomID(int32 pKingdomID){
  return false;
}
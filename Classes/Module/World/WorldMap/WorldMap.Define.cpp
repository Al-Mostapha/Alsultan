#include "WorldMap.Define.h"
#include "Engine/Display.h"
#include "Base/Containers/HashMap.h"
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
  return "anbs";
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

WorldMapProtectNode *WorldMapDefine::CreateWorldMapProtectNew(bool pIsGray){
  return WorldMapProtectNode::CreateNew(pIsGray);
}

EResourceType WorldMapDefine::GetResourceTypeID(int32 pResourceClassID){
  return EResourceType::Food;
}

const GString &WorldMapDefine::GetResourceImageName(int32 pResourceClassID){
  static GString ResImageName = "Map_build_gold.png";
  return ResImageName;
}

int32 WorldMapDefine::GetResourceLevel(int32 pResourceClassID){
  return 1;
}

const GString &WorldMapDefine::GetResourceName(int32 pResourceClassID){
  static GString ResourceName = "ResourceImageName";
  return ResourceName;
}

int32 WorldMapDefine::GetResourceCastleLv(int32 pResourceClassID){
  return 1;
}

static const Color3B lineColor_self   = Color3B(0, 255, 0);
static const Color3B lineColor_leader = Color3B(255, 0, 255);
static const Color3B lineColor_league = Color3B(0, 126, 255);
static const Color3B lineColor_all    = Color3B(0, 255, 255);
static const Color3B lineColor_friend = Color3B(255, 255, 0);
static const Color3B lineColor_enemy  = Color3B(255, 0, 0);
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

GHashMap<EMapAllianceBuildType, RAllianceBuildInfo> _AllianceBuildInfo{
  {
    {EMapAllianceBuildType::Palace,  {2, 5, "Map_build_unionpalace.png"}},
    {EMapAllianceBuildType::Fort,    {2, 2, "Map_build_unionpalace.png"}},
    {EMapAllianceBuildType::WarHall, {2, 0, "Map_build_unionpalace.png"}},
    {EMapAllianceBuildType::Shelter, {2, 0, "Map_build_unionpalace.png"}},
    {EMapAllianceBuildType::KnowledgeTower, {2, 0, "Map_build_unionpalace.png"}},
    {EMapAllianceBuildType::Flag,    {1, 2, "Map_build_alliance_flagpole.png"}},
    {EMapAllianceBuildType::Altar,   {2, -2, "icon_alliance_beast_build.png"}},
    {EMapAllianceBuildType::PriPalace,   {2, 5, "Map_build_unionpalace.png"}}
  }
};



GOpt<RAllianceBuildInfo> WorldMapDefine::GetAllianceBuildInfo(EMapAllianceBuildType pBuild){
  if(_AllianceBuildInfo.Contains(pBuild)){
    return _AllianceBuildInfo[pBuild];
  }
  return {};
}

EResourceType WorldMapDefine::GetAllianceResourceType(int32 pResourceClassID){
  return EResourceType::Food;
}

GString WorldMapDefine::GetAllianceResourceImageName(int32 pResourceClassID){
  return "alliance_mineral_shuijingkuang.png";
}

GString WorldMapDefine::GetAllianceResourceName(int32 pResourceClassID){
  return "alliance_build_name_05";
}

bool WorldMapDefine::HasBossHdRes(EBossType pBossID, uint32 pLevel){
  return true;
}

RBossShowData WorldMapDefine::GetWorldBossShow(EBossType pBossID, uint32 pLevel){
  return RBossShowData();
}

Node *WorldMapDefine::CreateAttackEffectCsb(const RAttackEffectData &pData){
  // local node = SoraDCreatAnimationEx(data.nodeName)
  // node:setPosition(data.pos or cc.p(0, 0))
  // node:setName("attackEffectNode")
  // local scale = data.scale or 1
  // if data.isFlipX then
  //   node:setScale(-scale, scale)
  // else
  //   node:setScale(scale)
  // end
  // local Node_effect = node:getChildByName("Node_effect")
  // if Node_effect then
  //   Node_effect:setGroupID(data.groupID1)
  //   Node_effect:setGroupAuto(true)
  // end
  // local Sprite_main = node:getChildByName("Sprite_main")
  // if Sprite_main then
  //   Sprite_main:setGroupID(data.groupID2)
  // end
  // local Node_GLONE = SoraDGetChildByName(node, "Node_GLONE")
  // if Node_GLONE then
  //   for k, v in pairs(Node_GLONE:getChildren()) do
  //     SoraDMixtureGLONE(v)
  //   end
  // end
  // return node
  return GDisplay::Get()->NewNode();
}

bool WorldMapDefine::IsWorldBossCanAttackAlone(EBossType pBossID, uint32 pLevel){
  return false;
}

RChestBackShow WorldMapDefine::GetChestpackShow(int32 pChestID){
  return RChestBackShow();
}

uint32 WorldMapDefine::GetWarTreasureCastleLv(int32 pResourceClassID){
  return 1;
}

GString WorldMapDefine::GetWarTreasureBuildingName(int32 pResourceClassID){
  return "GetWarTreasureBuildingName";
}

RTreasureBowl WorldMapDefine::GetTreasureBowlpackShow(int32 pTreasureBowlClassID){
  RTreasureBowl lRet;
    lRet._Index = 1;
    lRet._Image = "icon_TreasureBowl.png";
    lRet._Effects = "zhouniangz";
    lRet._Delay = 2;
    lRet._Name = "common_text_3549";
    lRet._Notice1 = "common_text_3547";
    lRet._Notice2 = "common_text_3548";
    lRet._IconLod = "lod_monster.png";
    lRet._ScaleLod = 3;
  return lRet;
}
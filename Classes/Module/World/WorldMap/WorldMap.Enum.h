#pragma once

enum class EKingdomClassType{
  None = 0,
  Normal = 1,
  Pyramid = 2,
  LegendLord = 3,
  Ruins = 4,
  Remains = 4,
  DevilValley = 5,
  NewTrial = 5,
  Radiance = 6,
  Atlantis = 7,
  Nebula = 8
};

enum class EMapObjTypeDef{
  None = 0,
  mapTypePlain = 1,
  mapObjTypePlayer = 4,
  mapObjTypeResource = 5,
  mapObjTypeNpc = 6,
  mapObjTypeRelics = 7,
  mapObjTypeCampsite = 8,
  mapObjTypeCastale = 9,
  mapObjTypeBattery = 10,
  mapObjTypeTreasure = 12,
  mapObjTypeChest = 13,
  mapObjTypeSuperResource = 14,
  mapObjTypeBoss = 15,
  mapObjTypeEscort = 16,
  mapObjTypeBattlefieldSite = 17,
  mapObjTypeFortress = 18,
  mapObjTypeAllianceBuild = 19,
  mapTypeTreasureBowl = 20,
  mapObjTypeKingdomLevelBuild = 21,
  mapObjTypeLegendLord = 22,
  mapTypeHeroBattleBoss1 = 23,
  mapTypeHeroBattleBoss2 = 24,
  mapObjTypeRemainsWar = 25,
  mapTypeMonsterFiesta = 26,
  mapObjTypeChristmasTree = 26,
  mapObjNewTrialCity = 27,
  mapObjSeaMonsterInvade = 28,
  mapTypeWrathBeast = 29,
  mapTypeEndlessTrialsPortal = 30,
  mapTypeATBuilding = 31,
  mapTypeWerewolf = 32,
  mapTypeFireTreasure = 33,
  mapTypeWarTreasure = 34,
  mapTypeFortyThieves = 35,
  mapTypeRadianceWarPalace = 36,
  mapTypeRadianceWarGate = 37,
  mapTypeRadianceWarBeacon = 38,
  mapTypeRadianceWarResource = 39,
  mapTypeSemluk = 40,
  mapTypePyramidGloryBuild = 41,
  mapType20Campfire = 42,
  mapTypeLostRuins = 43,
  mapTypeHuntFair = 44,
  mapTypeIceSnowWonder = 45,
  mapTypeWindTower = 46,
  mapTypeRamadanFeast = 47,
  mapTypeAtlantisWarBuilding = 48,
  mapTypeAtlantisWarBoss = 49,
  mapTypeMine = 50,
  stronghold = 51,
  wastelandBoss = 52,
  mapTypeSnowWolfLost = 53,
  starTreasure = 54,
  nebulaWarBuilding = 55,
  nebulaNpc = 56,
  nebulaWarMine = 57,
  fireDragon1 = 58,
  fireDragon2 = 59,
  desertMeteorite = 60
};


enum class EWorldLodDef {
  None = 0,
  LOD1 = 1,
  LOD2 = 2,
  LOD3 = 3,
  LOD4 = 4,
  LOD5 = 5,
  LOD6 = 6
};

enum class EWorldMapZOrder {
  tmxView = -20,
  rolygonView = -18,
  selectBgView = -15,
  warLvBase = -14,
  objBgView = -13,
  objCastleBgView = -12,
  objLevelBg = -11,
  containerView = -10,
  containerViewSelf = -5,
  objFgView = -2,
  scrollView = 0,
  containerViewNode = 3,
  moveLine = 5,
  moveLineFg = 6,
  animateLayerFg = 7,
  transView = 8,
  selectView = 10,
  otherTipView = 30,
  topTipView = 50
};


enum class EWorldMapLayInstance {
  None = 0,
  City = 1,
  AllianceResource = 2,
  AllianceManor = 3,
  Boss = 4,
  Feast = 5
};

enum class EMapSyncMsgType{
  ADD_PIECE_MAP = 1,
  ADD_MAPOBJ = 2,
  REMOVE_MAPOBJ = 3,
  UPDATE_MAPOBJ = 4,
  FLASH_ON_MAPOBJ = 5,
  ADD_PIECE_QUEUE = 11,
  ADD_QUEUE = 12,
  REMOVE_QUEUE = 13,
  UPDATE_QUEUE = 14,
  UPDATE_SUPER_RES = 15,
  SYNC_NUM = 21
};

enum class EWorldMapAllianceMarkType{
  None,
  _1, _2,  _3,
  _4, _5, _6,
  _7, _8, _9,
  _10
};

enum class EWorldMapTipButtonType{
  shuoMing = 1,
  yongHuXinxi = 2,
  qianCheng = 3,
  yaoqingQianCheng = 4,
  zhanLing = 5,
  tanXian = 6,
  fanHui = 7,
  zhenCha = 8,
  gongJi = 9,
  xuanZhan = 10,
  shibingYuabzhu = 11,
  chakanYuanjun = 12,
  ziyuanYuanzhu = 13,
  jijieBuduiXinxi = 14,
  chengshiZengyi = 15,
  jinruChengshi = 16,
  buDui = 17,
  zhaoHui = 18,
  jiesan = 19,
  jiaSu = 20,
  buDuiXiangqing = 21,
  zhuangTai = 22,
  guanZhi = 23,
  renMing = 24,
  guanliWangguo = 25,
  zuduiYuanzhu = 26,
  luomaZhanhunLaixi = 27,
  fangzhi = 28,
  caiji = 29,
  jianzao = 30,
  chakanxiangqing = 31,
  yayun = 32,
  bangzhuyayun = 33,
  tuijianlueduo = 34,
  kaiqijiacheng = 35,
  junqing = 36,
  lueduo = 37,
  yuanzhujiacheng = 38,
  xiefang = 39,
  chakanzhujun = 40,
  xiangqing = 41,
  lingdiqianCheng = 42,
  lianmengjianzhu = 43,
  lianmengqizhi = 44,
  qianru = 45,
  baoxiang = 46,
  leaguerenMing = 47,
  biaoqingyinzhang = 48,
  hegemonrenMing = 49,
  prisonerIn = 50,
  alliancepet_1 = 51,
  alliancepet_2 = 52,
  alliancepet_3 = 53,
  alliancepet_4 = 54,
  remains_buff = 55,
  decorate = 56,
  remains_watchTower = 57,
  remains_allianceWar = 58,
  remains_mail = 59,
  intetior = 60,
  tanmingmibao = 61,
  wajuexiangqing = 62,
  zuduiwajue = 63,
  wajue = 64,
  treasuremap_wajue = 65,
  sign = 66,
  duel = 67,
  cancel = 68,
  cancel_cancel = 69,
  build_info = 70,
  anniversary_flame = 71,
  explore = 72,
  ramadan_world_explore = 73,
  nebula_caiji = 74,
  caijixiangqing = 75,
  kingStar_renMing = 76,
  commandHallNpc = 77,
  desertMeteorite = 78,
};

enum class EMapMoveLineServerType{
  None = 0,
  KillNpc = 1,
  AttackLord = 2,
  Scout = 3,
  CollResource = 4,
  RelicsExplore = 5,
  ToCamp = 6,
  ResourceHelp = 7,
  ArmyHelp = 8,
  Mass = 9,
  Return = 10,
  AttackCamp = 11,
  AttackResource = 12,
  MassSlave = 13,
  OccupyMass = 14,
  Occupy = 15,
  NpcAttack = 16,
  DigTreasure = 17,
  AttackTreasure = 18,
  Chest = 19,
  SuperResource = 20,
  MassBoss = 21,
  Escort = 22,
  EscortAssist = 23,
  EscortRob = 24,
  GuardAllianceBuild = 27,
  AttackAllianceBuild = 28,
  MassAllianceBuild = 29,
  MassABeast = 30,
  Tree = 34,
  KillWBeast = 35,
  MassWBeast = 36,
  ATBuilding = 37,
  MassATBuilding = 38,
  CollTorchMine = 39,
  AtkTorchMine = 40,
  CollWarTreasure = 41,
  AttackWarTreasure = 42,
  CollRadianceWarResource = 43,
  AnnCampfire = 44,
  KillBoss = 45,
  Survey = 46,
  RamadanFeast = 47,
  MassAtlantisBoss = 48,
  killStrongholdNpc = 49,
  collNebulaWarMine = 50,
  commandHallNpc = 51,
  exploreDesertMeteorite = 52
};

enum class EMapMoveLineType  {
  None = 0,
  AttackLord = 1,
  Scout = 2,
  capture = 3,
  RelicsExplore = 4,
  ResourceHelp = 5,
  ArmyHelp = 6,
  Mass = 7,
  Return = 8,
  RomanSoul = 9,
  SuperRes = 10,
  Escort = 11,
  EscortRob = 12,
  EscortHelp = 13,
  AnnCampfire = 14,
  CommandHallNpc = 15,
  DesertMeteorite = 16
};

enum class EMapMoveLineModel {
  None = 0,
  GoOut = 1, 
  GoBack = 2
};

enum class EMapMoveLineColor {
  None = 0,
  White = 1,
  Green = 2,
  Red = 3,
  Purple = 4,
  Blue = 5,
  Yellow = 6,
  Azure = 7
};

enum class EMapMoveLineMatrixType{
  None = 0,
  Troop = 1,
  Detection = 2,
  Collection = 3,
  Trade = 4,
  RomanSoul = 5,
  Chest = 6,
  Escort = 7,
  EscortRob = 8,
  EscortHelp = 9,
  HeroBack = 10,
  NewTrial = 11,
  CommandHall = 12
};

enum class EMapMoveLineStatusType {
  Rally = 0,
  Moving = 1,
  Working = 2,
  Finished = 3
};

enum class EMapMoveLineAttrType {
  None = 0,
  Normal = 1, 
  WarArea = 2
};

enum class EWorldMapCastleEffectID {
  None = 0,
  Crystal_Heart = 9004501,
  Flowery_Firework = 9004502,
  Festival_Firework = 9004503,
  Rainbow_castle = 9004504,
  Victory_Firework = 9004505,
  NewYear_FireWork_2020 = 9004506,
  Snow_iceArea = 9004507,
  Ramadan_Shining = 9004508,
  JACK_O_LANTERN_ID = 9002611,
  Snow_Ball_Troop_ID = 9003801,
  Panther_Troop_ID1 = 9004001,
  Panther_Troop_ID2 = 9004002,
  Panther_Troop_ID3 = 9004003,
  Lion_Troop_ID = 9002315,
  Shining_Castle = 9004508,
  Shining_Castle_2 = 9004509,
  Snow_Effect = 9004510,
  King_Troop_ID = 9002302,
  Shining_Castle_3 = 9004511,
  FirewWork_Ceremony = 9004512,
  IceWolf_Castle = 9004513,
  NewYear_FireWork_2022 = 9004514
};

enum class ECommandHallTaskType{
  None = 0,
  REBEL_ARMY_GROUP_TASK = 1,
  REBEL_ARMY_PIONEER_TASK = 2,
  DIALOGUE_TASK = 3,
  RESCUE_TASK = 4,
  BATTLE_TASK = 5,
  SNIPE_HUNTER_TASK = 6
};

enum class EGrouID  {
  None = 0,
  group_instance = 100,
  buildingBatchNode = 101,
  castleBatchNode = 102,
  batteryBatchNode = 103,
  monsterBatchNode = 104,
  bossBatchNode = 105,
  pyramidBatchNode = 106,
  palaceBatchNode = 107,
  castleSkin1BatchNode = 108,
  monsterFiestaBatchNode = 109,
  monsterSeaBatchNode = 110,
  wrathBeastBatchNode = 111,
  tileEffectBatchNode = 112,
  tileEffectGLONEBatchNode = 113,
  endlessTrialBatchNode = 114,
  castleSkin2BatchNode = 115,
  buildRadiance = 116,
  monsterSemlukBatchNode = 117,
  feastBatchNode = 118,
  castleSkin3BatchNode = 119,
  monsterNebulaBatchNode = 120,
  attackEffectBatchNode = 128,
  group_warLv_base = 130,
  group_warLv_base_particle = 131,
  group_warLv_top = 132,
  group_warLv_top_particle = 133,
  group_particle_bg = 134,
  build_star_normal = 135,
  build_star_glone = 136,
  build_star_particle = 137,
  group_emoji = 140,
  group_moveline = 150,
  group_moveline_particle = 151,
  group_moveline_panther = 152,
  group_moveline_particle_bg = 153,
  group_moveline_fighting = 154,
  group_moveline_lion = 155,
  group_moveline_whiteTiger = 156,
  group_moveline_lodicon = 157,
  group_moveline_charge = 158,
  group_moveline_charge_bg = 159,
  group_moveline_sniper_bg = 160,
  group_moveline_sniper = 161,
  group_moveline_trick_bg = 162,
  group_moveline_trick = 163,
  group_moveline_worldcup = 164,
  group_level_build = 200,
  group_level_monster = 201,
  group_flag = 202,
  group_night_effect = 203,
  group_text = 204,
  group_protect = 205,
  group_border = 206,
  group_text_monster = 207,
  group_animate_object_bg = 210,
  group_animate_object_fg = 211,
  group_animate_object_top = 212,
  group_animate_tmx_bg = 213,
  group_progress_monster = 214,
  group_alliance_pet = 215,
  group_protect_new = 216,
  group_build_color = 217,
  group_build_bg = 218,
  group_build_effect = 219,
  group_build_light = 220,
  group_build_light_et = 221,
  group_moveline_text = 222,
  group_build_gate = 223,
  group_lod_icon = 224,
  group_sign = 225
};

enum class EWorldMapLeagueManorUpdateType {
  None = 0,
  Add = 1,
  Remove = 2,
  Activity = 3,
  RelationChange = 4
};

enum class EManorlineSn{
  strongHold = -2,
  placePreview = -1,
  None = 0
};

enum class EWorldMapCastleEffectID {
  None = 0,
  Crystal_Heart = 9004501,
  Flowery_Firework = 9004502,
  Festival_Firework = 9004503,
  Rainbow_castle = 9004504,
  Victory_Firework = 9004505,
  NewYear_FireWork_2020 = 9004506,
  Snow_iceArea = 9004507,
  Ramadan_Shining = 9004508,
  JACK_O_LANTERN_ID = 9002611,
  Snow_Ball_Troop_ID = 9003801,
  Panther_Troop_ID1 = 9004001,
  Panther_Troop_ID2 = 9004002,
  Panther_Troop_ID3 = 9004003,
  Lion_Troop_ID = 9002315,
  Shining_Castle = 9004508,
  Shining_Castle_2 = 9004509,
  Snow_Effect = 9004510,
  King_Troop_ID = 9002302,
  Shining_Castle_3 = 9004511,
  FirewWork_Ceremony = 9004512,
  IceWolf_Castle = 9004513,
  NewYear_FireWork_2022 = 9004514
};


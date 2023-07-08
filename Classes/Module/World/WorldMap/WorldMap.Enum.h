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


enum class EWorldLodDef {
  None = 0,
  LOD1 = 1,
  LOD2 = 2,
  LOD3 = 3,
  LOD4 = 4,
  LOD5 = 5,
  LOD6 = 6
};

enum class ELodLayer {
  None = 0,
  LOD_LAYER_NORMAL = 1,
  LOD_LAYER_NPC = 2,
  LOD_LAYER_ALLIANCE = 3,
  LOD_LAYER_SELF = 4,
  LOD_LAYER_CASTLE = 5,
  LOD_LAYER_ALLIANCERES = 6,
  LOD_LAYER_ALLIANCESTRONG = 7,
  LOD_LAYER_MONSTER = 8,
  LOD_LAYER_BOSS = 9,
  LOD_LAYER_NEBULA = 10,
  LOD_LAYER_NEBULA_4 = 11
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
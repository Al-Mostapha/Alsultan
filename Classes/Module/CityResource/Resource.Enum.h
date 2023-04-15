#pragma once

#include "Include/IncludeBase.h"

enum class EResource { 
  None = 0, 
  Gold = 1001, 
  Food = 1002, 
  Wood = 1003, 
  Iron = 1004, 
  Mithril = 1005, 
  Steel = 1006, 
  Crystal = 1027,
  MeteorCrystal = 1620
};

enum class EResBuyViewType {
  None = 0,
  Build = 1,
  Upgrade = 2,
  TRAIN_ARMY = 3,
  TRAIN_TRAP = 4,
  STUDY_SCIENCE = 5,
  EQUIP_BAPTIZE = 6,
  EQUIP_INTENSIFY = 7,
  PROMOTE_ARMY = 8,
  UPGRADE_STAR = 9,
  WARFRAME_FORG = 10,
  BUILD_STATUE_BRAVE = 11,
  WAR_GEM_REPLACE = 12,
  MGAGIC_LAMP_STRENGTH = 13
};
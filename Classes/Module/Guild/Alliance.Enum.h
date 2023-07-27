#pragma once

enum class EAllianceRank{
  R0 = 0,
  R1 = 1,
  R2 = 2,
  R3 = 3,
  R4 = 4,
  R5 = 5,
  Official = 6
};

enum class EARecruit{
  None = 0,
  Public = 1,
  Private = 2
};

enum class EEscortAddState {
  None = 0,
  Close = 1,
  Opening = 2,
  Opened = 3
};

enum class EAllianceBuildingStatus{
  FREE = 1,
  BUILD = 2,
  COMPLETE = 3,
  LOCK = 10,
  UNSET = 11,
  NONE = 0,
  PERFECT = 1,
  BURNING = 2,
  RECOVERING = 3,
  DESTROY = 4,
  BUILDING = 5
};

enum class EMapAllianceRelationType{
  None = 0,
  ALLY,
  FRIENDLY,
  ENEMY,
  SELF,
  NORMAL
};
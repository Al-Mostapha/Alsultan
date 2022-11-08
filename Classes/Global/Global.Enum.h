#pragma once 


enum class ESpeedType{
  None = 0,
  Free = 1,
  Gold = 2,
  Item = 3
};

enum class ETouchEventType{
  None = 0,
  Begin = 1,
  Move = 2,
  End = 3,
  Cancel = 4
};

enum class EFactionType{
  None = 0,
  Normal = 1
};

enum class EScene{
  None,
  LogIn,
  City,
  World
};

enum class EKingdomClass{
  None
};

enum class ENoticeIcon{
  None = -1,
  Build = 0,
  Item = 1,
  Solider = 2,
  Resource = 3,
  Tech = 4,
  Army = 5,
  Reward = 6,
  Normal = 7
};

enum class EMsgBoxCallBack{
  None = 0,
  Yes = 0,
  No = 1,
  Cancel = 2,
  SpeedUp = 3,
  Other = 4,
  TimeEnd = 5,
};
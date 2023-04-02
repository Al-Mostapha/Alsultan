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
  Normal = 1,
  Byzantine = 2
};

enum class EScene{
  None,
  LogIn,
  City,
  World
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

enum class EMainUIStyle{
  None = 0,
  Easter = 1,
  Halloween = 2,
  Chritmas = 3,
  QuickSand = 4,
  RosNormal = 5
};

enum class ELuckyBlessActivityEffectType{
  None = 0,
  BuildUpgrade = 1,
  TechnologyResearch = 2,
  TrainSoldiers = 3,
  BuildStrength = 4
};


enum class ELoginRangeTbl {
  None = 0,
  GameUpdate = 1,
  LoadImages = 2,
  ConnectServer = 3,
  ObbUpdate = 4,
  ObbValidate = 5
};

enum class ELoginFailType {
  None = 0,
  Client = 1,
  Server = 2,
  Version = 3,
  StartLogin = 4,
  GetUserInfo = 5,
  SdkTokenError = 6
};

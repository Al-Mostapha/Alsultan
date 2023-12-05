#pragma once

class HeroModule{
  public:
  static HeroModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
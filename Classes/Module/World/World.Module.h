#pragma once

class WorldModule{
  public:
  static WorldModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
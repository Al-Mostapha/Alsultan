#pragma once

class ItemModule{
  public:
  static ItemModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
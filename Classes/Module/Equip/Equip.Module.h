#pragma once


class EquipModule{
  public:
  static EquipModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
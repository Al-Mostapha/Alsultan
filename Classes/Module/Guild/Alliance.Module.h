#pragma once


class AllianceModule{
  public:
  static AllianceModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
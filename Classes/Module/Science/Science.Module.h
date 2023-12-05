#pragma once

class ScienceModule{
  public:
  static ScienceModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
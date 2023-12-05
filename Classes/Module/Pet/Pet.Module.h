#pragma once

class PetModule{
  public:
  static PetModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};
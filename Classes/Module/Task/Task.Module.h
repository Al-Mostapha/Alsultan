#pragma once

class TaskModule{
  public:
  static TaskModule *Get();
  void Init();
  void StartGame();
  private:
    void Load();
};

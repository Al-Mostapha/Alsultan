#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XFunction.h"

class JsonFileLoader{
  
  GFunc<void()> _CallBack;
  public:
  static JsonFileLoader *Get();
  void Init();
  void Load(const GFunc<void()> &pCallback = nullptr);
  void SetFinishCallback(const GFunc<void()> &pCallback = nullptr);
  private:
    void Load(const GString &p_FileName, GFunc<void()> p_Callback);
    void LoadCityFiles();
    void LoadBuildingFiles();
    void LoadPlayerFiles();
};
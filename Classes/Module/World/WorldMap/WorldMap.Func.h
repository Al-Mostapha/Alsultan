#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class WorldMapFunction{
  public:
    static WorldMapFunction *Get();
    GTuple<float, GString, bool> GetMonsterImgAngel(Vec2 pBeginPoint, Vec2 pEndPoint);
    void CreateThrowAction(
      Node *pNode, const Vec2 &pBeginPoint, const Vec2 &pEndPoint, float pDelayTime = 0,
      float pSpeed = 300 , const std::function<void()> &pCallBack = nullptr
    );
    GTuple<float, GString, bool> GetBatteryImgAngel(Vec2 pBeginPoint, Vec2 pEndPoint);
};
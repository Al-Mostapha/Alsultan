#include "WorldMap.Func.h"
#include "Base/Base.Geometry.h"

WorldMapFunction *WorldMapFunction::Get(){
  static WorldMapFunction lInstance;
  return &lInstance;
}

GTuple<float, GString, bool> WorldMapFunction::GetMonsterImgAngel(Vec2 pBeginPoint, Vec2 pEndPoint){
  GString lImgNameAngle = "wn";
  bool lIsFlipX = false;
  auto lRotation = -GBase::DGetAngleByPos(pBeginPoint, pEndPoint);
  if(lRotation >= 0 && lRotation < 90){
    lImgNameAngle = "ws";
    lIsFlipX = true;
  }else if(lRotation >= 90 && lRotation < 180){
    lImgNameAngle = "ws";
    lIsFlipX = false;
  }else if(lRotation >= -180 && lRotation < -90){
    lImgNameAngle = "wn";
    lIsFlipX = false;
  } else if(lRotation >= -90 && lRotation < 0){
    lImgNameAngle = "wn";
    lIsFlipX = true;
  }
  return {lRotation, lImgNameAngle, lIsFlipX};
}

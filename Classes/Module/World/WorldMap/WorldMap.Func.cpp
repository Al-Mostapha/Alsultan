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

void WorldMapFunction::CreateThrowAction(
  Node *pNode, const Vec2 &pBeginPoint, const Vec2 &pEndPoint,
  float pDelayTime, float pSpeed, std::function<void()> pCallBack
){
  // if not target then
  //   return
  // end
  // target:setVisible(false)
  // delayTime = delayTime or 0
  // speed = speed or 300
  // local distance = cc.pGetDistance(beginPoint, endPoint)
  // local actionTime = math.abs(distance) / speed
  // local rotationAngel = SoraDGetAngleByPos(beginPoint, endPoint)
  // local changeAngel = 5 + 50 * math.abs(math.abs(rotationAngel) - 90) / 90
  // local controlAngel = rotationAngel + changeAngel
  // if rotationAngel > 90 or rotationAngel < -90 then
  //   controlAngel = rotationAngel - changeAngel
  // end
  // local radian = math.angle2radian(controlAngel)
  // local pointX = beginPoint.x + 0.5 * distance * math.cos(radian)
  // local pointY = beginPoint.y + 0.5 * distance * math.sin(radian)
  // local controlPoint = cc.p(pointX, pointY)
  // local bezier = {
  //   beginPoint,
  //   controlPoint,
  //   endPoint
  // }
  // local bezierTo = cc.BezierTo:create(actionTime, bezier)
  // local startAngel = SoraDGetAngleByPos(beginPoint, controlPoint)
  // local endAngel = SoraDGetAngleByPos(controlPoint, endPoint)
  // target:setRotation(-(startAngel - 90))
  // local rotateTo = cc.RotateTo:create(actionTime, -(endAngel - 90))
  // local bezierAction = cc.Spawn:create(bezierTo, rotateTo)
  // local actionsArray = {}
  // actionsArray[#actionsArray + 1] = cc.DelayTime:create(delayTime)
  // actionsArray[#actionsArray + 1] = cc.CallFunc:create(function()
  //   target:setVisible(true)
  // end)
  // actionsArray[#actionsArray + 1] = cc.Spawn:create(bezierTo, rotateTo)
  // actionsArray[#actionsArray + 1] = cc.CallFunc:create(function()
  //   target:removeFromParent()
  //   if endCallFunc then
  //     endCallFunc()
  //   end
  // end)
  // local action = transition.sequence(actionsArray)
  // target:runAction(action)
}

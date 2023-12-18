#include "Utils3D.h"
#include "Engine/Display.h"
#include "Base/Math/Math.Base.h"

Vec3 Sub3D(Vec4 p1, Vec3 p2){
  return {
    p1.x - p2.x,
    p1.y - p2.y,
    p1.z - p2.z
  };
}

GPair<bool,Vec3> GBase::RayIntersectsPlane(RRayIntersect p_Ray, RPlanIntersect p_Plan){
  auto l_P0 = Sub3D(p_Plan._Pos, p_Ray._Origin);
  auto l_DotDN = p_Ray._Direction.dot(p_Plan._Normal);
  if(GMath::Abs(l_DotDN) < 1.0e-6)
    return GPair<bool, Vec3>(false, Vec3::ZERO);
  auto l_T = l_P0.dot(p_Plan._Normal) / l_DotDN;
  auto l_Pt = p_Ray._Origin + (p_Ray._Direction * l_T);
  return GPair<bool, Vec3>(true, l_Pt);
}

Vec4 GBase::ConvertToWorldSpace3D(Node *p_Target, Vec2 p_Pos){
  Vec4 _NodePos3D = {
    p_Pos.x,
    p_Pos.y, 
    0, 1
  };
  auto l_ValMat4ToWorld = p_Target->getNodeToWorldTransform();
  auto l_Mat4ToWorld = Mat4(l_ValMat4ToWorld);
  l_Mat4ToWorld.transformVector(&_NodePos3D);
  return _NodePos3D;
}

Vec4 GBase::ConvertToWorldSpace2DOr3D(Node *p_Target, Vec2 p_NodePos){
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    return ConvertToWorldSpace3D(p_Target, p_NodePos);
  }

  auto l_2DPoint = p_Target->convertToWorldSpace(p_NodePos);
  Vec4 l_3DPoint ;
  l_3DPoint.x = l_2DPoint.x;
  l_3DPoint.y = l_2DPoint.y;

  return l_3DPoint;
}

Vec4 GBase::ConvertToNodeSpace3D(Node *p_Target, Vec4 p_World3DPos){
  auto l_ValMat4ToNode = p_Target->getWorldToNodeTransform();
  p_World3DPos.w = 1;
  l_ValMat4ToNode.transformVector(&p_World3DPos);
  return p_World3DPos;
}

GPair<bool, Vec3> GBase::DGet3DTouchPos(Node *p_Target, Vec2 p_TouchPos, GOpt<Vec2> p_Params){
  auto l_RotationX = GGlobal::Get()->gWorldMapRotation3D_X;
  if(p_Params)
    l_RotationX = p_Params.value().x;
  auto l_ZEye = Director::getInstance()->getZEye();

  RRayIntersect l_Ray;
  l_Ray._Origin.x = GDisplay::Get()->width /2;
  l_Ray._Origin.y = GDisplay::Get()->rheight /2;
  l_Ray._Origin.z = l_ZEye;

  l_Ray._Direction.x = p_TouchPos.x - l_Ray._Origin.x;
  l_Ray._Direction.y = p_TouchPos.y - l_Ray._Origin.y;
  l_Ray._Direction.z = 0 - l_Ray._Origin.z;
  
  RPlanIntersect l_Plane;
  l_Plane._Normal.x = 0;
  l_Plane._Normal.y = GMath::Abs(GMath::Sin(GMath::Rad(l_RotationX)));
  l_Plane._Normal.z = GMath::Abs(GMath::Cos(GMath::Rad(l_RotationX)));

  l_Plane._Normal.normalize();
  l_Plane._Pos = {0, 0, 0, 1}; 
  auto l_PanelPoint = Vec2(l_Plane._Pos.x, l_Plane._Pos.y);
   l_Plane._Pos = ConvertToWorldSpace3D(p_Target, l_PanelPoint);
  return RayIntersectsPlane(l_Ray, l_Plane);
}

GOpt<Vec4> GBase::ConvertTouchToNodeSpace3D(Node *p_Target, Vec2 p_TouchPos, GOpt<Vec2> p_Rotation){
  auto [l_Ret, l_Touch3D] = DGet3DTouchPos(p_Target, p_TouchPos, p_Rotation);
  if(l_Ret){
    auto l_4DTouchPos = Vec4( p_TouchPos.x, p_TouchPos.y, 0, 0 );
    return  ConvertToNodeSpace3D(p_Target, l_4DTouchPos);
  }
  return {};
}

GOpt<Vec4> GBase::ConvertTouchToNodeSpace2DOr3D(Node *p_Target, Vec2 p_TouchPos, Vec2 P_Rotation){
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    return ConvertTouchToNodeSpace3D(p_Target, p_TouchPos, P_Rotation);
  }
  auto l_2DPointSpace = p_Target->convertToNodeSpace(p_TouchPos);

  return Vec4{
    l_2DPointSpace.x, l_2DPointSpace.y, 0, 0
  };
}

Vec4 GBase::DConvertToPoint3D(Node *p_Target1, Vec2 p_TargetPos, Node *p_Target2 ){
  auto l_WorldPoint = ConvertToWorldSpace3D(p_Target1, p_TargetPos);
  return ConvertToNodeSpace3D(p_Target2, l_WorldPoint);
}

Vec2 GBase::DCoverToPoint(Node *p_Node1, Vec2 p_TargetPoint, Node *p_Node2){
  auto l_WorldPoint = p_Node1->convertToWorldSpace(p_TargetPoint);
  return p_Node2->convertToNodeSpace(l_WorldPoint);
}

Vec4 GBase::DCoverToPoint2DOr3D(Node *p_Node1, Vec2& p_TargetPoint, Node *p_Node2, bool p_Enable3d ){
  if(p_Enable3d){
    return DConvertToPoint3D(p_Node1, p_TargetPoint, p_Node2);
  }
  auto l_Out = DCoverToPoint(p_Node1, p_TargetPoint, p_Node2);
  return {
    l_Out.x, l_Out.y,
    0, 0
  };
}

GOpt<Vec3> GBase::DConvertoScreenPos3D(Node *p_Target, Vec3 p_NodePos){
  
  auto l_WorldPos3D = ConvertToWorldSpace3D(p_Target, Vec2(p_NodePos.x, p_NodePos.y));
  auto l_ZEye = Director::getInstance()->getZEye();

  RRayIntersect l_Ray;
  l_Ray._Origin.x = GDisplay::Get()->width / 2;
  l_Ray._Origin.y = GDisplay::Get()->rheight / 2;
  l_Ray._Origin.z = l_ZEye;
  l_Ray._Direction = Sub3D(l_WorldPos3D, l_Ray._Origin);

  RPlanIntersect l_Plane;
  l_Plane._Normal = Vec3(0, 0, 1);
  l_Plane._Normal.normalize();
  l_Plane._Pos = {0, 0, 0, 1};
  auto [l_Ret, l_Touch3DPos] = RayIntersectsPlane(l_Ray, l_Plane);
  if(l_Ret)
    return l_Touch3DPos;
  return {};
}

GOpt<Vec3> GBase::DConvertoScreenPos2DOr3D(Node *p_Target, Vec3 p_NodePos){
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    return DConvertoScreenPos3D(p_Target,  p_NodePos);
  }
  auto l_2DPos = p_Target->convertToWorldSpace(Vec2(p_NodePos.x, p_NodePos.y));
  return Vec3{
    l_2DPos.x, 
    l_2DPos.y,
    0
  };
}

Vec2 GBase::DProject2ScreenPos3D(Node *p_Target, Vec3 p_Pos){
  auto l_WorldPos4D = ConvertToWorldSpace3D(p_Target, Vec2(p_Pos.x, p_Pos.y));
  auto l_WorldPos3D = Vec3 {l_WorldPos4D.x, l_WorldPos4D.y, l_WorldPos4D.z};
  return Director::getInstance()->getRunningScene()->getDefaultCamera()->projectGL(l_WorldPos3D);
}

Vec2 GBase::DProjec2ScreenPos2DOr3D(Node *p_Target, Vec3 p_NodePos){
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    return DProject2ScreenPos3D(p_Target, p_NodePos);
  }
  return p_Target->convertToWorldSpace({p_NodePos.x, p_NodePos.y});
}

Vec2 GBase::DVerticalProject2ScreenPos3D(Node *p_Target, Vec2 p_Pos){
  auto l_WorldPos3D = GBase::ConvertToWorldSpace3D(p_Target, p_Pos);
  return {l_WorldPos3D.x, l_WorldPos3D.y};
}

Vec2 GBase::DVerticalProject2ScreenPos2DOr3D(Node *p_Target, Vec2 p_NodePos){
  if(GGlobal::Get()->gEnableWorldMap3D.value())
    return DVerticalProject2ScreenPos3D(p_Target, p_NodePos);
  return p_Target->convertToWorldSpace(p_NodePos);
}

GOpt<Vec3> GBase::DConvertScreenPoint2WorldPos3D(Node *p_Target, Vec2 p_ScreenPos){
  auto l_RotationX = GGlobal::Get()->gWorldMapRotation3D_X;
  Vec3 l_WorldPos3D = {
    p_ScreenPos.x, 
    p_ScreenPos.y,
    0
  };
  
  auto l_ZEye = Director::getInstance()->getZEye();
  RRayIntersect l_Ray;
  l_Ray._Origin = {
    GDisplay::Get()->width / 2,
    GDisplay::Get()->rheight / 2, 
    l_ZEye
  };
  l_Ray._Direction = l_WorldPos3D - l_Ray._Origin;
  
  RPlanIntersect l_Plane;
  l_Plane._Normal = {
    0,
    GMath::Abs(GMath::Sin(GMath::Rad(l_RotationX))),
    GMath::Abs(GMath::Cos(GMath::Rad(l_RotationX)))
  };
  l_Plane._Normal.normalize();
  l_Plane._Pos = {0,0,0,1};
  auto [l_Ret, l_Touch3DPos] = RayIntersectsPlane(l_Ray, l_Plane);
  GOpt<Vec3> l_Out = std::nullopt;
  if(l_Ret)
    return l_Touch3DPos;
  return {};
}

GOpt<Vec4> GBase::DConvertScreenPoint2NodePos3D(Node *p_Target, Vec2 p_ScreenPos){
  auto l_WorldPos = DConvertScreenPoint2WorldPos3D(p_Target, p_ScreenPos);
  if(l_WorldPos){
    return ConvertToNodeSpace3D(p_Target, {(*l_WorldPos).x, (*l_WorldPos).y, (*l_WorldPos).z, 0});
  }
  return {};
}

GOpt<Vec4> GBase::DConvertScreenPoint2NodePos2DOr3D(Node *p_Target, Vec2 p_ScreenPos){
  if(GGlobal::Get()->gEnableWorldMap3D.value())
    return DConvertScreenPoint2NodePos3D(p_Target, p_ScreenPos);
  auto l_2D = p_Target->convertToNodeSpace(p_ScreenPos);
  return Vec4{
    l_2D.x, l_2D.y,
    0, 0
  };
}

GTuple<bool, GVector<Vec2>> GBase::DLineIntersectRect(Vec2 pLineStart, Vec2 pLineEnd, Rect pRect){
  return {false, {}};
}







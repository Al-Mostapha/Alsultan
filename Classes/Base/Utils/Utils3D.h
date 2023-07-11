#pragma once
#include "Base/BaseTypeDef.h"
#include "Global/Global.h"
#include "Base/Containers/Pair.h"


USING_NS_CC;

struct RRayIntersect{
  Vec3 _Origin;
  Vec3 _Direction;
};

struct RPlanIntersect{
  Vec4 _Pos;
  Vec3 _Normal;
};

namespace GBase{
  GPair<bool,Vec3> RayIntersectsPlane(RRayIntersect p_Ray, RPlanIntersect p_Plan);
  Vec4 ConvertToWorldSpace3D(Node *p_Target, Vec2 p_NodePos);
  Vec4 ConvertToWorldSpace2DOr3D(Node *p_Target, Vec2 p_NodePos);
  Vec4 ConvertToNodeSpace3D(Node *p_Target, Vec4 p_World3DPos);
  GPair<bool, Vec3> DGet3DTouchPos(Node *, Vec2, GOpt<Vec2> p_Rotation = {});
  GOpt<Vec4> ConvertTouchToNodeSpace3D(Node *, Vec2, GOpt<Vec2> p_Rotation = {});
  GOpt<Vec4> ConvertTouchToNodeSpace2DOr3D(Node *p_Target, Vec2 p_TouchPos, Vec2 P_Rotation = Vec2::ZERO);
  Vec4 DConvertToPoint3D(Node *p_Target1, Vec2 p_TargetPos, Node *p_Target2 );
  Vec4 DCoverToPoint2DOr3D(Node *, Vec2&, Node * = nullptr, bool = GGlobal::Get()->gEnableWorldMap3D.value());
  GOpt<Vec3> DConvertoScreenPos3D(Node *p_Target, Vec3 p_NodePos);
  GOpt<Vec3> DConvertoScreenPos2DOr3D(Node *p_Target, Vec3 p_NodePos);
  Vec2 DProject2ScreenPos3D(Node *, Vec3);
  Vec2 DProjec2ScreenPos2DOr3D(Node *p_target, Vec3 p_NodePos);
  Vec2 DVerticalProject2ScreenPos3D(Node *p_Target, Vec2 p_Pos);
  Vec2 DVerticalProject2ScreenPos2DOr3D(Node *p_Target, Vec2 p_NodePos);
  GOpt<Vec3> DConvertScreenPoint2WorldPos3D(Node *p_Target, Vec2 p_ScreenPos);
  GOpt<Vec4> DConvertScreenPoint2NodePos3D(Node *p_Target, Vec2 p_ScreenPos);
  GOpt<Vec4> DConvertScreenPoint2NodePos2DOr3D(Node *p_Target, Vec2 p_ScreenPos);
  Vec2 DCoverToPoint(Node *p_Node1, Vec2 p_TargetPoint, Node *p_Node2);
  GTuple<bool, GVector<Vec2>> DLineIntersectRect(Vec2 pLineStart, Vec2 pLineEnd, Rect pRect);
};
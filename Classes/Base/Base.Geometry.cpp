#include "Base.Geometry.h"

namespace GBase {

  ELayoutAlignment DGetLayoutAlignment(){
    return ELayoutAlignment::Right;
  }

  Vec2 DFPoint(double p_X, double p_Y, double p_Target){
    Vec2 l_Point;
    l_Point = Vec2(p_X, p_Y);
    double l_Target = p_Target;
    double l_SizeW = 0;
    l_SizeW = p_Target;
    if(DGetLayoutAlignment() == ELayoutAlignment::Right)
      return l_Point;
    if(l_Point.x)
      return Vec2(l_SizeW - l_Point.x, l_Point.y);
    return l_Point;
  }

  float DFPosX(float p_X, float p_Target){
  //     local sizeW = 0
  auto l_SizeW = 0;
  if(p_Target == 0)
    l_SizeW = 640;
  else  
    l_SizeW = p_Target;
  return p_X;
  // if SoraDGetLayoutAlignment() == gLayoutAlignmentTypeDef.right then
  //   return x
  // elseif x then
  //   return sizeW - x
  // else
  //   print("SoraDFPoint err p")
  // end
  }


}
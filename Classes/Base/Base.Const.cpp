
#include "Base.Const.h"

 bool GBase::GLobalSettings::ShowMsgTip = true;

DrawNode *GBase::Display::NewPolygon(const GVector<Vec2> &p_Points, const RPolygonProps &p_Props, DrawNode *p_DrawNode){
  GVector<Vec2> l_Points;
  for (int32 i = 0; i < p_Points.size(); i++){
    l_Points.push_back(Vec2(p_Points[i].x * p_Props.scale, p_Points[i].y * p_Props.scale));
  }
  if(!p_DrawNode)
    p_DrawNode = DrawNode::create();
  p_DrawNode->drawPolygon(l_Points.data(), l_Points.size(), p_Props.FillColor, p_Props.borderWidth, p_Props.BorderColor);
  return p_DrawNode;
}
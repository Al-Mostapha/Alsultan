#include "Base.Geometry.h"
#include "Include/IncludeEngine.h"
#include "Base/Math/Math.Base.h"
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
    auto l_SizeW = 0;
    if(p_Target == 0)
      l_SizeW = 640;
    else  
      l_SizeW = p_Target;
    if(GBase::DGetLayoutAlignment() == ELayoutAlignment::Right)
      return p_X;
    else if(p_X)
      return l_SizeW - p_X;
    return p_X;
  }

  float DFPosX(float p_X){
    return DFPosX(p_X, 0.f);
  }

  float DFPosX(float p_X, Node *p_Target){
    float l_SizeW = 0;
    if(p_Target && p_Target->getParent())
      l_SizeW = p_Target->getParent()->getContentSize().width;
    else 
      l_SizeW = 640;
    if(GBase::DGetLayoutAlignment() == ELayoutAlignment::Right)
      return p_X;
    else if(p_X)
      return l_SizeW - p_X;
    return p_X;
  }

  float DAlignNodeArray(GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding){
    CCAssert(p_Nodes.size(), "Nodes is empty");
    auto l_BeginX = 0;
    auto l_FNode  = p_Nodes[0];
    if(p_IsRA){
      l_BeginX = l_FNode->getPositionX() +
         (1-l_FNode->getAnchorPoint().x) *l_FNode->getScaleX() * l_FNode->getContentSize().width;
    }else{
      l_BeginX = l_FNode->getPositionX() - 
        l_FNode->getAnchorPoint().x * l_FNode->getScaleX() * l_FNode->getContentSize().width;
    }
    return DAlignNodeArrayOnBeginX(l_BeginX, p_Nodes, p_IsRA, p_padding);
  }

  void DAlignNodeArray(GVector<Node *> p_Nodes, bool p_IsRA, float p_padding){}

  float DAlignNodeArrayOnBeginX(float p_Begin, GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding){
    auto l_AccWidth = 0;
    auto l_PosX = 0;
    for(int32 ii = 0; ii < p_Nodes.size(); ii++){
      auto l_V = p_Nodes[ii];
      auto l_NodeWidth = l_V->getContentSize().width * l_V->getScaleX();
      auto l_NodeX = 0;
      if(p_IsRA)
        l_NodeX = p_Begin - l_AccWidth - ( 1 - l_V->getAnchorPoint().x ) * l_NodeWidth;
      else 
        l_NodeX = p_Begin + l_AccWidth + l_V->getAnchorPoint().x * l_NodeWidth;
      l_V->setPositionX(l_NodeX);
      if(p_padding.size() > ii)
        l_AccWidth += l_NodeWidth + p_padding[ii];
      else 
        l_AccWidth += l_NodeWidth;
    }
    return l_AccWidth;
  }

 float DAlignNodeArrayOnLimitX( GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding,
    bool p_LimitR, float p_LimitX){

    CCAssert(p_Nodes.size(), "Nodes is empty");
    float l_BeginX = 0;
    auto l_FN = p_Nodes[0];
    if(p_IsRA)
      l_BeginX = l_FN->getPositionX() + (1-l_FN->getAnchorPoint().x) *l_FN->getScaleX() * l_FN->getContentSize().width;
    else 
      l_BeginX = l_FN->getPositionX() - l_FN->getAnchorPoint().x * l_FN->getScaleX() * l_FN->getContentSize().width;
    float l_AccuWidth = 0;
    for(int32 iii = 0; iii < p_Nodes.size(); iii++){
      auto l_NodeWidth = p_Nodes[iii]->getContentSize().width *  p_Nodes[iii]->getScaleX();
      if(p_padding.size() > iii)
        l_AccuWidth += l_NodeWidth + p_padding[iii];
      else 
        l_AccuWidth += l_NodeWidth;
    }
    if(p_LimitR){
      if(p_IsRA){
        l_BeginX = p_LimitX;
      }else if(p_LimitX < l_BeginX + l_AccuWidth){
        l_BeginX = p_LimitX - l_AccuWidth;
      }
    }else{
      if(p_IsRA){
        if(p_LimitX > l_BeginX - l_AccuWidth)
          l_BeginX = p_LimitX + l_AccuWidth;
      }else if(p_LimitX < l_BeginX){
        l_BeginX = p_LimitX;
      }
    }
    return DAlignNodeArrayOnBeginX(l_BeginX, p_Nodes, p_IsRA, p_padding);
  }

  void DToCenter(Node *p_Node, float p_Interval, bool pIsReverse, bool pIsSize){
// function SoraDToCenter(node, interval, isReverse, isSize)
//   local targets = node:getChildren()
//   local totalLen = 0
//   local interval = interval or 10
//   local isReverse = isReverse or false
//   local len = 0
//   for k, v in pairs(targets) do
//     local width = 0
//     if not isSize and v.getVirtualRendererSize then
//       width = math.min(v:getVirtualRendererSize().width, v:getContentSize().width)
//       width = width * v:getScaleX()
//     else
//       width = v:getContentSize().width * v:getScaleX()
//     end
//     if v:isVisible() then
//       totalLen = totalLen + width
//       len = len + 1
//     end
//   end
//   totalLen = totalLen + (len - 1) * interval
//   local tempLen = 0
//   if isReverse then
//     for i = #targets, 1, -1 do
//       local width = 0
//       if not isSize and targets[i].getVirtualRendererSize then
//         width = math.min(targets[i]:getVirtualRendererSize().width, targets[i]:getContentSize().width)
//         width = width * targets[i]:getScaleX()
//       else
//         width = targets[i]:getContentSize().width * targets[i]:getScaleX()
//       end
//       if targets[i]:isVisible() then
//         targets[i]:setAnchorPoint(cc.p(0.5, 0.5))
//         targets[i]:setPositionX(-totalLen / 2 + width / 2 + tempLen)
//         tempLen = tempLen + width + interval
//       end
//     end
//   else
//     for i = 1, #targets do
//       local width = 0
//       if not isSize and targets[i].getVirtualRendererSize then
//         width = math.min(targets[i]:getVirtualRendererSize().width, targets[i]:getContentSize().width)
//         width = width * targets[i]:getScaleX()
//       else
//         width = targets[i]:getContentSize().width * targets[i]:getScaleX()
//       end
//       if targets[i]:isVisible() then
//         targets[i]:setAnchorPoint(cc.p(0.5, 0.5))
//         targets[i]:setPositionX(-totalLen / 2 + width / 2 + tempLen)
//         tempLen = tempLen + width + interval
//       end
//     end
//   end
//   return node, tempLen
// end
  }
}

TextHAlignment GBase::DFLabelR(){
  if(GBase::DGetLayoutAlignment() == ELayoutAlignment::Right)
    return TextHAlignment::RIGHT;
  return TextHAlignment::LEFT;
}



void GBase::DAutoSizeButtonText(ui::Button *p_Btn, Size p_Size){
  if(!p_Btn) 
    return;
  auto l_Txt = p_Btn->getTitleRenderer();
  if( p_Size.width != 0 && p_Size.height != 0){
    l_Txt->setWidth(p_Size.width);
    l_Txt->setHeight(p_Size.height);
  }else{
    auto l_Size = p_Btn->getContentSize();
    l_Txt->setWidth(l_Size.width);
    l_Txt->setHeight(l_Size.height);
  }
  l_Txt->setVerticalAlignment(TextVAlignment::CENTER);
  l_Txt->setVerticalAlignment(TextVAlignment::CENTER);
  p_Btn->setTitleText(p_Btn->getTitleText());
}

bool GBase::DIsPointInPolygon(const GVector<Vec2> &p_Polygon, Vec2 p_Point){
  // local lineArray = {}
  // local targetPoint = cc.pMidpoint(polygonPtArray[1], polygonPtArray[3])
  // for i = 1, #polygonPtArray do
  //   local point1 = polygonPtArray[i]
  //   local point2 = polygonPtArray[1]
  //   if i < #polygonPtArray then
  //     point2 = polygonPtArray[i + 1]
  //   end
  //   if cc.pIsSegmentIntersect(point1, point2, touchPoint, targetPoint) then
  //     return false
  //   end
  // end
  // return true
  return true;
}

float GBase::DGetAngleByPos(Vec2 pPoint1, Vec2 pPoint2){
  auto lPoint = pPoint2 - pPoint1;
  return GMath::Atan2(lPoint.y, lPoint.x) * 180 / M_PI;
}


bool GBase::DRectIntersectsRect(const Rect &pRect1, const Rect &pRect2, bool pHaveBorder){

  // local x11 = rect1.x
  auto x11 = pRect1.origin.x;
  // local y11 = rect1.y
  auto y11 = pRect1.origin.y;
  // local x12 = rect1.x + rect1.width
  auto x12 = pRect1.origin.x + pRect1.size.width;
  // local y12 = rect1.y + rect1.height
  auto y12 = pRect1.origin.y + pRect1.size.height;
  // local x21 = rect2.x
  auto x21 = pRect2.origin.x;
  // local y21 = rect2.y
  auto y21 = pRect2.origin.y;
  // local x22 = rect2.x + rect2.width
  auto x22 = pRect2.origin.x + pRect2.size.width;
  // local y22 = rect2.y + rect2.height
  auto y22 = pRect2.origin.y + pRect2.size.height;
  if(pHaveBorder){
    return x12 >= x21 && x11 <= x22 && y12 >= y21 && y11 <= y22;
  }else{
      return x12 > x21 && x11 < x22 && y12 > y21 && y11 < y22;
  }
  return false;
}

float GBase::DGetTextLen(Label *pLabel){
  // local txtContentInfo = {
  //   fontName = "",
  //   fontSize = label:getSystemFontSize(),
  //   fontAlignmentH = label:getHorizontalAlignment(),
  //   fontAlignmentV = label:getVerticalAlignment(),
  //   fontDimensions = cc.size(0, 0),
  //   isHtml = false
  // }
  // local measureSize = cc.Device:measureText(label:getString(), txtContentInfo)
  // return measureSize.width
  return pLabel->getContentSize().width;
}
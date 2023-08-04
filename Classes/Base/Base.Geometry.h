#pragma once
#include "Base/BaseTypeDef.h"

enum class ELayoutAlignment {Left = 0, Right = 1};

namespace cocos2d{
  class Node;
  class Vec2;
  enum class TextHAlignment;
  namespace ui {
    class Button;
  }
};

using namespace cocos2d;
namespace GBase{
  Vec2 DFPoint(double p_X, double p_Y, double p_Target);
  float DFPosX(float p_X, float p_Target);
  float DFPosX(float p_X, Node *p_Target);
  float DFPosX(float p_X);
  ELayoutAlignment DGetLayoutAlignment();
  float DAlignNodeArray(GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding = {});
  void DAlignNodeArray(GVector<Node *> p_Nodes, bool p_IsRA, float p_padding);
  float DAlignNodeArrayOnBeginX(float p_Begin, GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding = {});
  float DAlignNodeArrayOnLimitX( GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding, bool p_LimitR, float p_LimitX);
  void DToCenter(Node *p_Node, float p_Interval = 10, bool pIsReverse = false, bool pIsSize = false);
  TextHAlignment DFLabelR();
  void DAutoSizeButtonText(ui::Button *p_Btn, Size p_Size = Size::ZERO);
  bool DIsPointInPolygon(const GVector<Vec2> &p_Polygon, Vec2 p_Point);
  float DGetAngleByPos(Vec2 pPoint1, Vec2 pPoint2);
  bool DRectIntersectsRect(const Rect &pRect1, const Rect &pRect2, bool pHaveBorder = false);
  float DGetTextLen(Label *pLabel);
};
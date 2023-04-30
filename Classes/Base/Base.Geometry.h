#pragma once
#include "Base/BaseTypeDef.h"

enum class ELayoutAlignment {Left = 0, Right = 1};

namespace cocos2d{
  class Node;
  class Vec2;
  enum class TextHAlignment;
};

using namespace cocos2d;
namespace GBase{
  Vec2 DFPoint(double p_X, double p_Y, double p_Target);
  float DFPosX(float p_X, float p_Target);
  float DFPosX(float p_X, Node *p_Target);
  ELayoutAlignment DGetLayoutAlignment();
  float DAlignNodeArray(GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding = {});
  void DAlignNodeArray(GVector<Node *> p_Nodes, bool p_IsRA, float p_padding);
  float DAlignNodeArrayOnBeginX(float p_Begin, GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding = {});
  float DAlignNodeArrayOnLimitX( GVector<Node *> p_Nodes, bool p_IsRA, GVector<float> p_padding, bool p_LimitR, float p_LimitX);
  void DToCenter(Node *p_Node);
  TextHAlignment DFLabelR();
};
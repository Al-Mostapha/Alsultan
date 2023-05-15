#include "Engine.h"
#include "Device.h"
#include "Display.h"

GEngine *GEngine::Get()
{
  static GEngine *l_Engine = nullptr;
  if (l_Engine == nullptr)
  {
    l_Engine = new GEngine();
  }
  return l_Engine;
}

void GEngine::Init()
{
  GDevice::Get()->Init();
  GDisplay::Get()->Init();
  // GConfig::Get()->Init();
  // GAudio::Get()->Init();
  // GScene::Get()->Init();
  // GUI::Get()->Init();
  // GGame::Get()->Init();
}

void GEngine::PrintNodeTree(Node *p_Node, int p_Depth)
{
  if (p_Node == nullptr)
  {
    return;
  }
  for (int i = 0; i < p_Depth; i++)
  {
    cocos2d::log("  ");
  }
  cocos2d::log("%s\n", p_Node->getName().c_str());
  for (auto l_Child : p_Node->getChildren())
  {
    PrintNodeTree(l_Child, p_Depth + 1);
  }
}


void GEngine::NodeHighlight(Node *){}
void GEngine::ButtonHighlight(Node *){}
void GEngine::ClickableHighlight(Node * p_Parent){
  if(p_Parent == nullptr)
    return;
  if(dynamic_cast<ui::Widget *>(p_Parent) != nullptr){
    auto l_Widget = dynamic_cast<ui::Widget *>(p_Parent);
    if(l_Widget->isTouchEnabled() == false)
      return;
      auto l_contentSize = l_Widget->getContentSize();
      auto l_DrawNode = DrawNode::create();
      Vec2 vertices[4] =
      {
          Vec2::ZERO,
          Vec2(l_contentSize.width, 0.0f),
          Vec2(l_contentSize.width, l_contentSize.height),
          Vec2(0.0f, l_contentSize.height)
      };
    l_DrawNode->drawPoly(vertices, 4, true, Color4F::GREEN);
    l_Widget->addChild(l_DrawNode);

    l_Widget->addTouchEventListener([](Ref *p_Sender, ui::Widget::TouchEventType p_Type){
      if(p_Type == ui::Widget::TouchEventType::BEGAN){
        auto l_Widget = dynamic_cast<ui::Widget *>(p_Sender);
        l_Widget->setOpacity(50);
      }
      else if(p_Type == ui::Widget::TouchEventType::ENDED){
        auto l_Widget = dynamic_cast<ui::Widget *>(p_Sender);
        l_Widget->setOpacity(100);
      }
    });
  }
  
  for(auto l_Child : p_Parent->getChildren()){
    ClickableHighlight(l_Child);
  }

}
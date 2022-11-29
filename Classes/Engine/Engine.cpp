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
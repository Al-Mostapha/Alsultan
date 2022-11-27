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
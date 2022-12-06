#include "UISwitcher.h"

UISwitcher* UISwitcher::Create()
{
  auto l_Switcher = Create("");
  l_Switcher->Ctor();
  return l_Switcher;
}

void UISwitcher::CloseSwitcher()
{
  
}
#include "FGui.GRoot.h"


GRoot *GRoot::Get(){
  static GRoot *l_GRoot = new GRoot();
  return l_GRoot;
}

Size GRoot::GetSize(){
  return Size(0,0);
}
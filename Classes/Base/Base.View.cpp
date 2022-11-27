#include "Base.View.h"
#include "Include/IncludeEngine.h"

void BaseView::LoadImages(GVector<GString> p_Array, const std::function<void()> &p_Callback){
  if(p_Array.empty())
    return;
  auto l_Index = 0;
  for (size_t i = 0; i < p_Array.size(); i++)
  {
    auto l_ImageName = p_Array.at(i);
    m_ArrayImagesPath.insert(l_ImageName);
    auto l_PList = l_ImageName + ".plist";
    GDisplay::Get()->AddSpriteFrames(l_ImageName, "", [&](){
      l_Index++;
      if(l_Index >= p_Array.size())
        p_Callback();
    });
  }
}
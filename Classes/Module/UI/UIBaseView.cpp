#include "UIBaseView.h"
#include "Base/Common/Timer.Mgr.h"

UIBaseView *UIBaseView::Create(Size p_Size, bool p_IsColor, Node *p_Target)
{
  if(p_Target)
    return dynamic_cast<UIBaseView *>(p_Target);
  auto l_View  = UIBaseView::create();
  l_View->setContentSize(p_Size);
  if(p_IsColor){
    l_View->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    l_View->setBackGroundColor(Color3B(255, 0, 0));
    l_View->setBackGroundColorOpacity(100);
  }
  l_View->setAnchorPoint(Vec2(0.5, 0.5));
  l_View->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
  l_View->setTouchEnabled(true);
  l_View->setSwallowTouches(true);
  return l_View;
}

void UIBaseView::Ctor()
{
  //self:setNodeEventEnabled(true)
  m_FreeImagesOnExit = false;
  m_ADType = false;
  m_MenuID = 0;
  m_ArrayImagesPath.clear();
}

void UIBaseView::SetBackGround(float p_Opacity, Color3B p_Color)
{
  setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
  setBackGroundColor(p_Color);
  setBackGroundColorOpacity(p_Opacity);
}

float UIBaseView::GetPanelOffsetHeight()
{
  if(m_ADType)
    return GDisplay::Get()->height - 120;
  else 
    return GDisplay::Get()->height;
}

void UIBaseView::LoadImages(const GVector<GString> &p_ArrayImagesPath, UIBaseView::CallBack p_CallBack){
  if(p_ArrayImagesPath.empty())
    return;
  auto l_Index = 0;
  for (size_t i = 0; i < p_ArrayImagesPath.size(); i++)
  {
    auto l_ImageName = p_ArrayImagesPath.at(i);
    m_ArrayImagesPath.insert(l_ImageName);
    auto l_PList = l_ImageName + ".plist";
    GDisplay::Get()->AddSpriteFrames(l_PList , l_ImageName, [&](){
      l_Index++;
      if(l_Index >= p_ArrayImagesPath.size() && p_CallBack)
        p_CallBack();
    });
  }
}

bool UIBaseView::IsImageLoaded(GString p_ImageName)
{
  return m_ArrayImagesPath.find(p_ImageName) != m_ArrayImagesPath.end();
}

void UIBaseView::FreeImages(){
//   if not self.freeImagesOnExit then
//     return
//   end
//   if self.arrayImagesPath then
//     for k, v in pairs(self.arrayImagesPath) do
//       local plistName = v.name .. ".plist"
//       local imageName = getImageFileNameByPlatform(v.name, v.format)
//       if v.isLoadOK then
//         imageManager.unuseImage(imageName)
//         imageManager.unusePlist(plistName)
//         if device.platform == "android" then
//           imageManager.unuseImage(v.name .. "_alpha.pkm")
//         end
//       end
//     end
//   end
}

void UIBaseView::onEnter(){
  ui::Layout::onEnter();
  OnMessageListener();
  OnEnterOther();
}


void UIBaseView::onExit(){
  ui::Layout::onExit();
  GBase::DRemoveMessageByTarget(this);
  GBase::DManagerRemoveTimerByTarget(this);
  FreeImages();
  OnExitOther();
}


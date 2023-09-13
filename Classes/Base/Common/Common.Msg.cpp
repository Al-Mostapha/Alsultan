#include "Common.Msg.h"
#include "Module/UI/Part/Common/Msg/UICommonHelpMsgBox.h"

void GBase::DShowHelpMsgTip(GString p_Msg){
  auto l_MsgBox = UICommonHelpMsgBox::Create();
  l_MsgBox->SetMsg(p_Msg, RStyleFormat());
  l_MsgBox->Show();
}
void GBase::DShowHelpMsgTip(GString p_Msg, RStyleFormat p_Format ){
  auto l_MsgBox = UICommonHelpMsgBox::Create();
  l_MsgBox->SetMsg(p_Msg, p_Format);
  l_MsgBox->Show();
}

UICommonPromptBox*  GBase::DShowMsgBox(GString p_Msg, GString p_YesBtnTitle,
                          GString p_NoBtnTitle , const GFunc<void(EMsgBoxCallBack)> &p_CallBack,
                          void* p_Data, int p_Align,  bool p_NoSound){
  return nullptr;
}

UICommonPromptBox* GBase::DShowLoginFailBox(const char* p_FailType, GString p_ShowMsg, bool p_HaveCancelBtn, std::function<void()> p_CallBack) {
  return nullptr;
}

void GBase::ShowServerTip(const GString &pTitle, const GString &pContent){

}
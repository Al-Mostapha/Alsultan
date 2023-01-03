#include "Questionnaire.Ctrl.h"

QuestionnaireCtrl *QuestionnaireCtrl::Get()
{
    static QuestionnaireCtrl *s_QuestionnaireCtrl = nullptr;
    if (s_QuestionnaireCtrl == nullptr)
    {
        s_QuestionnaireCtrl = new QuestionnaireCtrl();
    }
    return s_QuestionnaireCtrl;
}

void QuestionnaireCtrl::ReqGetQuestData()
{
  // local project = IsArClient and "koh" or "ros"
  // local kid = SoraDConfigGet("Game:LoginView:setKingdomID~integer")
  // local lang = GameLanguageCopy
  // print("GameLanguageCopy", GameLanguageCopy, userSDKManager.isBeta())
  // local channel = userSDKManager.getPlatformChannel()
  // if channel == "" then
  //   channel = "AppStore" or channel
  // end
  // local url
  // if userSDKManager.isBeta() or device.platform == "mac" then
  //   url = string.format("https://testwebapi.onemt.co/activity/list/%s/%s/%s/%s/", project, lang, kid, channel)
  // else
  //   url = string.format("https://webapi.onemt.co/activity/list/%s/%s/%s/%s/", project, lang, kid, channel)
  // end
  // local encryptData = crypto.encryptXXTEA(gametop.playertop_:getPlayerID(), "eTYR77JO4LW0TeNW")
  // local uid = crypto.encodeBase64(encryptData)
  // print(url, tostring(uid))
  // SoraDHttpRequest(handler(self, self.reqGetQuestDataRsp), url, "POST", {p = uid}, handler(self, self.reqGetQuestDataRsp), nil)
}
#include "Login.h"
#include "Login.Ctrl.h"

Login* Login::Get() {
  static Login* l_Inst = new Login();
  return l_Inst;
}

void Login::Ctor() {
  // cc(self):addComponent("components.behavior.EventProtocol"):exportMethods()
}

void Login::InitSocket() {
  // print("=====initSocket=====")
  // self:disconnectLogin()
  // local socket = net.SocketTCP.new()
  // socket:setName("SocketTCP")
  // socket:setTickTime(0.01)
  // socket:setReconnTime(6)
  // socket:setConnFailTime(15)
  // socket:addEventListener(socket.EVENT_DATA, handler(self, self.receive))
  // socket:addEventListener(socket.EVENT_CLOSE, handler(self, self.tcpClose))
  // socket:addEventListener(socket.EVENT_CLOSED, handler(self, self.tcpClosed))
  // socket:addEventListener(socket.EVENT_CONNECTED, handler(self, self.tcpConnected))
  // socket:addEventListener(socket.EVENT_CONNECT_FAILURE, handler(self, self.failure))
  // self.socket = socket
}

void Login::ConnectLogin() {
  //   print("=====login:connectLogin=====", host, port)
  // sendReviewLog(string.format("=====login:connectLogin===== %s %s", host, port))
  // self.token = token
  // NextState = S2C_CHALLENGE
  // self.socket:connect(host, port)

  // TODO:This temp bypass
  S2C_AUTH_TOKEN(nullptr);
}

void Login::S2C_AUTH_TOKEN(const char* p_B64Msg) {
  //  print("=====login:S2C_AUTH_TOKEN=====", msg)
  //   sendReviewLog("=====login:S2C_AUTH_TOKEN=====" .. tostring(msg))
  //   local code = tonumber(string.sub(msg, 1, 3))
  //   local submsg = string.sub(msg, 5)
  //   if code == login.Err_Login_AuthTokenSuccess then

  //     local resultmsg = base64decode(submsg)

  //     local b64kingdomId, b64servername, b64gateip, b64gateport, b64subid, b64uid = resultmsg:match("([^@]+)@([^@]+)@([^@]+)@([^@]+)@([^@]+)@(.+)")
  //     self.kingdomId = base64decode(b64kingdomId)
  //     self.servername = base64decode(b64servername)
  //     self.gateip = base64decode(b64gateip)
  //     self.gateport = base64decode(b64gateport)
  //     self.subid = base64decode(b64subid)
  //     self.uid = base64decode(b64uid)
  //     if device.platform == "mac" or userSDKManager.isBeta() then
  //       self:tempConverGateIP()
  //     end
  //     print(string.format("=====login authtoken success=====", self.kingdomId, self.uid, self.gateip, self.gateport))
  //     sendReviewLog(string.format("=====login authtoken success=====", self.kingdomId, self.uid, self.gateip, self.gateport))
  //     self:disconnectLogin()

  //     self:loginSuccess()
  LoginSuccess();
  //   elseif code == login.Err_Login_NotExistServer then
  //     local _, kid = msg:match("(%d+) (%d+)")
  //     local serverTime = string.match(msg, "serverTime:(%d+)")
  //     serverTime = serverTime and tonumber(serverTime)
  //     self:serverMaintaince(kid, serverTime)
  //   elseif code == login.Err_Login_BeSealed then
  //     local _, sealType = msg:match("(%d+) (%d+)")
  //     sealType = tonumber(sealType)
  //     self:beSealed(sealType)
  //   elseif code == login.Err_Login_VersionError then
  //     self:versionError()
  //   elseif code == login.Err_Login_SDKUserDelete then
  //     self:beSealed(gSealAccountType.DEL_ACCOUNT)
  //   else
  //     local failedType = gLoginFailTypeDef.loginFailType_startLogin
  //     if code == login.Err_Login_Unauthorized then
  //       print("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\232\135\170\229\174\154\228\185\137\231\154\132auth_handler\228\184\141\232\174\164\229\143\175token=====")
  //       sendReviewLog("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\232\135\170\229\174\154\228\185\137\231\154\132auth_handler\228\184\141\232\174\164\229\143\175token=====")
  //     elseif code == login.Err_Login_Forbidden then
  //       print("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\232\135\170\229\174\154\228\185\137\231\154\132login_handler\230\137\167\232\161\140\229\164\177\232\180\165=====")
  //       sendReviewLog("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\232\135\170\229\174\154\228\185\137\231\154\132login_handler\230\137\167\232\161\140\229\164\177\232\180\165=====")
  //     elseif code == login.Err_Login_NotAcceptable then
  //       print("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\232\175\165\231\148\168\230\136\183\229\183\178\231\187\143\229\156\168\231\153\187\233\153\134\228\184\173(\229\143\170\229\143\145\231\148\159\229\156\168multilogin\229\133\179\233\151\173\230\151\182)=====")
  //       sendReviewLog("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\232\175\165\231\148\168\230\136\183\229\183\178\231\187\143\229\156\168\231\153\187\233\153\134\228\184\173(\229\143\170\229\143\145\231\148\159\229\156\168multilogin\229\133\179\233\151\173\230\151\182)=====")
  //     elseif code == login.Err_Login_SDKTokenError then
  //       print("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\231\172\172\228\184\137\230\150\185SDK\232\174\164\232\175\129\233\148\153\232\175\175====")
  //       sendReviewLog("=====\233\170\140\232\175\129token\229\164\177\232\180\165
  //       \231\153\187\229\189\149\229\164\177\232\180\165,\231\172\172\228\184\137\230\150\185SDK\232\174\164\232\175\129\233\148\153\232\175\175====")
  //       failedType = gLoginFailTypeDef.loginFailType_sdkTokenError
  //     end
  //     self:loginFailed(failedType)
  //   end
}


void Login::LoginSuccess(){
  LoginCtrl::Get()->LoginSuccess();
}
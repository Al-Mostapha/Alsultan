#include "RaidersLostArk.Ctrl.h"

RaidersLostArkCtrl *RaidersLostArkCtrl::Get(){
    static RaidersLostArkCtrl *s_RaidersLostArk = nullptr;
    if(s_RaidersLostArk == nullptr){
        s_RaidersLostArk = new RaidersLostArkCtrl();
    }
    return s_RaidersLostArk;
}

void RaidersLostArkCtrl::InitKeyNums(){
  // local backpackCtrl = SoraDGetCtrl("backpackCtrl")
  // local keyList = {
  //   830701,
  //   830801,
  //   830901,
  //   831001,
  //   831101,
  //   831201,
  //   831301,
  //   831401,
  //   831501,
  //   831601,
  //   831701,
  //   831801,
  //   831901,
  //   832001,
  //   832201
  // }
  // for i, v in ipairs(keyList) do
  //   local keyCount = backpackCtrl:getItemCount(v)
  //   if not self.keyNumData[v] then
  //     self.keyNumData[v] = {}
  //   end
  //   self.keyNumData[v] = keyCount
  // end
}
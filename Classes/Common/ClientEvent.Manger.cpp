#include "ClientEvent.Manger.h"

ClientEventManger *ClientEventManger::Get() {
  static ClientEventManger *s_ClientEventManger = nullptr;
  if (s_ClientEventManger == nullptr) {
    s_ClientEventManger = new ClientEventManger();
  }
  return s_ClientEventManger;
}

GVector<REvent> ClientEventManger::GetEventStateInfo(int32 p_IdActivity) {
  GVector<REvent> v;
  return v;
}
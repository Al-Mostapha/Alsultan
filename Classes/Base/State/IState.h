
#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Base.Const.h"
#include "Base/Containers/Set.h"

class IState {
public:

  struct Event{
    void *m_Data;
    Event(void *p_Data) : m_Data(p_Data) {}
    template<typename T>
    T *GetData(){
      return static_cast<T *>(m_Data);
    }
  };

  GString m_Name = "";
  GSet<IState *> m_From;
  IState *m_To = nullptr;
  virtual void PreEnter(Event *p_Event) = 0;
  virtual void OnEnter(Event *p_Event) = 0;
  virtual void PostEnter(Event *p_Event) = 0;
  virtual void Enter(Event *p_Event) = 0;
  virtual void OnExit(Event *p_Event) = 0;
  bool AddState(IState *p_State);
  bool FinalState(IState *p_State);
};


class StateNone : public IState{
public:
  void PreEnter(Event *p_Event) {}
  void OnEnter(Event *p_Event) {}
  void PostEnter(Event *p_Event) {}
  void Enter(Event *p_Event) {}
  void OnExit(Event *p_Event) {}
  static IState *Create(){
    return nullptr;
  }
};
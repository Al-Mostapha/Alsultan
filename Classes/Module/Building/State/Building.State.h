#pragma once
#include "Include/IncludeBase.h"
#include "Base/State/IState.h"

namespace Building{
  class StateReset : public IState{
    public:
    void PreEnter(Event *p_Event) ;
    void OnEnter(Event *p_Event) {}
    void PostEnter(Event *p_Event);
    void Enter(Event *p_Event) {}
    void OnExit(Event *p_Event) {}
    static IState *Create(){
      return new StateReset();
    }
  };


  class StateLock : public IState{
    public:
    void PreEnter(Event *p_Event) ;
    void OnEnter(Event *p_Event) {}
    void PostEnter(Event *p_Event) {}
    void Enter(Event *p_Event) {}
    void OnExit(Event *p_Event) {}
    static IState *Create(){
      return new StateLock();
    }
  };

  class StateBuilding : public IState{
    public:
    void PreEnter(Event *p_Event) ;
    void OnEnter(Event *p_Event) {}
    void PostEnter(Event *p_Event);
    void Enter(Event *p_Event) {}
    void OnExit(Event *p_Event);
    static IState *Create(){
      return new StateBuilding();
    }
  };


  class StateHarvest : public IState{
    public:
    void PreEnter(Event *p_Event) ;
    void OnEnter(Event *p_Event) {}
    void PostEnter(Event *p_Event) ;
    void Enter(Event *p_Event) {}
    void OnExit(Event *p_Event) {}
    static IState *Create(){
      return new StateHarvest();
    }
  };

  class StateDemolish : public IState{
    public:
    void PreEnter(Event *p_Event) ;
    void OnEnter(Event *p_Event) {}
    void PostEnter(Event *p_Event);
    void Enter(Event *p_Event) {}
    void OnExit(Event *p_Event) {}
    static IState *Create(){
      return new StateDemolish();
    }
  };

  class StateWork : public IState{
    public:
    void PreEnter(Event *p_Event) ;
    void OnEnter(Event *p_Event) {}
    void PostEnter(Event *p_Event);
    void OnExit(Event *p_Event) {}
    void Enter(Event *p_Event) {}
    static IState *Create(){
      return new StateWork();
    }
  };

  class StateIdle : public IState{
    public:
    void PreEnter(Event *p_Event)  {}
    void OnEnter(Event *p_Event)   {}
    void PostEnter(Event *p_Event) {}
    void Enter(Event *p_Event)     {}
    void OnExit(Event *p_Event)    {}
    static IState *Create(){
      return new StateIdle();
    }
  };

} // namspace

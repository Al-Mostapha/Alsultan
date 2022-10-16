
#include "IState.h"


bool IState::AddState(IState *p_State){
  bool l_IsFound = m_From.find(p_State) == m_From.end();;
  m_From.insert(p_State);
  return l_IsFound;
}

bool IState::FinalState(IState *p_State){
  bool l_IsFound = m_To == p_State;
  m_To = p_State;
  return l_IsFound;
}
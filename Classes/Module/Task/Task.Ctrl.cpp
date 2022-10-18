#include "Task.Ctrl.h"

TaskCtrl *TaskCtrl::Get(){
  static TaskCtrl *s_TaskCtrl =  new TaskCtrl();
  return s_TaskCtrl;
}
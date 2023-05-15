#include "Task.Ctrl.h"

TaskCtrl *TaskCtrl::Get(){
  static TaskCtrl *s_TaskCtrl =  new TaskCtrl();
  return s_TaskCtrl;
}

bool TaskCtrl::IsHospitalQueue(ETask p_Task){
  return 
    p_Task == ETask::hostpital_queue || 
    p_Task == ETask::RadianceWarHostpitalQueue || 
    p_Task == ETask::atlantis_war_hostpital_queue || 
    p_Task == ETask::nebula_war_hostpital_queue ;
}

ITask *TaskCtrl::QueryQueue(ETask p_Task){
  auto l_Task = new ITask();
  return l_Task;
}
#include "Building.State.h"
#include "Module/Building/IBuilding.h"
#include "Module/Building/BuildingUnit/BuildingIEmbassy.h"
#include "Module/Building/Building.Logic.h"


void Building::StateReset::PreEnter(IState::Event *p_Event)
{
  m_Name = "Reset";
  AddState(StateNone::Create());
  AddState(StateLock::Create());
  AddState(StateBuilding::Create());
  AddState(StateHarvest::Create());
  AddState(StateDemolish::Create());
  AddState(StateWork::Create());
  FinalState(StateIdle::Create());
}

void Building::StateReset::PostEnter(IState::Event *p_Event)
{
  IBuilding *l_Building = p_Event->GetData<IBuilding>();
  if(!l_Building)
    return;
  l_Building->HideAnimBuildWorker();
  l_Building->HideAnimWorking();
  l_Building->HideGlow();
  l_Building->HideWorkDone();
  l_Building->ShowZAnimation();
  l_Building->SetHarvestState(EHarvestState::None);
  l_Building->m_IsCanSpeedUpFree = false;
  l_Building->m_IsCancelled = false;
  EBuilding l_BuildingId = l_Building->GetBuildingId();
  l_Building->SetQueueDirty(true);
  if(l_BuildingId == EBuilding::FirstAidTent && l_Building->IsTraining()){
    l_Building->SetBlockState(EBuildingState::Training);
    l_Building->ChangeState();
  }
  if(l_BuildingId == EBuilding::Embassy){
    auto l_Embassy = dynamic_cast<BuildingIEmbassy *>(l_Building);
    if(l_Embassy){
      l_Embassy->UpdateAllianceHelpList();
    }
  }
  l_Building->UpdateTopTip();
  if(l_Building->IsCanSpeedUpStrongFree() || l_Building->IsNeedRequestHelp()){
    l_Building->ShowTopTip();
  }
}

void Building::StateLock::PreEnter(IState::Event *p_Event)
{
  m_Name = "Lock";
  AddState(StateNone::Create());
  FinalState(StateLock::Create());
}

void Building::StateBuilding::PreEnter(IState::Event *p_Event){
  m_Name = "Building";
  AddState(StateNone::Create());
  AddState(StateIdle::Create());
  AddState(StateWork::Create());
  AddState(StateHarvest::Create());
  FinalState(StateBuilding::Create());
}

void Building::StateBuilding::PostEnter(IState::Event *p_Event){

  IBuilding *l_Building = p_Event->GetData<IBuilding>();
  if(!l_Building)
    return;

  l_Building->SetQueueDirty(true);
  EBuilding l_BuildingId = l_Building->GetBuildingId();
  EBuildingIndex l_BuildingIndex = l_Building->GetBuildingIndex();
  auto l_QueuedTask = BuildingLogic::Get()->GetQueueType(l_BuildingIndex);
  if(!l_QueuedTask){
    l_Building->SetBlockState(EBuildingState::Idle);
    l_Building->ChangeState();
    l_Building->UpdateLvl();
    return;
  }else{
    l_Building->m_BuildingTask = l_QueuedTask;
  }
  if(!l_Building->m_BuildingTask)
    return;

  auto l_RemainTime = l_Building->m_BuildingTask->GetRemainTime();
  if(l_RemainTime <= 0){
    l_Building->SetBlockState(EBuildingState::Idle);
    l_Building->ChangeState();
    l_Building->UpdateLvl();
    return;
  }
  l_Building->ShowAnimBuildWorker();
  l_Building->ShowCoolingPanel();
}

void Building::StateBuilding::OnExit(IState::Event *p_Event){
  IBuilding *l_Building = p_Event->GetData<IBuilding>();
  if(!l_Building)
    return;
  if(l_Building->m_IsCancelled){
    l_Building->ShowEffectUpgrade();
  }
  if(l_Building->GetBuildingId() == EBuilding::TreasurePool){
    l_Building->getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_WISHINGWELL_VIEW");
  }
  l_Building->UpdateViewAfterBuild();
}

void Building::StateWork::PreEnter(IState::Event *p_Event){
  m_Name = "Work";
  AddState(StateNone::Create());
  AddState(StateIdle::Create());
  AddState(StateHarvest::Create());
  FinalState(StateWork::Create());
}

void Building::StateWork::PostEnter(IState::Event *p_Event){
  IBuilding *l_Building = p_Event->GetData<IBuilding>();
  if(!l_Building)
    return;
  l_Building->SetQueueDirty(true);
  l_Building->ShowAnimWorking();
  l_Building->ShowCoolingPanel();
}


void Building::StateHarvest::PreEnter(IState::Event *p_Event){
  m_Name = "Harvest";
  AddState(StateNone::Create());
  AddState(StateIdle::Create());
  AddState(StateWork::Create());
  FinalState(StateHarvest::Create());
}

void Building::StateHarvest::PostEnter(IState::Event *p_Event){
  IBuilding *l_Building = p_Event->GetData<IBuilding>();
  if(!l_Building)
    return;
  l_Building->SetQueueDirty(true);
  if(l_Building->GetState() == EBuildingState::None)
    return;
  l_Building->ShowWorkDone();
}

void Building::StateDemolish::PreEnter(IState::Event *p_Event){
  m_Name = "Demolish";
  AddState(StateNone::Create());
  AddState(StateIdle::Create());
  AddState(StateWork::Create());
  AddState(StateHarvest::Create());
  FinalState(StateDemolish::Create());
}

void Building::StateDemolish::PostEnter(IState::Event *p_Event){
  IBuilding *l_Building = p_Event->GetData<IBuilding>();
  if(!l_Building)
    return;
  auto l_QueuedTask = BuildingLogic::Get()->GetQueueType(l_Building->GetBuildingIndex());
  if(!l_QueuedTask)
    return;
  l_Building->m_BuildingTask = l_QueuedTask;
  auto l_RemainTime = l_Building->m_BuildingTask->GetRemainTime();
  if(l_RemainTime <= 0){
    l_Building->SetBlockState(EBuildingState::Idle);
    l_Building->ChangeState();
    l_Building->UpdateLvl();
    return;
  }
  l_Building->ShowAnimBuildWorker();
  l_Building->ShowCoolingPanel();
}



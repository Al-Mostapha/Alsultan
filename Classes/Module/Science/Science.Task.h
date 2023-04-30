#pragma once

#include "Module/Task/ITask.h"
#include "Science.Enum.h"

class ScienceTask : public ITask
{
  public:
    EScienceID _TechnologyID = EScienceID::None;
};
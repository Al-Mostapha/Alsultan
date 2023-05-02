#pragma once

#include "Module/Task/ITask.h"
#include "Science.Enum.h"

class ScienceTask : public ITask
{
  public:
    EScience _TechnologyID = EScience::None;
};
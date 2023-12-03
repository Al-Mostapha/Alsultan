#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"
#include "Module/Science/Science.Enum.h"


class UIWarTechnologyScrollLine : public Node {

  CREATE_FUNC(UIWarTechnologyScrollLine);
public:
  struct RSkillLineData{
    EScience _Id;
    EScience _ToId;
    EScienceType _Type;
    float _PosX;
    float _PosY;
  };
  static UIWarTechnologyScrollLine* Create();
  void Ctor();
  void InitData(RSkillLineData, DrawNode *p_FrameLine, DrawNode *p_FrameLineHl, bool p_BeeLine);

};
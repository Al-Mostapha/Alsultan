#pragma once 
#include "Include/IncludeBase.h"
#include "Module/UI/Panel/UIPanelBase.h"

class UIMsgNotice : public UIPanelBase {
private:

  CREATE_FUNC(UIMsgNotice)
public:
  void InitPanel() override;
  void Notice( const char *p_IdNotice );
  static UIMsgNotice *Create();
  
};
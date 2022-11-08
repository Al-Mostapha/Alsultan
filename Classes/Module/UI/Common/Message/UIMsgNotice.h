#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/Panel/UIPanelBase.h"

class UIMsgNotice : public UIPanelBase {
private:

  CREATE_FUNC(UIMsgNotice)
public:
  void InitPanel() override;
  typedef GHashMap<GString, GString> NoticeData;
  void Notice( const char *p_IdNotice, NoticeData p_NoticeData = {}, ENoticeIcon p_Icon = ENoticeIcon::None);
  static UIMsgNotice *Create();
  
};
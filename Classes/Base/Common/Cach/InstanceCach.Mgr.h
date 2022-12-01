#pragma once

class InstanceCachManger{
  public:
  static InstanceCachManger *Get();
  void ClearCache();
};
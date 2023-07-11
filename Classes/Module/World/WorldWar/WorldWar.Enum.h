#pragma once

enum class EConquestWarState
{
  None = 0,
  LOCK = 1,
  WAITING = 2,
  NOT_MATCH = 3,
  PREPARE = 4,
  OPENING = 5
};
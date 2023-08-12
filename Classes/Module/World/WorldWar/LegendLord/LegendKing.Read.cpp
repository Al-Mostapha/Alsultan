#include "LegendKing.Read.h"

LegendKingRead *LegendKingRead::Get(){
  static LegendKingRead *lLegendKingRead = new LegendKingRead();
  return lLegendKingRead;
}
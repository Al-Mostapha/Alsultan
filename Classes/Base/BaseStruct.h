#pragma once

#include "BaseTypeDef.h"

struct GStruct {

	GString toString() {
	
		return "this Is structure";
	
	}

	bool fromJsonString(GString JsonStr) {
		return true;
	}

	bool fromJsonObject(GJsonObject& JsonObject) {
		return true;
	}
} ;


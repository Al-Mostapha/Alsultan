#pragma once
#include "Base/Type/XJson.h"
#include "BaseTypeDef.h"

struct GStruct {

	GString toString() {
	
		return "this Is structure";
	
	}

	bool fromJsonString(GString JsonStr) {
		return true;
	}

	bool fromJsonObject(XJson& JsonObject) {
		return true;
	}
};


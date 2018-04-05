#pragma once
#include "IRCode.h"
#include "ArduinoInterface.h"
#include "DatabaseInterface.h"


class Framework
{
public:
	Framework();
	~Framework();

private:
	ArduinoInterface myArdInter;
	DatabaseInterface myStorage;
};


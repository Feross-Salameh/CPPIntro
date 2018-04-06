#pragma once
#include "Header.h"
#include "IRCode.h"
#include "ArduinoInterface.h"
#include "DatabaseInterface.h"


class Framework
{
public:
	Framework();

	void StoreIRCode(std::string name);
	void CreateSequence(std::vector<ICode *>& codes, std::string name);
	void CallCode(std::string name);
	void RunSequence(std::string name);
	void GetCode(std::string name, ICode& code);
private:
	ArduinoInterface myArdy;
	DatabaseInterface myStorage;

	// TODO: implement when there is more than 1 interface.
	std::vector<IHardware*> interfaces;
};


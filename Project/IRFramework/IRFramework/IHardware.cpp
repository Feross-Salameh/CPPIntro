#include "IHardware.h"



IHardware::IHardware() :
	myHWID(""),
	myPort(""),
	myIsConnected(false),
	myStatus("")
{
	this->myHW.reset();
}

IHardware::IHardware(std::string hwID, std::string port) :
	myHWID(hwID),
	myPort(port),
	myIsConnected(false),
	myStatus("")
{
}
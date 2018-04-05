#pragma once
#include "IHardware.h"
#include "Header.h"
#include "IRCode.h"

/*
	References to how to interact with arduino:
	https://playground.arduino.cc/Interfacing/CPPWindows - shows example of what interface class looks like.
	
*/

// this class will just be a skeleton until i work on the 
class ArduinoInterface :
	public IHardware
{
public:
	ArduinoInterface(const std::string& port);
	~ArduinoInterface(); // make sure we cleanup the connection before we close it for good.
	virtual bool Connect(std::string &error);
	virtual bool Disconnect(std::string &error);
	virtual bool Reset(std::string &error);

	virtual bool Send(ICode& code, std::string &error);
	virtual bool Recieve(ICode& code, std::string &error);
};


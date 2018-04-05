#include "ArduinoInterface.h"

using namespace std;

ArduinoInterface::ArduinoInterface(const std::string & port) : IHardware("ARDUINO", port)
{
	this->Connect(myStatus);
}

ArduinoInterface::~ArduinoInterface()
{
	this->Disconnect(myStatus);
	myHW.reset();
}


bool ArduinoInterface::Connect(std::string & error)
{
	try
	{
		if (myIsConnected)
			return true;
		// TODO: fill in rest of connection logic
	}
	catch (const std::exception& ex)
	{
		error = ex.what();
		return false;
	}
	error = "";
	myIsConnected = true;
	return true;
}

bool ArduinoInterface::Disconnect(std::string & error)
{
	try
	{
		if (!myIsConnected)
			return true;
		// TODO: fill in rest of disconnection logic
	}
	catch (const std::exception& ex)
	{
		error = ex.what();
		return false;
	}
	error = "";
	myIsConnected = false;
	return true;
}

bool ArduinoInterface::Reset(std::string & error)
{
	try
	{
		this->Disconnect(myStatus);
	}
	catch (const std::exception&)
	{

	}
	error = "";
	return this->Connect(myStatus);

}

bool ArduinoInterface::Send(ICode &code, std::string & error)
{
	try
	{
		if (!myIsConnected)
			throw new exception("Arduino Interface: unable to send, not connected");
		auto irc = dynamic_cast<IRCode*>(&code);
		if (irc == nullptr)
		{
			error = "Arduino Interface: incorrect code given";
			throw new exception;
		}
		// TODO: fill in rest of disconnection logic

	}
	catch (const std::exception&)
	{
		return false;
	}
	error = "";
	return true;
}

bool ArduinoInterface::Recieve(ICode & code, std::string & error)
{
	try
	{
		if (!myIsConnected)
			throw new exception("Arduino Interface: unable to send, not connected");
		// TODO: fill in rest of disconnection logic
		// making empty code for now:
		code = IRCode();
		unsigned char data[5] = { 'h', 'e', 'l', 'l', 'o' };
		code.setData(data, 5);
		code.setDevice("TEST");
		code.setWait(5);
	}
	catch (const std::exception&)
	{
		return false;
	}
	error = "";
	return true;
}

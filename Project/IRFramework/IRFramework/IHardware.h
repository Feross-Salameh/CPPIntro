#pragma once
#include "Header.h"
#include "ICode.h"

class IHardware
{
public:
	IHardware();
	IHardware(std::string hwID, std::string port);
	// all these virtual functions have 
	// changing these to pulic. 
	virtual bool Connect(std::string &error) = 0;
	virtual bool Disconnect(std::string &error) = 0;
	virtual bool Reset(std::string &error) = 0;

	virtual bool Send(ICode& code, std::string &error) = 0;
	virtual bool Recieve(ICode& code, std::string &error) = 0;

	// getters, inlining them in header because of how small they are.

	const std::string& HWID() const { return myHWID; }
	const std::string& Port() const { return myPort; }
	const bool& IsConnected() const { return myIsConnected; }
	const std::string& Status() const { return myStatus; }

protected:
	std::string myHWID; // stores the ID number for the hardware we're using to commuinicate
	std::string myPort; // the commincation port the hardware is setup on.
	bool myIsConnected; // bool containing status of connection.
	std::string myStatus; // various information about the connection status 
	std::unique_ptr<void*> myHW; // place holder if there is already .dll I can use to connect to a spesific HW. 
	
};

 
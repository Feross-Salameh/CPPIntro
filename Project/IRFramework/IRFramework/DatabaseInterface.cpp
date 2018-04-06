#include "DatabaseInterface.h"
#include "IRCode.h"


DatabaseInterface::DatabaseInterface()
{

}

DatabaseInterface::DatabaseInterface(std::string URL) :
	myURL(URL),
	myIsConnected(false),
	myStatus("")
{
	this->Connect(myStatus);
}



DatabaseInterface::~DatabaseInterface()
{
	this->Disconnect(myStatus);
}

bool DatabaseInterface::Connect(std::string & error)
{
	try
	{
		// TODO: fully setup this function
		if (myIsConnected)
			return true;
		else if (myURL == "")
		{
			error = "Unable to connect: URL empty";
			return false;
		}

	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

bool DatabaseInterface::Disconnect(std::string & error)
{
	try
	{
		// TODO: fully setup this function
		if (!myIsConnected)
			return false;
	}
	catch (const std::exception&)
	{
		return false;
	}

	return true;
}

bool DatabaseInterface::storeCode(ICode & code)
{
	try
	{
		// TODO: fully setup this function

	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

bool DatabaseInterface::retrieveCode(std::string name, ICode & code)
{
	try
	{
		// TODO: fully setup this function
		unsigned char data[5] = { 'h', 'e', 'l', 'l', 'o' };
		code = IRCode(data, 5, "TEST", 5);
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

bool DatabaseInterface::storeSequence(std::vector<ICode *> codes, std::string name)
{
	try
	{
		// TODO: fully setup this function

	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

std::vector<ICode *> DatabaseInterface::retrieveSequence(std::string name)
{
	// TODO: fully setup this function

	return std::vector<ICode *>();
}

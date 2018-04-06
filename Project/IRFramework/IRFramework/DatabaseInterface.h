#pragma once
#include "Header.h"
#include "ICode.h"

class DatabaseInterface
{
	// we are assuming that the database is already created, so this class will have no need to create the database.
public:
	DatabaseInterface();
	DatabaseInterface(std::string URL);
	~DatabaseInterface();

	bool Connect(std::string &error);
	bool Disconnect(std::string &error);

	bool storeCode(ICode& code);
	bool retrieveCode(std::string name, ICode & code);

	bool storeSequence(std::vector<ICode *> codes, std::string name);
	std::vector<ICode *> retrieveSequence(std::string name);

private:
	std::string myURL;
	bool myIsConnected;
	std::string myStatus;


};


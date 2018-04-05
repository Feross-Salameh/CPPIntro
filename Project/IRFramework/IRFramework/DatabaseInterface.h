#pragma once
class DatabaseInterface
{
public:
	DatabaseInterface();
	~DatabaseInterface();

	virtual bool Connect(std::string &error) = 0;
	virtual bool Disconnect(std::string &error) = 0;
	virtual bool Reset(std::string &error) = 0;

private:
	std::string myURL;
	bool myIsConnected;


};


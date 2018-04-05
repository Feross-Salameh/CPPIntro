#pragma once
#include "Header.h"
/// This interface is to provide a base of storing and retreiving codes.
class ICode
{
public:
	ICode(unsigned char data[], size_t size, const std::string& device, const double& wait);
	// gertters 
	const unsigned char* getData() const;
	const std::string getDevice() const;
	const double getWait() const;
	
	// setters, all of these are pure virtual because I'm assuming each child class will have it's own rules of how what it can store.
	virtual bool setData(unsigned char data[], size_t size) = 0;
	virtual bool setDevice(const std::string& name) = 0;
	virtual bool setWait(const double& time) = 0;
protected:
	std::unique_ptr<std::vector<unsigned char>> myData; //stores code data in bytes
	std::string myDevice; // name of device this code belongs to
	double myWait; // time in seconds for how long to wait after the code is sent.

};


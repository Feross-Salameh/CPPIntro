#include "ICode.h"

ICode::ICode(unsigned char data[], size_t size, const std::string& device, const double& wait) :
	myData(std::make_unique<std::vector<unsigned char>>(0)),
	myDevice(device),
	myWait(wait)
{
	// for some reason, passing in data directly in the initialzer list was giving me issues, 
	// so I'm doing this instead. Maybe a copy would work as well?
	for (size_t i = 0; i < size; i++)
	{
		myData->push_back(data[i]);
	}
}

const unsigned char* ICode::getData() const
{
	return (*this).myData.get()->data();
}

const std::string ICode::getDevice() const
{
	return this->myDevice;
}

const double ICode::getWait() const
{
	return this->myWait;
}

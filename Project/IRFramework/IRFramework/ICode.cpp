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

//Last minute add, realized the code would need a name.
ICode::ICode(unsigned char data[], size_t size, const std::string & device, const double & wait, std::string name) : 
	ICode(data, size, device, wait)
{
	Name = name;
}

ICode::ICode() : ICode({0}, 0, "NO DEVICE", 0)
{

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

bool ICode::setData(unsigned char data[], size_t size)
{
	try
	{
		this->myData.reset();
		this->myData = std::make_unique<std::vector<unsigned char>>();

		for (size_t i = 0; i < size; i++)
		{
			myData->push_back(data[i]);
		}
	}
	catch (const std::exception&) // any exceptions, return false;
	{
		return false;
	}
	return true;
}

bool ICode::setDevice(const std::string & name)
{
	try
	{
		if (trim_copy(name) == "") // don't want an empty name...
			return false;
		this->myDevice = name;
	}
	catch (const std::exception&)
	{
		return false;
	}

	return true;
}

bool ICode::setWait(const double & time)
{
	try
	{
		if (time < 0)
			return false;
		this->myWait = time;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}


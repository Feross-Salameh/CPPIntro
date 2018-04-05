#include "IRCode.h"



IRCode::IRCode() : ICode(new unsigned char[5], 5, "NO DEVICE", 0)
{

}
IRCode::IRCode(unsigned char data[], size_t size, const std::string& device, const double& wait) : ICode(data, size, device, wait)
{

}

//Get the data for the IRcode. the idea behinf making the user overwite this function was to make sure the code put
// will follow the set rules. right now it will just pass the data in without any checks.
bool IRCode::setData(unsigned char data[], size_t size)
{
	// TODO: figure out if there needs to be any checks for IR codes (max size?, starting bit?)

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

bool IRCode::setDevice(const std::string & name)
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

bool IRCode::setWait(const double & time)
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

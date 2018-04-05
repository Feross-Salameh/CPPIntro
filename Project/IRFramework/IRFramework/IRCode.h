#pragma once
#include "ICode.h"
class IRCode :
	public ICode
{
public:
	IRCode();
	IRCode(unsigned char data[], size_t size, const std::string& device, const double& wait);

	bool setData(unsigned char data[], size_t size);
	bool setDevice(const std::string& name);
	bool setWait(const double& time);

private:
	// at this point in development, I don't know if need to have more private members.
	// I assume I will add more when I try to implement the arduino it will need more information.
	// TODO: do I need to store other information?
};


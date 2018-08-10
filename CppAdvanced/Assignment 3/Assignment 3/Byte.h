#pragma once
#include <iostream>
namespace Binary
{
	class Byte
	{
	public:
		Byte(unsigned __int8 value = 0) : myValue{ value } {}

		Byte(const Byte& other) = default;

		Byte& operator=(const Byte& rhs) = default;
		Byte operator=(unsigned __int8 value)
		{
			this->myValue = value;
			return *this;
		}

		Byte(Byte&& other) = delete;

		Byte& operator=(Byte&& rhs) = delete;

		operator unsigned __int8() const { return myValue; }
		friend std::ostream& operator<<(std::ostream& os, const Byte& b)
		{
			os << "0x" << std::hex << b.myValue;
			return os;
		}
	private:
		unsigned __int8 myValue;
	};
}
#pragma once
#include <iostream>
#include "Byte.h"
namespace Binary
{
	class DoubleWord
	{
	public:
		DoubleWord(unsigned short value = 0) : myValue(value) { }
		DoubleWord(const DoubleWord& other) = default;

		DoubleWord& operator=(DoubleWord const& original)
		{
			this->myValue = original.myValue;
			return *this;
		}
		DoubleWord& operator=(unsigned short value)
		{
			this->myValue = value;
			return *this;
		}

		DoubleWord(DoubleWord && other) = delete;
		DoubleWord& operator=(DoubleWord&& original) = delete;
		operator unsigned short() const { return myValue; }


		friend std::ostream& operator<<(std::ostream& os, const DoubleWord& word)
		{
			os << std::hex << "0x" << std::uppercase;
			if (word.myValue < 16)
				os << "000";
			else if (word.myValue < 256)
				os << "00";
			else if (word.myValue < 4096)
				os << "0";

			os << word.myValue;
			return os;
		}

	private:
		unsigned __int32 myValue;
	};

}

#pragma once

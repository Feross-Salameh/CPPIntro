#pragma once
#include <iostream>
#include <bitset>
namespace Binary
{
	/*
	source: https://stackoverflow.com/questions/1001307/detecting-endianness-programmatically-in-a-c-program
	*/
	constexpr int is_big_endian()
	{
		union {
			uint32_t i;
			char c[4];
		} bint = { 0x01020304 };

		return bint.c[0] == 1;
	}
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

		void write(std::ostream& os);
		void read(std::istream& is);
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
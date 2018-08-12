#include "Byte.h"

void Binary::Byte::write(std::ostream & os)
{
	std::bitset<8> b(myValue);
	os << b;
}

void Binary::Byte::read(std::istream & is)
{
	char * buffer = new char;
	is.read(buffer, 1);
	myValue = *buffer;

	delete buffer;
}



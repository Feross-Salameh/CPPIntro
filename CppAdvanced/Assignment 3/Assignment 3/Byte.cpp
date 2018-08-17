#include "Byte.h"

const void Binary::Byte::write(std::ostream & os)
{
	
	if (is_big_endian())
	{
		throw "Cannot use Big endian system";
	}
	else
	{
		char * buffer = new char;
		*buffer = myValue;
		os.write(buffer, 1);
		delete buffer;
	}
	
}

const void Binary::Byte::read(std::istream & is)
{
	
	if (is_big_endian())
	{
		throw "Cannot use Big endian system";
	}
	else
	{
		char * buffer = new char;
		is.read(buffer, 1);
		myValue = *buffer;

		delete buffer;

	}
	
}



#include "write.h"

// function definitions...
void write(std::ostream& os, const int& value)
{
	os << value;
}

void write(std::ostream& os, const float& value)
{
	os << value;
}

void write(std::ostream& os, const std::string& value)
{
	os << value;
}
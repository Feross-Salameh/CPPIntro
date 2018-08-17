#include "DoubleWord.h"

void Binary::DoubleWord::write(std::ostream & os)
{
	TemplateWrite(*this, os);
}

void Binary::DoubleWord::read(std::istream & is)
{
	TemplateRead(*this, is);
}

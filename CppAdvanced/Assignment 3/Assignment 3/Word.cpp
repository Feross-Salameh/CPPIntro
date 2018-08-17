#include "Word.h"

void Binary::Word::write(std::ostream & os)
{
	TemplateWrite(*this, os);
}

void Binary::Word::read(std::istream & is)
{
	TemplateRead(*this, is);
}



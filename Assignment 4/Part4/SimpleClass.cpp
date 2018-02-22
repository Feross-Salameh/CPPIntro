#include "SimpleClass.h"



SimpleClass::SimpleClass()
{
	std::cout << "Default constructor called" << std::endl;
}

SimpleClass::SimpleClass(const SimpleClass & stc)
{
	std::cout << "Copy constructor called" << std::endl;

}

SimpleClass::~SimpleClass()
{
	std::cout << "Deconstructor called" << std::endl;

}


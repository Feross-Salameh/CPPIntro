#include "CharQueue1.h"


// default constuctor
CharQueue1::CharQueue1()
{
}

CharQueue1::CharQueue1(size_t size) : 
	mySize{size}, 
	myIndex{ 0 },
	myArray{ std::make_unique<char[]>(mySize)}
{
	std::cout << "CharQueue1 constructor called" << std::endl;
}

CharQueue1::CharQueue1(const CharQueue1& src) :
	mySize{src.mySize},
	myIndex{src.myIndex},
	myArray{std::make_unique<char[]>(mySize)}
{
	
}


CharQueue1::~CharQueue1()
{
}

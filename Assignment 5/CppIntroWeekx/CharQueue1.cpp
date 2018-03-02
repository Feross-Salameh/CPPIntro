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

}

CharQueue1::CharQueue1(const CharQueue1& src) :
	mySize{src.mySize},
	myIndex{src.myIndex},
	myArray{ std::make_unique<char[]>(mySize)}
{
	for (unsigned int i = 0; i < mySize; i++)
		myArray.get()[i] = src.myArray.get()[i];
}

///adds a char to the queue 
void CharQueue1::enqueue(char ch)
{
	myArray.get()[myIndex++] = ch;
	// if we need to create a bigger array:
	if (myIndex == mySize)
	{
		auto temp = std::make_unique<char[]>(++mySize); // I'm assuming make_unique uses new???
		for (unsigned int i = 0; i < myIndex; i++)
			temp.get()[i] = myArray.get()[i];
		myArray = std::move(temp);
	}
	
}

// the time complexity for this O(n). I can make it constant time by using a circular queue, 
// but the requirements didn't ask for it.
char CharQueue1::dequeue()
{
	if(isEmpty())
		return '\0';
	auto tmp = myArray.get()[0];
	for (int i = 1; i <= myIndex; i++)
		myArray.get()[i - 1] = myArray.get()[i];
	myIndex--;
	return tmp;
	
}

bool CharQueue1::isEmpty() const
{
	return (myIndex == 0);
}

void CharQueue1::swap(CharQueue1& src)
{
	auto temp = CharQueue1(src);
	src = *this;
	*this = temp;
}

int CharQueue1::capacity() const
{
	return mySize;
}


CharQueue1& CharQueue1::operator=(CharQueue1 src)
{
	this->mySize = src.mySize;
	this->myIndex = src.myIndex;
	auto temp = std::make_unique<char[]>(this->mySize);
	for (unsigned int i = 0; i < this->myIndex; i++)
		temp.get()[i] = src.myArray.get()[i];
	myArray = std::move(temp);
	return *this;
}


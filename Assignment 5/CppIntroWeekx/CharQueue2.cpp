#include "CharQueue2.h"



CharQueue2::CharQueue2() : 
	myArray{std::deque<char>()}
{

}

CharQueue2::CharQueue2(size_t size) :
	myArray{ std::deque<char>(size) }
{
	myArray.clear();
}

void CharQueue2::enqueue(char ch)
{
	myArray.push_back(ch);
}

char CharQueue2::dequeue()
{
	char c = '\0';
	if (!isEmpty())
	{
		c = myArray.front();
		myArray.pop_front();
	}
		
	myArray.shrink_to_fit();
	return c;
}

bool CharQueue2::isEmpty() const
{
	return myArray.empty();
}

void CharQueue2::swap(CharQueue2& src)
{
	auto tmp = this->myArray;
	this->myArray = src.myArray;
	src.myArray = tmp;
}

int CharQueue2::capacity() const
{
	return myArray.max_size();
}

CharQueue2& CharQueue2::operator=(CharQueue2 src)
{
	this->myArray = src.myArray;
	return *this;
}
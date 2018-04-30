#include "Circle.h"



Circle::Circle(int radius, int xCoord, int yCoord, const char * name ) :
	mRadius{radius}, mXCoord{xCoord}, mYCoord{yCoord}
{
	// setting up mName. Will need to copy from name ptr
	if (name == nullptr) // if null, no need to continue with constructor 
		return;
	mName = new char[strlen(name) + 1];
	strcpy_s(mName, strlen(name) + 1, name);
}

Circle::Circle(const Circle & rhs)
{
	// DONE: insert return statement here
	if (this == &rhs)
		return;
	// in case of any failures, I will try and swap names first.
	try
	{
		char * buffer = new char[strlen(rhs.mName) + 1];
		strcpy_s(buffer, strlen(rhs.mName) + 1, rhs.mName);
		// we know at this point the copy passed successfully. can now move all variables.
		delete[] this->mName; // no memory leaking
		this->mName = buffer;
		this->mRadius = rhs.mRadius;
		this->mXCoord = rhs.mXCoord;
		this->mYCoord = rhs.mYCoord;
	}
	catch (const std::exception&)
	{
		// we should do nothing here?
	}
}

Circle::~Circle() // since we used new in constructor, need to use delete as well.
{
	delete[] mName;
}
// overloaded addition operator. I've added the X and Y coordinates as well as given the new circle a name.
Circle Circle::operator+(const Circle& rhs)
{
	return Circle(this->mRadius + rhs.mRadius, this->mXCoord + rhs.mXCoord, this->mYCoord + rhs.mYCoord, "New Circle");
}

Circle & Circle::operator=(const Circle & rhs)
{
	// DONE: insert return statement here
	if (this == &rhs)
		return *this;
	// in case of any failures, I will try and swap names first.
	try
	{
		char * buffer = new char[strlen(rhs.mName) + 1];
		strcpy_s(buffer, strlen(rhs.mName) + 1, rhs.mName);
		// we know at this point the copy passed successfully. can now move all variables.
		delete[] this->mName; // no memory leaking
		this->mName = buffer;
		this->mRadius = rhs.mRadius;
		this->mXCoord = rhs.mXCoord;
		this->mYCoord = rhs.mYCoord;
	}
	catch (const std::exception&)
	{
		// we should do nothing here?
	}
	return *this;
}

Circle Circle::operator++()
{
	this->mRadius++;
	return *this;
}

Circle Circle::operator++(int)
{
	Circle tmp(*this);
	operator++();
	return tmp;
}

std::ostream & operator<<(std::ostream& os, const Circle & c)
{
	os << "Circle radius: " << c.mRadius << " at (" << c.mXCoord << "," << c.mYCoord << ").";
	return os;
}

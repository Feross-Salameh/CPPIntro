#include "DyArray.h"


// normal ccor
DyArray::DyArray(size_t size) :
	mySize(size),
	myCount(0),
	myData(new int[size] { 0 })
{

}

// default ctor, chains from normal
DyArray::DyArray() : DyArray(0)
{
}

// copy ctor, chains from normal
DyArray::DyArray(DyArray& rhs) : DyArray(rhs.mySize)
{
	std::copy(rhs.myData, rhs.myData + this->mySize, this->myData);
}

DyArray& DyArray::operator=(DyArray& rhs)
{
	this->myCount = rhs.myCount;
	this->mySize = rhs.mySize;

	delete this->myData;
	this->myData = new int[this->mySize]{ 0 };
	std::copy(rhs.myData, rhs.myData + this->mySize, this->myData);

	return *this;
}

DyArray::~DyArray()
{
	delete myData;
}


void DyArray::put(int index, int value)
{
	expand(index);
	myData[index] = value;
	if (index > myCount)
		myCount = index;
}


int DyArray::get(int index) const
{
	if (index < 0 || index > myCount)
		return 0;
	else
		return myData[index];
}

/*
	This function is a bit tricky in my opinion. Just because the user can lets say populate
	the indicies 0 and 10. if that's the case we technically have 8 emplty spots we could contract. 
	Since nothing was specified, I will just shift everything down and contract if mySize - myCount is > 5 to save on computation time
*/
void DyArray::remove(int index)
{
	for (int i = index; i <= myCount; i++)
		myData[i] = myData[i + 1];
	if (mySize - myCount >= 5)
		contract();
}


int& DyArray::operator[] (int index)
{
	expand(index);
	if (index > myCount)
		myCount = index + 1;
	return this->myData[index];
}

int& DyArray::operator[] (int index) const
{
	int zero = 0;
	if (index < 0 || index > myCount)
		return zero;
	else
		return this->myData[index];
}
//expands the current DyArray, if need be.
void DyArray::expand(int newSize)
{
	// after researching if there was an effective way to do this, most people said to use a vector that 
	// handles this sort of thing. But since I'm using a int * I'll have to get creative
	if (newSize <= mySize)
		return;
	auto tmpData = new int[newSize]{ 0 };
	std::copy(this->myData, this->myData + this->mySize, tmpData);
	this->mySize = newSize;
	
	delete this->myData;
	this->myData = tmpData;
}

// contracts array size to current count
void DyArray::contract()
{
	if (mySize == myCount) // no need to do anything
		return; 

	auto tmpData = new int[myCount] {0};
	std::copy(this->myData, this->myData + this->myCount, tmpData);

	this->mySize = this->myCount;

	delete this->myData;
	this->myData = tmpData;
}

std::ostream & operator<<(std::ostream & os, DyArray & da)
{
	os << "Dynamic Array contents: " << std::endl;
	for (int i = 0; i < da.myCount; i++)
	{
		os << "[" << i << "]: " << da[i] << std::endl;
	}

	return os;
}

#include "MyClass.h"

Probe MyClass::myProbe;

MyClass::MyClass() :
	myIndex(myProbe.getTotalCount()++)
{
	myProbe.getCurrentCount()++;
}


MyClass::~MyClass()
{
	myProbe.getCurrentCount()--;
}


unsigned int MyClass::getIndex() const
{
	return myIndex;
}
Probe & MyClass::getMyProbe()
{
	return myProbe;
}

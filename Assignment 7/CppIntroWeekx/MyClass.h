#include "Probe.h"
#pragma once
class MyClass
{
public:
	MyClass();
	~MyClass();
	static Probe& getMyProbe();
	unsigned int getIndex() const;
private:
	static Probe myProbe;
	unsigned int myIndex;
};


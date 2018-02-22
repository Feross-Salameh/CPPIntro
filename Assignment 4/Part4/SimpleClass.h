#pragma once
#include <iostream>
#include <string>

class SimpleClass
{
public:
	SimpleClass();
	SimpleClass(const SimpleClass& stc);
	~SimpleClass();

private:
	// nothing to be placed here...

};



void f1(SimpleClass aSimpleClass);
void f2(SimpleClass aSimpleClass);
void f3(SimpleClass& aSimpleClass);
void f4(SimpleClass* aSimpleClass);
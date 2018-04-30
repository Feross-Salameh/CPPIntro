#pragma once
#include <stdio.h>
#include <string.h>
#include <exception> 
#include <iostream>
class Circle
{
public:
	Circle(int radius,
		int xCoord = 0, int yCoord = 0,
		const char * name = nullptr);
	Circle(const Circle& rhs);
	~Circle();

	Circle operator+(const Circle& rhs);
	Circle& operator=(const Circle& rhs);
	Circle operator++();
	Circle operator++(int);

	friend std::ostream& operator<<(std::ostream& os, const Circle& c);
private:
	int mXCoord;
	int mYCoord;
	int mRadius;
	char * mName; // this stores the name of the circle
};


#include <cstdio>
#include <iostream>
#include "Circle.h"

const int kMaxNameSize = 128;
using namespace std;

void CreateTwoCircles()
{
	char * name = new char[kMaxNameSize];
	const char * kName1 = "Cir1";
	const char * kName2 = " CircleNumber2";
	strncpy_s(name, kMaxNameSize, kName1, _TRUNCATE);
	Circle c1(2, 1, 1, name);
	strncpy_s(name, kMaxNameSize, kName2, _TRUNCATE);
	Circle c2(5, 1, 1, name);
	delete[] name;// delete first before printing the circle below
				  // Print the two below one after another
	cout << "c1 is " << c1 << endl; // Name printed: Cir1
	cout << "c2 is " << c2 << endl; // Name printed: CircleNumber2
}


void DoCircleAssignment()
{
	char * name = new char[kMaxNameSize];
	const char * kName1 = "Cir1";
	const char * kName2 = "CircleNumber2";
	strncpy_s(name, kMaxNameSize, kName1, _TRUNCATE);
	Circle c1(1, 0, 0, name);
	cout << "c1 is " << c1 << endl;
	strncpy_s(name, kMaxNameSize, kName2, _TRUNCATE);
	Circle c2(2, 1, 1, name);
	delete[] name;// delete first before printing the circle below
	cout << "Before assignment, c2 is " << c2 << endl;
	c2 = c1;
	cout << "After assignment, c2 is " << c2 << endl;
}
void CircleTest()
{
	CreateTwoCircles();
	DoCircleAssignment();
}
int main()
{
	Circle c1(5);
	Circle c2(5, 2, 4, "c2");
	CircleTest();
	return 0;
}
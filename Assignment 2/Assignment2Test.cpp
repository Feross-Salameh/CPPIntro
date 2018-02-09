#include "TestHarness.h"
#include <string>
#include <iostream>

using namespace std;
// Rename this file to match the functionality under test. E.g., StringTest.
// Add tests and CHECKs as required

// swaps the values of 2 int * using a temp
void SwapIntPtr(int *a, int *b)
{
	auto t = *a;
	*a = *b;
	*b = t;
}
// swaps the values of 2 ints using a temp
void SwapIntRef(int& a, int& b)
{
	auto t = 0;
	t = a;
	a = b;
	b = t;
}
TEST(Assignment2, Part1)
{
	// creating ints
	int a = 3, b = 4;
	// calling ptr swap
	SwapIntPtr(&a, &b); // after swap: b == 4, a == 3
	CHECK_EQUAL(4, a);
	CHECK_EQUAL(3, b);

	// calling ref swap
	SwapIntRef(a, b); // after swap: b == 3, a == 4
	CHECK_EQUAL(3, a);
	CHECK_EQUAL(4, b);

}

// struct to hold information about month
struct Month
{
	std::string name = "";
	int days = -1;
};

TEST(Assignment2, Part2)
{
	// creating arrays for the months:
	auto names = new char*[12];
	auto days = new int[12];

	// manually put in the months/ days: 
	names[0] = new char[8];		strcpy_s(names[0], 8, "January");		days[0] = 31;
	names[1] = new char[9];		strcpy_s(names[1], 9, "February");		days[1] = 28;
	names[2] = new char[6];		strcpy_s(names[2], 6, "March");			days[2] = 31;
	names[3] = new char[6];		strcpy_s(names[3], 6, "April");			days[3] = 30;
	names[4] = new char[4];		strcpy_s(names[4], 4, "May");			days[4] = 31;
	names[5] = new char[5];		strcpy_s(names[5], 5, "June");			days[5] = 30;
	names[6] = new char[5];		strcpy_s(names[6], 5, "July");			days[6] = 31;
	names[7] = new char[7];		strcpy_s(names[7], 7, "August");		days[7] = 31;
	names[8] = new char[10];	strcpy_s(names[8], 10, "September");	days[8] = 30;
	names[9] = new char[8];		strcpy_s(names[9], 8, "October");		days[9] = 31;
	names[10] = new char[9];	strcpy_s(names[10], 9, "November");		days[10] = 30;
	names[11] = new char[9];	strcpy_s(names[11], 9, "December");		days[11] = 31;
	CHECK_EQUAL("January", names[0]);
	CHECK_EQUAL("March", names[2]);
	CHECK_EQUAL(31, days[0]);
	CHECK_EQUAL(31, days[11]);

	// printing to string stream:
	std::stringstream ss;

	for (int i = 0; i < 12; i++)
		ss << "Month: " << names[i] << ". Days: " << days[i] << "\n\r";

	// second part. using struct.
	auto months = new Month[12];
	months[0].name = "January";		months[0].days = 31;
	months[1].name = "February";	months[1].days = 28;
	months[2].name = "March";		months[2].days = 31;
	months[3].name = "April";		months[3].days = 30;
	months[4].name = "May";			months[4].days = 31;
	months[5].name = "June";		months[5].days = 30;
	months[6].name = "July";		months[6].days = 31;
	months[7].name = "Augest";		months[7].days = 31;
	months[8].name = "September";	months[8].days = 30;
	months[9].name = "October";		months[9].days = 31;
	months[10].name = "November";	months[10].days = 30;
	months[11].name = "December";	months[11].days = 31;

	ss.clear();

	for(int i = 0; i < 12; i++)
		ss << "Month: " << months[i].name << ". Days: " << months[i].days << "\n\r";

}


char* CatPtr(char* a, char* b)
{

}
TEST(Assignment3, Part3)
{

}

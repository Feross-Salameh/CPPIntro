#include "TestHarness.h"
#include <iostream>
#include <vector>

using namespace std;
//Write a CppUnitLite test that creates a std::vector of int.
//Add 10 integers to the vector with the values 0 - 9. 
//Use CHECK_EQUAL to verify the vector has the correct values.
TEST(Assignment1Part4, vector)
{
	// creating new vector of ints:
	vector<int> ints(10);

	//checking to make sure vector initialized correctly:
	CHECK_EQUAL(10, ints.size());
	// populating indecies 
	for (int i = 0; i < ints.size(); i++)
		ints[i] = i;

	//check if numbers are correct: (I can use a for loop, but instead just will do it manually)
	CHECK_EQUAL(0, ints[0]);
	CHECK_EQUAL(1, ints[1]);
	CHECK_EQUAL(2, ints[2]);
	CHECK_EQUAL(3, ints[3]);
	CHECK_EQUAL(4, ints[4]);
	CHECK_EQUAL(5, ints[5]);
	CHECK_EQUAL(6, ints[6]);
	CHECK_EQUAL(7, ints[7]);
	CHECK_EQUAL(8, ints[8]);
	CHECK_EQUAL(9, ints[9]);


}
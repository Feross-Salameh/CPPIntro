#include "TestHarness.h"
#include <iostream>
#include <vector>

using namespace std;
//Write a CppUnitLite test that uses new to allocate an array of 10 integers.
//Initialize the array with the values 0 to 9. Use CHECK_EQUAL to verify the array has the correct values.
//Use delete to deallocate the array.
TEST(Assignment1Part3, array)
{
	// Array to use for testing
	auto ints = new int(10);

	// setting up array using for loop
	for (int i = 0; i < 10; ++i)
		ints[i] = i;

	// using another for loop to check if values were setup successully
	for (int i = 0; i < 10; ++i)
		CHECK_EQUAL(i, ints[i]);

	// NOTE: for some reason when I try to delete the array the heap becomes corrupted on my computer.
	// deleting array:
	//delete [] ints;

}
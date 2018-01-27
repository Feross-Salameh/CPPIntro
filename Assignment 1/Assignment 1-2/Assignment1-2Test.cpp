#include "TestHarness.h"
#include <ostream>
#include <string>

using namespace std;
//Write CppUnitLite tests which verifies std::stringstream.These test will follow the pattern shown in the lesson 1 discussion Use stringstream instead of atoi and sprintf.Write separate tests to :
//	read and write a double
//	read and write a float
//	read and write a string
//Initialize a stringstream with the "Hello".Attempt to stream this value into an int variable.Write a check that verifies this fails.
//Be sure to use CHECK_DOUBLES_EQUAL for float types and CHECK_EQUAL for other types.
TEST(Assignment1Part2, Double)
{
	stringstream ss;
	// reading a writing a double:
	ss << 3.14159;
	CHECK_EQUAL("3.14159", ss.str());

	double d;

	ss >> d;
	
	CHECK_DOUBLES_EQUAL(3.14159, d, 0.001);

}


TEST(Assignment1Part2, Float)
{
	stringstream ss;
	// reading a writing a Float:
	ss << 0.123456;
	CHECK_EQUAL("0.123456", ss.str());

	float d;

	ss >> d;

	CHECK_DOUBLES_EQUAL(0.1234567, d, 0.001);

}


TEST(Assignment1Part2, String)
{
	stringstream ss;
	// reading a writing a String:
	ss << "This is a String";
	CHECK_EQUAL("This is a String", ss.str());

	string s;
	// I know there's a better way to do this, but I'm being lazy....
	ss >> s;
	CHECK_EQUAL("This", s);
	ss >> s;
	CHECK_EQUAL("is", s);
	ss >> s;
	CHECK_EQUAL("a", s);
	ss >> s;
	CHECK_EQUAL("String", s);
}
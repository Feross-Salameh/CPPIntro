#include "ranged_number.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>

using namespace BitmapGraphics;
using namespace std;

TEST(lower, ranged_number)
{
	ranged_number<int, 0, 255> rn;

	rn = 1;
	CHECK_EQUAL(1, rn);

	rn = 0;
	CHECK_EQUAL(0, rn);

	rn = -1;
	CHECK_EQUAL(0, rn);
}

TEST(upper, ranged_number)
{
	ranged_number<int, 0, 10> rn;

	rn = 9;
	CHECK_EQUAL(9, rn);

	rn = 10;
	CHECK_EQUAL(10, rn);

	rn = 11;
	CHECK_EQUAL(10, rn);

}
#include "Color.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>

using namespace std;
using namespace Bitmap;
TEST(ctor, Color)
{
	Color c1(55, 55, 55);

	CHECK_EQUAL(55, c1.getBlue());
	CHECK_EQUAL(55, c1.getGreen());
	CHECK_EQUAL(55, c1.getRed());

	Color c2(c1);

	CHECK_EQUAL(55, c2.getBlue());
	CHECK_EQUAL(55, c2.getGreen());
	CHECK_EQUAL(55, c2.getRed());

	Color c3(move(c1));

	CHECK_EQUAL(55, c3.getBlue());
	CHECK_EQUAL(55, c3.getGreen());
	CHECK_EQUAL(55, c3.getRed());
}

TEST(settors, Color)
{
	Color c1;

	c1.setBlue(55);

	CHECK_EQUAL(55, c1.getBlue());

	c1.setBlue(100);

	CHECK_EQUAL(100, c1.getBlue());

	c1.setRed(55);

	CHECK_EQUAL(55, c1.getRed());

	c1.setRed(100);

	CHECK_EQUAL(100, c1.getRed());

	c1.setGreen(55);

	CHECK_EQUAL(55, c1.getGreen());

	c1.setGreen(100);

	CHECK_EQUAL(100, c1.getGreen());
}
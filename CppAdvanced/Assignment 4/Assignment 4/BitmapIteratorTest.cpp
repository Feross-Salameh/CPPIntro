#include "WindowsBitmapDecoder.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include <fstream>


using namespace std;
using namespace BitmapGraphics;

TEST(ctor, BitmapIterator)
{
	ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	auto decoder = WindowsBitmapDecoder(bmp, "image/x-ms-bmp");

	auto iter = decoder.createIterator();

	CHECK_EQUAL(100, iter->getBitmapHeight());
	CHECK_EQUAL(100, iter->getBitmapWidth());

}
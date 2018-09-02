#include "WindowsBitmapDecoder.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include <fstream>


using namespace std;
using namespace BitmapGraphics;

TEST(Decode, WindowsBitmapDecoder)
{
	ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	auto decoder = WindowsBitmapDecoder(bmp, "image/x-ms-bmp");
	CHECK_EQUAL(true, decoder.isSupported());
}



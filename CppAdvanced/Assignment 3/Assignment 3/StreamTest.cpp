#include "BitmapStream.h"
#include "WindowsBitmap.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>

using namespace std;
using namespace Bitmap;

TEST(Main, BitmapStream)
{
	BitmapStream stream;

	WindowsBitmap bitmap;

	char* error = new char();

	if (!stream.ReadInBitmap("bitmap.bmp", bitmap, error))
	{
		cout << "Could not read in bitmap file. Error: " << error << endl;
		CHECK(0);
	}

	if (!stream.WriteOutBitmap("test.bmp", bitmap, error))
	{
		cout << "Could not write out bitmap file. Error: " << error << endl;
		CHECK(0);
	}

	WindowsBitmap bitmap2;

	if (!stream.ReadInBitmap("test.bmp", bitmap2, error))
	{
		cout << "Could not read in bitmap file. Error: " << error << endl;
		CHECK(0);
	}

	CHECK_EQUAL(bitmap, bitmap2);
}
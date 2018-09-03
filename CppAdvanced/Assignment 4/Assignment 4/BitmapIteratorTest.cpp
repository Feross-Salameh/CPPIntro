#include "WindowsBitmapDecoder.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include <fstream>
#include <algorithm>

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

TEST(lineCount, BitmapIterator)
{
	ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	auto iter = WindowsBitmapDecoder(bmp, "image/x-ms-bmp").createIterator();

	try
	{
		for (size_t i = 0; i < 99; i++)
		{
			iter->nextScanLine();
		}
	}
	catch (const std::exception&)
	{
		CHECK(0)
	}
	
	try
	{
		iter->nextScanLine();
		CHECK(0);
	}
	catch (const std::exception&)
	{
		CHECK(1);
	}

}

TEST(Pixel, BitmapIterator)
{
	ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	auto iter = WindowsBitmapDecoder(bmp, "image/x-ms-bmp").createIterator();
	try
	{
		auto color = iter->getColor();
		iter->nextPixel();
		auto colot2 = iter->getColor();
		CHECK(1);
	}
	catch (const std::exception&)
	{
		CHECK(0);
	}
	


}
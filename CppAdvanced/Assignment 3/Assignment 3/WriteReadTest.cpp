#include "WindowsBitmap.h"
#include "WindowsBitmapHeader.h"
#include "SizeWord.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include <fstream>
using namespace Binary;
using namespace Bitmap;
TEST(readByte, Byte)
{
	std::ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	Byte b;
	b.read(bmp);
	CHECK_EQUAL('B', b);
	
}

TEST(readByte, Word)
{
	std::ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	Word b;
	b.read(bmp);
	CHECK_EQUAL(0x4D42, b);
	std::ofstream bmp2("test.bmp", std::ios::out | std::ios::binary);
	b.write(bmp2);
}

TEST(readBMPH, WindowsBitmapHeader)
{
	std::ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	WindowsBitmapHeader wbh;
	wbh.ReadFileHeader(bmp);

	CHECK_EQUAL('B', wbh.getFirstIdentifier());
	CHECK_EQUAL('M', wbh.getSecondIdentifier());
	CHECK_EQUAL(30054, wbh.getFileSize());
	CHECK_EQUAL(0, wbh.getReserved());

	wbh.ReadInfoHeader(bmp);

	CHECK_EQUAL(40, wbh.getInfoHeaderBytes());
	CHECK_EQUAL(100, wbh.getBitmapWidth());
	CHECK_EQUAL(100, wbh.getBitmapHeight());
}


TEST(writeBMPH, WindowsBitmapHeader)
{
	std::ifstream bmp("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmp.is_open())
	{
		throw "Unable to open file";
	}
	WindowsBitmapHeader wbh;
	wbh.ReadFileHeader(bmp);
	wbh.ReadInfoHeader(bmp);


	std::ofstream bmpOut("Test.bmp", std::ios::out | std::ios::binary);
	wbh.writeFileHeader(bmpOut);
	wbh.writeInfoHeader(bmpOut);
	bmpOut.close();


	std::ifstream bmpIn("Test.bmp", std::ios::in | std::ios::binary);
	if (!bmpIn.is_open())
	{
		throw "Unable to open file";
	}
	WindowsBitmapHeader wbh2;

	wbh2.ReadFileHeader(bmpIn);

	CHECK_EQUAL('B', wbh2.getFirstIdentifier());
	CHECK_EQUAL('M', wbh2.getSecondIdentifier());
	CHECK_EQUAL(30054, wbh2.getFileSize());
	CHECK_EQUAL(0, wbh2.getReserved());
	WindowsBitmapHeader wbh3;
	wbh3.ReadInfoHeader(bmpIn);

	CHECK_EQUAL(40, wbh3.getInfoHeaderBytes());
	CHECK_EQUAL(100, wbh3.getBitmapWidth());
	CHECK_EQUAL(100, wbh3.getBitmapHeight());
}

TEST(readBitmap, WindowsBitmap)
{
	std::ifstream bmpFile("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmpFile.is_open())
	{
		throw "Unable to open file";
	}
	WindowsBitmap bitmap(bmpFile);

	CHECK_EQUAL(100, bitmap.getHeight());
	CHECK_EQUAL(100, bitmap.getWidth());
	CHECK_EQUAL(30054, bitmap.getFileSize());


}

TEST(writeBitmap, WindowsBitmap)
{
	std::ifstream bmpFile("basic.bmp", std::ios::in | std::ios::binary);
	if (!bmpFile.is_open())
	{
		throw "Unable to open file";
	}
	WindowsBitmap bitmap(bmpFile);

	std::ofstream bmpOut("Test.bmp", std::ios::out | std::ios::binary);

	bitmap.Write(bmpOut);
	bmpOut.close();

	std::ifstream bmpIn("Test.bmp", std::ios::in | std::ios::binary);
	if (!bmpIn.is_open())
	{
		throw "Unable to open file";
	}
	WindowsBitmap bitmapIn(bmpIn);


	CHECK_EQUAL(bitmap, bitmapIn);
}
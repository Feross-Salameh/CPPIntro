#include "BitmapStream.h"
using namespace std;
bool BitmapStream::ReadInBitmap(const char * bitmapFile, Bitmap::WindowsBitmap & bitmap, char * errorMessage)
{
	if (!filesystem::exists(bitmapFile))
	{
		string error = "File does not exist";
		strcpy_s(errorMessage, sizeof(error.c_str()), error.c_str());
		return false;
	}

	std::ifstream bitmapStream(bitmapFile, ios::in | ios::binary);
	if (!bitmapStream.is_open())
	{
		string error = "unable to open file";
		strcpy_s(errorMessage, sizeof(error.c_str()), error.c_str());
		return false;
	}

	try
	{
		Bitmap::WindowsBitmap tempBitmap(bitmapStream);
		bitmap = move(tempBitmap);
	}
	catch (const std::exception& ex)
	{
		strcpy_s(errorMessage, sizeof(ex.what()), ex.what());
		return false;
	}
	
	return true;
}

bool BitmapStream::WriteOutBitmap(const char * bitmapFile, const Bitmap::WindowsBitmap & bitmap, char * errorMessage)
{
	try
	{
		std::ofstream bmpOut("Test.bmp", std::ios::out | std::ios::binary);
	}
	catch (const std::exception& ex)
	{
		strcpy_s(errorMessage, sizeof(ex.what()), ex.what());
		return false;
	}
	return true;
}

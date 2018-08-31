#pragma once
#include "SizeWord.h"
#include "WindowsBitmap.h"
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>


class BitmapStream
{
public:
	BitmapStream() = default;
	~BitmapStream() = default;
	BitmapStream(const BitmapStream&) = delete;
	BitmapStream(BitmapStream&&) = delete;
	BitmapStream& operator=(const BitmapStream&) = delete;
	BitmapStream& operator=(BitmapStream&&) = delete;

	bool ReadInBitmap(const char* bitmapFile, Bitmap::WindowsBitmap& bitmap, char* errorMessage);
	bool WriteOutBitmap(const char* bitmapFile, const Bitmap::WindowsBitmap& bitmap, char* errorMessage);
};


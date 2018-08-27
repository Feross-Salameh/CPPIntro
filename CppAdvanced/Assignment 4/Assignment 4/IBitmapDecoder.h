#pragma once
#include"IBitmapIterator.h"
#include <string>

namespace BitmapGraphics
{
	class IBitmapDecoder
	{
	public:

		IBitmapDecoder() {};
		virtual ~IBitmapDecoder() {};
		virtual IBitmapDecoder* clone() = 0;
		virtual HBitmapIterator createIterator() = 0;
		virtual std::string getMimeType() = 0;
		virtual bool isSupported() = 0;
	};
	using HBitmapDecoder = IBitmapDecoder * ;
}




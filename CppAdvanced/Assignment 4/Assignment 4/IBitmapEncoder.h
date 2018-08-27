#pragma once
#include "IBitmapIterator.h"
#include <string>

namespace BitmapGraphics
{
	class IBitmapEncoder
	{
	public:
		IBitmapEncoder() {};
		virtual ~IBitmapEncoder() {};
		virtual IBitmapEncoder * clone() = 0;
		virtual void encodeToStream() = 0;
		virtual std::string getMimeType() = 0;
	};
	using HBitmapEncoder = IBitmapEncoder * ;


}


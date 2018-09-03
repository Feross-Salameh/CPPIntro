#pragma once
#include "IBitmapIterator.h"
#include <string>
#include <iostream>
namespace BitmapGraphics
{
	class IBitmapEncoder
	{
	public:
		IBitmapEncoder() {};
		virtual ~IBitmapEncoder() {};
		virtual IBitmapEncoder & clone() = 0;
		virtual void encodeToStream(std::ostream& os) = 0;
		virtual std::string getMimeType() = 0;
	private:
		HBitmapIterator myIterator;
	};
	using HBitmapEncoder = IBitmapEncoder&;


}


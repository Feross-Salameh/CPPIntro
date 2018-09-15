#include "Bitmap.h"
#include "BitmapIterator.h"
#include <memory>

namespace Framework
{

	Bitmap::ScanLineIterator Bitmap::begin()
	{
		return myScanLines.begin();
	}

	Bitmap::ScanLineIterator Bitmap::end()
	{
		return myScanLines.end();
	}

	HBitmapIterator Bitmap::createIterator()
	{
		return std::make_unique<BitmapIterator>(*this);
	}
}
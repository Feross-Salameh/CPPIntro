#include "WindowsBitmap.h"

using namespace Bitmap;

Bitmap::WindowsBitmap::WindowsBitmap(std::istream & sourceStream)
{

}

WindowsBitmap::ScanLineItorator Bitmap::WindowsBitmap::begin()
{
	myScanLines.begin();
}

WindowsBitmap::ScanLineItorator Bitmap::WindowsBitmap::end()
{
	return myScanLines.end();
}

int Bitmap::WindowsBitmap::getWidth() const
{
	return static_cast<int>(myHeader.getBitmapWidth());
}

int Bitmap::WindowsBitmap::getHeight() const
{
	return static_cast<int>(myHeader.getBitmapHeight());
}

int Bitmap::WindowsBitmap::getFileSize() const
{
	return static_cast<int>(myHeader.getFileSize());
}

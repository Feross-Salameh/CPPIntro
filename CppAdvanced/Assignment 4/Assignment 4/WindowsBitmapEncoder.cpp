#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator iterator) : myBitmapIterator(iterator)
	{

	}
	IBitmapEncoder & WindowsBitmapEncoder::clone()
	{
		auto tmp = new WindowsBitmapEncoder(*this);
		return *tmp;
	}
	void WindowsBitmapEncoder::encodeToStream(std::ostream& os)
	{
		WindowsBitmapHeader wbh;
		wbh.setBItmapHeight(myBitmapIterator->getBitmapHeight());
		wbh.setBitmapWidth(myBitmapIterator->getBitmapWidth());
		size_t fileSize = myBitmapIterator->getBitmapHeight() * myBitmapIterator->getBitmapHeight() * 3;
		fileSize += 54; // adding header
		wbh.setFileSize(fileSize);
		wbh.write(os);
		while (!myBitmapIterator->isEndOfImage())
		{
			myBitmapIterator->getColor().write(os);
			myBitmapIterator->nextPixel();
		}

	}
	std::string WindowsBitmapEncoder::getMimeType()
	{
		return "image/x-ms-bmp";
	}
}
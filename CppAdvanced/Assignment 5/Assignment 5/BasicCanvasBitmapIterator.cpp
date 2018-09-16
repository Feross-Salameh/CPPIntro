#include "BasicCanvasBitmapIterator.h"

namespace Framework
{
	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(BasicCanvas & canvas) : myCanvas{canvas}
	{
	}
	void BasicCanvasBitmapIterator::nextScanLine()
	{
		++currentY;
		if (!isEndOfImage())
		{
			currentX = 0;
		}
	}
	bool BasicCanvasBitmapIterator::isEndOfImage() const
	{
		return currentY == getBitmapWidth();
	}
	void BasicCanvasBitmapIterator::nextPixel()
	{
		++currentX;
	}
	bool BasicCanvasBitmapIterator::isEndOfScanLine() const
	{
		return currentX == getBitmapHeight();
	}
	Color BasicCanvasBitmapIterator::getColor() const
	{
		return myCanvas.getPixelColor(Point(currentX, currentY));
	}
	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return myCanvas.getWidth();
	}
	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return myCanvas.getHeight();
	}
}

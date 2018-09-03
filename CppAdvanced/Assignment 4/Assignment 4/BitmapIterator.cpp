#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(uint32_t width, uint32_t height, ScanLineCollection const & collection) : 
		myWidth{ width }, 
		myHeight{ height },
		myScanLineIterorator{collection.begin() },
		myScanLineBeginingIterorator{ collection.begin() },
		myScanLineEndingterorator{ collection.end() }
	{
		updateColorIterators();
	}

	void BitmapIterator::nextScanLine()
	{
		++myScanLineIterorator;
		if(myScanLineIterorator != myScanLineEndingterorator)
		{
			updateColorIterators();
		}
		else
		{
			throw std::out_of_range("Current End of Scan Lines");
		}
	}
	bool BitmapIterator::isEndOfImage() const
	{
		return myColorIterorator == myColorEndingIterorator && myScanLineIterorator == myScanLineEndingterorator;
	}
	void BitmapIterator::nextPixel()
	{
		if (isEndOfImage())
		{
			throw std::out_of_range("Current End of Image");
		}
		else if (isEndOfScanLine())
		{
			nextScanLine();
		}
		else
		{
			++myColorIterorator;
		}
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		return myColorIterorator == myColorEndingIterorator;
	}

	Color BitmapIterator::getColor() const
	{
		return myColorIterorator.operator*();
	}

	void BitmapIterator::updateColorIterators()
	{
		myColorIterorator = myScanLineIterorator.operator*().begin();
		myColorBeginingIterorator = myScanLineIterorator.operator*().begin();
		myColorEndingIterorator = myScanLineIterorator.operator*().end();
	}


}

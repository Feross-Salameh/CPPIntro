#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(uint32_t width, uint32_t height, Bitmap::ScanLineCollection const & collection) : 
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
		if(!isEndOfImage())
		{
			++myScanLineIterorator;
			updateColorIterators();
		}
			
	}
	bool BitmapIterator::isEndOfImage() const
	{
		return myColorIterorator == myColorEndingIterorator;
	}
	void BitmapIterator::nextPixel()
	{
		if(!isEndOfScanLine())
			++myColorIterorator;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		return myScanLineIterorator == myScanLineEndingterorator;
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

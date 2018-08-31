#include "Bitmap.h"

namespace BitmapGraphics
{
    Bitmap::Bitmap(uint32_t width, uint32_t height, ScanLineCollection collection) :
    myWidth{width},
    myHeight{height},
	myScanLines{collection}
    {
    }
    
    int Bitmap::getNumberOfPadBytes() const
    {
        const auto remainder = (myWidth * 3) % 4;
        return (remainder == 0) ? 0 : (4 - remainder);
    }

	HBitmapIterator Bitmap::createIterator()
	{
		IBitmapIterator* newBitmap = new BitmapIterator(myWidth, myHeight, myScanLines);
		
		return *newBitmap;
	}

    
}
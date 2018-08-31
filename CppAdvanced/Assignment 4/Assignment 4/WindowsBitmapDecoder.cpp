#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream & is, std::string mimeType) : myBitmap{}, myMIMEType{ mimeType }
	{
		if (!isSupported())
			return;
		WindowsBitmapHeader bitmapHeader = WindowsBitmapHeader(is);

		std::list<Bitmap::ScanLine> newScanLines;

		for (auto row = 0u; row < bitmapHeader.getBitmapHeight(); ++row)
		{
			Bitmap::ScanLine scanLine;

			// Read row of pixels
			for (auto column = 0u; column < bitmapHeader.getBitmapWidth(); ++column)
			{
				scanLine.push_back(Color::read(is));
			}

			// Read and ignore pad bytes (if any)
			for (auto pad = 0; pad < ((bitmapHeader.getBitmapWidth() * 3) % 4 == 0) ? 0 : (4 - (bitmapHeader.getBitmapWidth() * 3) % 4); ++pad)
			{
				Binary::Byte::read(is);
			}

			newScanLines.push_back(std::move(scanLine));
		}

		myBitmap = new Bitmap(bitmapHeader.getBitmapWidth(), bitmapHeader.getBitmapHeight(), std::move(newScanLines));
	}


}



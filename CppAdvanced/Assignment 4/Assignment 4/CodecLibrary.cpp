#include "CodecLibrary.h"

namespace BitmapGraphics
{
	HBitmapDecoder CodecLibrary::createDecoder(std::istream & sourceStream)
	{
		// TODO: refractor this, should be done in a 
		Binary::Byte firstByte(sourceStream.peek());
		sourceStream.seekg(1);
		Binary::Byte secondByte(sourceStream.peek());
		sourceStream.seekg(0);
		IBitmapDecoder* decoder;
		// decoder selection:
		if (firstByte == Binary::Byte('B') && secondByte == Binary::Byte('M'))
		{
			decoder = new WindowsBitmapDecoder(sourceStream, "image/x-ms-bmp");
		}
		else
		{
			decoder = nullptr;
		}
		
		return *decoder;
	}
	HBitmapDecoder CodecLibrary::createDecoder(std::string const & mimeType, std::istream & sourceStream)
	{
		IBitmapDecoder* decoder;

		if (mimeType == "image/x-ms-bmp")
		{
			decoder = new WindowsBitmapDecoder(sourceStream, "image/x-ms-bmp");
		}
		else
		{
			decoder = nullptr;
		}
		return *decoder;
	}
}
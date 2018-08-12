#include "WindowsBitmapHeader.h"
#include "Byte.h"


Bitmap::WindowsBitmapHeader::WindowsBitmapHeader(Binary::DoubleWord fileSize, Binary::DoubleWord width, Binary::DoubleWord height) : fileSize{fileSize}, bitmapWidth{width}, bitmapHeight{height}
{

}

Bitmap::WindowsBitmapHeader::WindowsBitmapHeader() : WindowsBitmapHeader(0,0, 0)
{
}

const Binary::Byte Bitmap::WindowsBitmapHeader::getFirstIdentifier() const
{
	return firstIdentifier;
}

const Binary::Byte Bitmap::WindowsBitmapHeader::getSecondIdentifier() const
{
	return secondIdentifier;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getFileSize() const
{
	return fileSize;
}

void Bitmap::WindowsBitmapHeader::setFileSize(const Binary::DoubleWord & other)
{
	fileSize = other;
}

void Bitmap::WindowsBitmapHeader::setFileSize(unsigned __int16 other)
{
	fileSize = other;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getReserved() const
{
	return reserved;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getRawImageByteOffset() const
{
	return rawImageByteOffset;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getInfoHeaderBytes() const
{
	return infoHeaderBytes;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getBitmapHeight() const
{
	return bitmapHeight;
}

void Bitmap::WindowsBitmapHeader::setBitmapHeight(const Binary::DoubleWord & other)
{
	bitmapHeight = other;
}

void Bitmap::WindowsBitmapHeader::setBitmapHeight(unsigned __int16 other)
{
	bitmapHeight = other;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getBitmapWidth() const
{
	return bitmapWidth;
}

void Bitmap::WindowsBitmapHeader::setBitmapWidth(const Binary::DoubleWord & other)
{
	bitmapWidth = other;
}

void Bitmap::WindowsBitmapHeader::setBitmapWidth(unsigned __int16 other)
{
	bitmapWidth = other;
}

const Binary::Word Bitmap::WindowsBitmapHeader::getNumberofPlanes() const
{
	return numberOfPlanes;
}

const Binary::Word Bitmap::WindowsBitmapHeader::getBitsPerPixel() const
{
	return bitsPerPixel;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getCompressionType() const
{
	return compressionType;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getCompressedImageSize() const
{
	return compressedImageSize;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getHorizontalPixelsPerMeter() const
{
	return horizontalPixelsPerMeter;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getVerticalPixelsPerMeter() const
{
	return verticalPixelsPerMeter;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getNumberOfColors() const
{
	return numberOfColors;
}

const Binary::DoubleWord Bitmap::WindowsBitmapHeader::getNumberOfImportantColors() const
{
	return numberOfImportantColors;
}

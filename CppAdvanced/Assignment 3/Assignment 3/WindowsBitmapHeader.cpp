#include "WindowsBitmapHeader.h"
//#include "Byte.h"

using namespace Bitmap;
// setting the static  members for code organization.
const Binary::Byte WindowsBitmapHeader::firstIdentifier = 'B';
const Binary::Byte WindowsBitmapHeader::secondIdentifier = 'M';

const Binary::DoubleWord WindowsBitmapHeader::reserved = 0;
const Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 0;


const Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 40;

const Binary::Word WindowsBitmapHeader::numberOfPlanes = 1;
const Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
const Binary::DoubleWord WindowsBitmapHeader::compressionType = 0;
const Binary::DoubleWord WindowsBitmapHeader::compressedImageSize = 0;
const Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter = 0;
const Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter = 0;
const Binary::DoubleWord WindowsBitmapHeader::numberOfColors = 0;
const Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors = 0;

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

void Bitmap::WindowsBitmapHeader::setFileSize(uint16_t other)
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

void Bitmap::WindowsBitmapHeader::setBitmapHeight(uint16_t other)
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

void Bitmap::WindowsBitmapHeader::setBitmapWidth(uint16_t other)
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

void Bitmap::WindowsBitmapHeader::writeFileHeader(std::ostream & destinationStream) const
{
	const_cast<Binary::Byte&>(firstIdentifier).write(destinationStream);
	const_cast<Binary::Byte&>(secondIdentifier).write(destinationStream);
	const_cast<Binary::DoubleWord&>(fileSize).write(destinationStream);
	const_cast<Binary::DoubleWord&>(reserved).write(destinationStream);
	const_cast<Binary::DoubleWord&>(rawImageByteOffset).write(destinationStream);
}

void Bitmap::WindowsBitmapHeader::ReadFileHeader(std::istream & SourceStream) const
{
	const_cast<Binary::Byte&>(firstIdentifier).read(SourceStream);
	const_cast<Binary::Byte&>(secondIdentifier).read(SourceStream);
	const_cast<Binary::DoubleWord&>(fileSize).read(SourceStream);
	const_cast<Binary::DoubleWord&>(reserved).read(SourceStream);
	const_cast<Binary::DoubleWord&>(rawImageByteOffset).read(SourceStream);
}



void Bitmap::WindowsBitmapHeader::writeInfoHeader(std::ostream & destinationStream) const
{
	const_cast<Binary::DoubleWord&>(infoHeaderBytes).write(destinationStream);
	const_cast<Binary::DoubleWord&>(bitmapWidth).write(destinationStream);
	const_cast<Binary::DoubleWord&>(bitmapHeight).write(destinationStream);
	const_cast<Binary::Word&>(numberOfPlanes).write(destinationStream);
	const_cast<Binary::Word&>(bitsPerPixel).write(destinationStream);
	const_cast<Binary::DoubleWord&>(compressionType).write(destinationStream);
	const_cast<Binary::DoubleWord&>(compressedImageSize).write(destinationStream);
	const_cast<Binary::DoubleWord&>(horizontalPixelsPerMeter).write(destinationStream);
	const_cast<Binary::DoubleWord&>(verticalPixelsPerMeter).write(destinationStream);
	const_cast<Binary::DoubleWord&>(numberOfColors).write(destinationStream);
	const_cast<Binary::DoubleWord&>(numberOfImportantColors).write(destinationStream);

}

void Bitmap::WindowsBitmapHeader::ReadInfoHeader(std::istream & SourceStream) const
{
	const_cast<Binary::DoubleWord&>(infoHeaderBytes).read(SourceStream);
	const_cast<Binary::DoubleWord&>(bitmapWidth).read(SourceStream);
	const_cast<Binary::DoubleWord&>(bitmapHeight).read(SourceStream);
	const_cast<Binary::Word&>(numberOfPlanes).read(SourceStream);
	const_cast<Binary::Word&>(bitsPerPixel).read(SourceStream);
	const_cast<Binary::DoubleWord&>(compressionType).read(SourceStream);
	const_cast<Binary::DoubleWord&>(compressedImageSize).read(SourceStream);
	const_cast<Binary::DoubleWord&>(horizontalPixelsPerMeter).read(SourceStream);
	const_cast<Binary::DoubleWord&>(verticalPixelsPerMeter).read(SourceStream);
	const_cast<Binary::DoubleWord&>(numberOfColors).read(SourceStream);
	const_cast<Binary::DoubleWord&>(numberOfImportantColors).read(SourceStream);
}



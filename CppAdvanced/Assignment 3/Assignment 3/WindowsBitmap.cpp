#include "WindowsBitmap.h"

using namespace Bitmap;

Bitmap::WindowsBitmap::WindowsBitmap(std::istream & sourceStream) : myHeader{std::make_unique<WindowsBitmapHeader>(sourceStream)}, myScanLines{std::make_unique<ScanLineCollection>()}
{
	ReadScanLines(sourceStream);
}

WindowsBitmap::ScanLineItorator Bitmap::WindowsBitmap::begin()
{
	return myScanLines->begin();
}

WindowsBitmap::ScanLineItorator Bitmap::WindowsBitmap::end()
{
	return myScanLines->end();
}

int Bitmap::WindowsBitmap::getWidth() const
{
	return static_cast<int>(myHeader->getBitmapWidth());
}

int Bitmap::WindowsBitmap::getHeight() const
{
	return static_cast<int>(myHeader->getBitmapHeight());
}

int Bitmap::WindowsBitmap::getFileSize() const
{
	return static_cast<int>(myHeader->getFileSize());
}

int Bitmap::WindowsBitmap::getRedAtPixel(int x, int y)
{
	return (*getColor(x, y)).getRed();
}

int Bitmap::WindowsBitmap::getGreenAtPixel(int x, int y)
{
	return (*getColor(x, y)).getGreen();
}

int Bitmap::WindowsBitmap::getBlueAtPixel(int x, int y)
{
	return (*getColor(x, y)).getBlue();
}

std::vector<int> Bitmap::WindowsBitmap::getPixel(int x, int y)
{
	Color pixel = (*getColor(x, y));

	auto colors = std::vector<int>(3);

	colors[0] = pixel.getBlue();
	colors[1] = pixel.getGreen();
	colors[2] = pixel.getRed();

	return colors;
}

void Bitmap::WindowsBitmap::ReadScanLines(std::istream & sourceStream)
{
	ScanLineCollection tempScanLineList;
	auto height = static_cast<size_t>(getHeight());
	auto width = static_cast<size_t>(getWidth());

	for (size_t i = 0; i < height; ++i)
	{
		ScanLine tempScanLine;
		for (size_t i = 0; i < width; ++i)
		{
			Binary::Byte blue;
			Binary::Byte green;
			Binary::Byte red;

			blue.read(sourceStream);
			green.read(sourceStream);
			red.read(sourceStream);

			tempScanLine.push_back(Color(blue, green, red));
		}
		tempScanLineList.push_back(tempScanLine);
	}

	// once reading is completed/ successful. I can now store into member data
	*myScanLines = std::move(tempScanLineList);
}

void Bitmap::WindowsBitmap::WriteScanLines(std::ostream & destinationStream)
{
	for (ScanLine line : *myScanLines)
	{
		for (Color pixel : line)
		{
			pixel.Write(destinationStream);
		}
	}
}



void Bitmap::WindowsBitmap::Write(std::ostream & destinationStream)
{
	myHeader->writeFileHeader(destinationStream);
	myHeader->writeInfoHeader(destinationStream);
	WriteScanLines(destinationStream);
}

bool Bitmap::WindowsBitmap::operator==(const WindowsBitmap & rhs)
{

	return *myHeader == *rhs.myHeader && *myScanLines == *rhs.myScanLines;
}

bool Bitmap::WindowsBitmap::operator!=(const WindowsBitmap & rhs)
{
	return !(*this == rhs);
}

Bitmap::WindowsBitmap::ScanLine::iterator Bitmap::WindowsBitmap::getColor(int x, int y)
{
	if (y >= getHeight() || x >= getWidth())
		throw std::out_of_range("coordinate not in bitmap");
	auto iterY = myScanLines->begin();
	std::advance(iterY, y);

	auto iterX = (*iterY).begin();
	std::advance(iterX, x);
	return iterX;
}

std::ostream & Bitmap::operator<<(std::ostream & os, const WindowsBitmap & bitmap)
{
	os << "Height: " << bitmap.getHeight() << ", Width: " << bitmap.getWidth() << ", File Size: " << bitmap.getFileSize();
	return os;
}

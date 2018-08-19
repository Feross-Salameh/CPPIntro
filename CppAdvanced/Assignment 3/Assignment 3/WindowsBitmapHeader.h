#pragma once
//#include "Byte.h"
//#include "Word.h"
//#include "DoubleWord.h"
#include "SizeWord.h"

namespace Bitmap
{
	class WindowsBitmapHeader
	{
	public:
		WindowsBitmapHeader();
		WindowsBitmapHeader(std::istream& is);
		WindowsBitmapHeader(Binary::DoubleWord fileSize, Binary::DoubleWord width, Binary::DoubleWord height);
		WindowsBitmapHeader(const WindowsBitmapHeader&) = default;
		WindowsBitmapHeader(WindowsBitmapHeader&&) = default;

		WindowsBitmapHeader& operator=(const WindowsBitmapHeader&) = default;
		WindowsBitmapHeader& operator=(WindowsBitmapHeader&&) = default;

		~WindowsBitmapHeader() = default;


		const Binary::Byte getFirstIdentifier() const;

		const Binary::Byte getSecondIdentifier() const;

		const Binary::DoubleWord getFileSize() const;

		void setFileSize(const Binary::DoubleWord& other);
		void setFileSize(uint16_t other);

		const Binary::DoubleWord getReserved() const;

		const Binary::DoubleWord getRawImageByteOffset() const;


		const Binary::DoubleWord getInfoHeaderBytes() const;

		const Binary::DoubleWord getBitmapHeight() const;

		void setBitmapHeight(const Binary::DoubleWord& other);
		void setBitmapHeight(uint16_t other);

		const Binary::DoubleWord getBitmapWidth() const;

		void setBitmapWidth(const Binary::DoubleWord& other);
		void setBitmapWidth(uint16_t other);

		const Binary::Word getNumberofPlanes() const;

		const Binary::Word getBitsPerPixel() const;

		const Binary::DoubleWord getCompressionType() const;

		const Binary::DoubleWord getCompressedImageSize() const;

		const Binary::DoubleWord getHorizontalPixelsPerMeter() const;

		const Binary::DoubleWord getVerticalPixelsPerMeter() const;

		const Binary::DoubleWord getNumberOfColors() const;

		const Binary::DoubleWord getNumberOfImportantColors() const;



		void writeFileHeader(std::ostream& destinationStream) const;
		void ReadFileHeader(std::istream& SourceStream) const;


		void writeInfoHeader(std::ostream& destinationStream) const;
		void ReadInfoHeader(std::istream& SourceStream) const;

		bool operator==(const WindowsBitmapHeader& rhs);
		bool operator!=(const WindowsBitmapHeader& rhs);
	private:
		// file header
		const static Binary::Byte firstIdentifier;
		const static Binary::Byte secondIdentifier;
		Binary::DoubleWord fileSize;
		const static Binary::DoubleWord reserved;
		const static Binary::DoubleWord rawImageByteOffset;

		// info header
		const static Binary::DoubleWord infoHeaderBytes;
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		const static Binary::Word numberOfPlanes;
		const static Binary::Word bitsPerPixel;
		const static Binary::DoubleWord compressionType;
		const static Binary::DoubleWord compressedImageSize;
		const static Binary::DoubleWord horizontalPixelsPerMeter;
		const static Binary::DoubleWord verticalPixelsPerMeter;
		const static Binary::DoubleWord numberOfColors;
		const static Binary::DoubleWord numberOfImportantColors;
	};






	

}


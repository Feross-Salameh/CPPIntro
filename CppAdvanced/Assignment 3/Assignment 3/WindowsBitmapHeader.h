#pragma once
#include "Byte.h"
#include "Word.h"
#include "DoubleWord.h"


namespace Bitmap
{
	class WindowsBitmapHeader
	{
	public:
		WindowsBitmapHeader();
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
		void setFileSize(unsigned __int16 other);

		const Binary::DoubleWord getReserved() const;

		const Binary::DoubleWord getRawImageByteOffset() const;


		const Binary::DoubleWord getInfoHeaderBytes() const;

		const Binary::DoubleWord getBitmapHeight() const;

		void setBitmapHeight(const Binary::DoubleWord& other);
		void setBitmapHeight(unsigned __int16 other);

		const Binary::DoubleWord getBitmapWidth() const;

		void setBitmapWidth(const Binary::DoubleWord& other);
		void setBitmapWidth(unsigned __int16 other);

		const Binary::Word getNumberofPlanes() const;

		const Binary::Word getBitsPerPixel() const;

		const Binary::DoubleWord getCompressionType() const;

		const Binary::DoubleWord getCompressedImageSize() const;

		const Binary::DoubleWord getHorizontalPixelsPerMeter() const;

		const Binary::DoubleWord getVerticalPixelsPerMeter() const;

		const Binary::DoubleWord getNumberOfColors() const;

		const Binary::DoubleWord getNumberOfImportantColors() const;



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

	// setting the static  members in the header for code organization.
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




	

}


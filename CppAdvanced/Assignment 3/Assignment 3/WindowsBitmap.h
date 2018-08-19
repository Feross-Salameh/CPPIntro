#pragma once
#include "Color.h"
#include "SizeWord.h"
#include "WindowsBitmapHeader.h"
#include <algorithm>
#include <list>
#include <iostream>
#include <memory>
#include <vector>
namespace Bitmap
{
	class WindowsBitmap
	{
	public:
		using ScanLine = std::list<Color>;

	private:
		using ScanLineCollection = std::list<ScanLine>;

	public:
		using ScanLineItorator = ScanLineCollection::iterator;

		WindowsBitmap(std::istream& sourceStream);

		WindowsBitmap(const WindowsBitmap&) = default;
		WindowsBitmap(WindowsBitmap&&) = default;

		WindowsBitmap& operator=(const WindowsBitmap&) = default;
		WindowsBitmap& operator=(WindowsBitmap&&) = default;

		~WindowsBitmap() = default;

		ScanLineItorator begin();
		ScanLineItorator end();

		int getWidth() const;
		int getHeight() const;
		int getFileSize() const;

		int getRedAtPixel(int x, int y);
		int getGreenAtPixel(int x, int y);
		int getBlueAtPixel(int x, int y);
		// pixels stored as 0-blue, 1-green, 2-red
		std::vector<int> getPixel(int x, int y);


		void ReadScanLines(std::istream& sourceStream);
		void WriteScanLines(std::ostream& destinationStream);

		void Write(std::ostream& destinationStream);

		bool operator==(const WindowsBitmap& rhs);
		bool operator!=(const WindowsBitmap& rhs);

		friend std::ostream& operator<<(std::ostream& os, const WindowsBitmap& bitmap);
	private:
		std::unique_ptr<WindowsBitmapHeader> myHeader;
		std::unique_ptr<ScanLineCollection> myScanLines;
		ScanLine::iterator getColor(int x, int y);
	};
}


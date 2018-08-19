#pragma once
#include "Color.h"
#include "SizeWord.h"
#include "WindowsBitmapHeader.h"
#include <algorithm>
#include <list>
#include <iostream>

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


	private:
		WindowsBitmapHeader myHeader;
		ScanLineCollection myScanLines;

	};
}


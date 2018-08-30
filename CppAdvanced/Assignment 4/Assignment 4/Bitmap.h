#pragma once

#include "Color.h"
#include "IBitmapIterator.h"
#include "BitmapIterator.h"
#include <list>

namespace BitmapGraphics
{
    class Bitmap
    {
    public:
        using ScanLine = std::list<Color>;
		using ColorItorator = ScanLine::const_iterator;
		using ScanLineCollection = std::list<ScanLine>;
		using ScanLineIterator = ScanLineCollection::const_iterator;
        
		Bitmap() = default;
        Bitmap(uint32_t width, uint32_t height, ScanLineCollection collection);

		Bitmap(const Bitmap&) noexcept = default;
		Bitmap(Bitmap&&) noexcept = default;

		Bitmap& operator=(const Bitmap&) = default;
		Bitmap& operator=(Bitmap&&) = default;
        
		~Bitmap() noexcept = default;

        ScanLineIterator begin() noexcept { return myScanLines.cbegin(); }
        ScanLineIterator end() noexcept { return myScanLines.cend(); }
        
        int getWidth() const noexcept { return myWidth; }
        int getHeight() const noexcept { return myHeight; }
        int getNumberOfPadBytes() const;
        

        
		HBitmapIterator createIterator();

    private:
		uint32_t myWidth{ 0 };
		uint32_t myHeight{ 0 };
        
        ScanLineCollection myScanLines;
    };
}
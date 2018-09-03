#pragma once
#include "IBitmapIterator.h"
#include <list>
namespace BitmapGraphics
{
	using ScanLine = std::list<Color>;
	using ColorItorator = ScanLine::const_iterator;
	using ScanLineCollection = std::list<ScanLine>;
	using ScanLineIterator = ScanLineCollection::const_iterator;
	class BitmapIterator :
		public IBitmapIterator
	{
	public:
		BitmapIterator() = delete;
		BitmapIterator(uint32_t width, uint32_t height, ScanLineCollection const& collection);
		~BitmapIterator() = default;
		BitmapIterator(BitmapIterator const&) = default;
		BitmapIterator(BitmapIterator &&) = default;

		BitmapIterator& operator=(BitmapIterator const&) = default;
		BitmapIterator& operator=(BitmapIterator &&) = default;
		
		virtual void nextScanLine() override;
		virtual bool isEndOfImage() const override;
		virtual void nextPixel() override;
		virtual bool isEndOfScanLine() const override;
		virtual Color getColor() const override;

		virtual int getBitmapWidth() const override { return myWidth; }
		virtual int getBitmapHeight() const override { return myHeight; }
	private:
		uint32_t myWidth{ 0 };
		uint32_t myHeight{ 0 };
		ScanLineIterator myScanLineIterorator;
		ScanLineIterator myScanLineBeginingIterorator;
		ScanLineIterator myScanLineEndingterorator;
		ColorItorator myColorIterorator;
		ColorItorator myColorBeginingIterorator;
		ColorItorator myColorEndingIterorator;

		void updateColorIterators();
	};
	

}

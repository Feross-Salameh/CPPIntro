#pragma once
#include "IBitmapIterator.h"
#include "Bitmap.h"

namespace BitmapGraphics
{
	class BitmapIterator :
		public IBitmapIterator
	{
	public:
		BitmapIterator() = delete;
		BitmapIterator(uint32_t width, uint32_t height, Bitmap::ScanLineCollection const& collection);
		BitmapIterator(Bitmap bitmap);
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
		Bitmap::ScanLineIterator myScanLineIterorator;
		Bitmap::ScanLineIterator myScanLineBeginingIterorator;
		Bitmap::ScanLineIterator myScanLineEndingterorator;
		Bitmap::ColorItorator myColorIterorator;
		Bitmap::ColorItorator myColorBeginingIterorator;
		Bitmap::ColorItorator myColorEndingIterorator;

		void updateColorIterators();
	};
	

}

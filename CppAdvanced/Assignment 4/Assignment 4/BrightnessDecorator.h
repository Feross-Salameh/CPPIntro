#pragma once
#include "IBitmapIterator.h"
#include "ranged_number.h"

namespace BitmapGraphics
{
	class BrightnessDecorator :
		public IBitmapIterator
	{
	public:
		BrightnessDecorator(HBitmapIterator iterator);
		BrightnessDecorator(HBitmapIterator iterator, int brightness);

		BrightnessDecorator(BrightnessDecorator const&) = default;
		BrightnessDecorator(BrightnessDecorator &&) = default;

		BrightnessDecorator& operator=(BrightnessDecorator const&) = default;
		BrightnessDecorator& operator=(BrightnessDecorator &&) = default;

		~BrightnessDecorator() = default;

		virtual void nextScanLine() override { myOriginalIterator->nextScanLine(); }
		virtual bool isEndOfImage() const override { return myOriginalIterator->isEndOfImage(); }
		virtual void nextPixel() override { myOriginalIterator->nextPixel(); }
		virtual bool isEndOfScanLine() const override { return myOriginalIterator->isEndOfScanLine(); }

		virtual Color getColor() const override;

		virtual int getBitmapWidth() const override { return myOriginalIterator->getBitmapWidth(); }
		virtual int getBitmapHeight() const override { return myOriginalIterator->getBitmapHeight(); }

		constexpr int getBrightnessAdjustment() { return myBrightnessAdjustment; }
		void setBrightnessAdjustment(int brightness) { myBrightnessAdjustment = brightness; }
	private:
		HBitmapIterator myOriginalIterator;
		int myBrightnessAdjustment{ 0 };
		using ColorComponent = ranged_number<int, 0, 255>;
	};

}

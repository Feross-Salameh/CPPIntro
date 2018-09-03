#pragma once
#include "IBitmapIterator.h"
#include "ranged_number.h"

namespace BitmapGraphics
{
	class ColorInversionDecorator :
		public IBitmapIterator
	{
	public:
		ColorInversionDecorator(HBitmapIterator iterator);

		ColorInversionDecorator(ColorInversionDecorator const&) = default;
		ColorInversionDecorator(ColorInversionDecorator &&) = default;

		ColorInversionDecorator& operator=(ColorInversionDecorator const&) = default;
		ColorInversionDecorator& operator=(ColorInversionDecorator &&) = default;

		~ColorInversionDecorator() = default;

		virtual void nextScanLine() override { myOriginalIterator->nextScanLine(); }
		virtual bool isEndOfImage() const override { return myOriginalIterator->isEndOfImage(); }
		virtual void nextPixel() override { myOriginalIterator->nextPixel(); }
		virtual bool isEndOfScanLine() const override { return myOriginalIterator->isEndOfScanLine(); }

		virtual Color getColor() const override;

		virtual int getBitmapWidth() const override { return myOriginalIterator->getBitmapWidth(); }
		virtual int getBitmapHeight() const override { return myOriginalIterator->getBitmapHeight(); }

	private:
		HBitmapIterator myOriginalIterator;
		using ColorComponent = ranged_number<int, 0, 255>;
	};

}



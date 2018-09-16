#pragma once
#include "IBitmapIterator.h"
#include "Color.h"
#include "BasicCanvas.h"
#include <vector>
namespace Framework
{
	class BasicCanvasBitmapIterator : public IBitmapIterator
	{
	public:
		BasicCanvasBitmapIterator(BasicCanvas& canvas);

		virtual void nextScanLine() override;
		virtual bool isEndOfImage() const override;
		virtual void nextPixel() override;
		virtual bool isEndOfScanLine() const override;
		virtual Color getColor() const override;

		virtual int getBitmapWidth() const override;
		virtual int getBitmapHeight() const override;

	private:
		BasicCanvas myCanvas;
		int currentX{ 0 };
		int currentY{ 0 };
	};
}


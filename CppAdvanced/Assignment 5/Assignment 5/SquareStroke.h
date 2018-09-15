#pragma once
#include "IStroke.h"
#include "IPen.h"

namespace VG
{
	class SquareStroke :
		public IStroke
	{
	public:
		SquareStroke() = default;
		~SquareStroke() = default;

		SquareStroke(SquareStroke const&) = default;
		SquareStroke(SquareStroke &&) = default;

		SquareStroke& operator=(SquareStroke const&) = default;
		SquareStroke& operator=(SquareStroke &&) = default;

		virtual void setSize(int size) override { mysize = size; }
		virtual int getSize() const override { return mysize; }
		virtual void setColor(BitmapGraphics::Color const& color) override { myColor = color; }
		virtual BitmapGraphics::Color getColor() const override { return myColor; }
		virtual HPen createPen(BitmapGraphics::HCanvas const& canvas) override;
	private:
		BitmapGraphics::Color myColor;
		int mysize;
		HPen myPenTip;
	};
}



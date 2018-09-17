#pragma once
#include "IPen.h"
#include "Color.h"
#include "SquareStroke.h"
namespace Framework
{
	class SquarePen :
		public IPen
	{
	public:
		SquarePen() = default;
		~SquarePen() = default;

		virtual void drawPoint(HCanvas canvas, Point const& point) override;

		void setSize(int size) { mySize = size; }
		int getSize() const { return mySize; }
		void setColor(Color const& color) { myColor = color; }
		Color getColor() const { return myColor; }

	private:
		Color myColor;
		int mySize;

	};
}


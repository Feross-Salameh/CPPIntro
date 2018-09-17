#pragma once
#include "IStroke.h"
#include "SquarePen.h"
namespace Framework
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

		SquareStroke(int size, Color color) :mySize{ size }, myColor{ color } {}

		virtual void setSize(int size) { mySize = size; }
		virtual int getSize() const { return mySize; }
		virtual void setColor(Color const& color) { myColor = color; }
		virtual Color getColor() const { return myColor; }
		virtual HPen createPen(HCanvas const& canvas);

	private:
		int mySize;
		Color myColor;
	};

}

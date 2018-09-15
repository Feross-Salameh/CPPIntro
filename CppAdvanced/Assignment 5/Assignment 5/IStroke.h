#pragma once
#include "VectorGraphic.h"
#include "Color.h"
#include "ICanvas.h"
#include "IPen.h"
#include <memory>

namespace VG
{
	class IStroke
	{
	public:
		virtual void setSize(int size) = 0;
		virtual int getSize() const = 0;
		virtual void setColor(BitmapGraphics::Color const& color) = 0;
		virtual BitmapGraphics::Color getColor() const = 0;
		virtual HPen createPen(BitmapGraphics::HCanvas const& canvas) = 0;
	};
	using HStroke = std::unique_ptr<IStroke>;

	HStroke getPen();
}
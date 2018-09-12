#pragma once
#include "IBitmapIterator.h"
#include "IProjecter.h"
#include "Color.h"
#include "Point.h"
#include "Scene.h"
#include "Layer.h"
#include "VectorGraphic.h"

#include <memory>

namespace BitmapGraphics
{
	class ICanvas
	{
	public:
		virtual void setPixelColor(VG::Point const& location, BitmapGraphics::Color const& color) = 0;
		virtual BitmapGraphics::Color getPixelColor(VG::Point const& location) const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual BitmapGraphics::HBitmapIterator createBitmapIterator() const = 0;

	};
	using HCanvas = std::unique_ptr<ICanvas>;

}



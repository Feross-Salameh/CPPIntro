#pragma once
#include "Point.h"
#include "ICanvas.h"
#include <memory>
namespace Framework
{
	class IPen
	{
	public:
		virtual void drawPoint(HCanvas canvas, Point const& point) = 0;
	};
	using HPen = std::unique_ptr<IPen>;
}
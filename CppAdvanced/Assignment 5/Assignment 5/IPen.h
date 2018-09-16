#pragma once
#include "Point.h"
#include <memory>
namespace Framework
{
	class IPen
	{
	public:
		virtual void drawPoint(Point const& point) = 0;
	};
	using HPen = std::unique_ptr<IPen>;
}
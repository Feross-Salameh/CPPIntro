#pragma once
#include "Point.h"
#include "ICanvas.h"

#include <memory>

namespace VG
{
	class IPen
	{
	public:
		virtual void drawPoint(VG::Point const& point) = 0;
	};

	using HPen = std::unique_ptr<IPen>;
}


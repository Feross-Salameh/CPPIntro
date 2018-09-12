#pragma once
#include "ICanvas.h"


namespace BitmapGraphics
{
	class IProjector
	{
	public:
		virtual void projectCanvas(BitmapGraphics::HCanvas const& canvas) = 0;
	};

}


#pragma once
#include "ICanvas.h"

namespace Framework
{
	class IProjector
	{
	public:
		virtual void projectCanvas(HCanvas const& canvas) = 0;
	};

	using HProjector = std::unique_ptr<IProjector>;
}
#include "SquareStroke.h"

namespace Framework
{
	HPen SquareStroke::createPen(HCanvas const & canvas)
	{
		SquarePen ss;
		ss.setColor(myColor);
		ss.setSize(mySize);
		return std::make_unique<SquarePen>(ss);
	}
}



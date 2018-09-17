#include "SquarePen.h"
#include <list>

using namespace std;
namespace Framework
{
	void SquarePen::drawPoint(HCanvas canvas, Point const & point)
	{
		//assuming size is in pixels

		int x = point.getX();
		int y = point.getY();
		for (int i = x - mySize / 2; i < (x + mySize / 2); ++i)
		{
			for (int j = y - mySize / 2; j < (y + mySize / 2); ++j)
			{
				Point p(i, j);
				(*canvas).setPixelColor(p, myColor);
			}
		}

	}
}

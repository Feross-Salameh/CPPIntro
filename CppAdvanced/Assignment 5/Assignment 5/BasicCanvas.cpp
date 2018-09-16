#include "BasicCanvas.h"
#include "BasicCanvasBitmapIterator.h"
using namespace std;
namespace Framework
{
	BasicCanvas::BasicCanvas(int height, int width) : myHeight{height}, myWidth{width}, myBoard{DrawingBoard(height)}
	{
		for (size_t i = 0; i < myBoard.size(); i++)
		{
			myBoard[i] = DrawingBoardLine(myWidth);
		}
	}
	void BasicCanvas::setPixelColor(Point const & location, Color const & color)
	{
		myBoard[location.getY()][location.getX()] = color;
	}
	Color BasicCanvas::getPixelColor(Point const & location) const
	{
		return myBoard[location.getY()][location.getX()];
	}
	int BasicCanvas::getWidth() const
	{
		return myWidth;
	}
	int BasicCanvas::getHeight() const
	{
		return myHeight;
	}
	HBitmapIterator BasicCanvas::createBitmapIterator()
	{
		return  make_unique<BasicCanvasBitmapIterator>(*this);
	}
}

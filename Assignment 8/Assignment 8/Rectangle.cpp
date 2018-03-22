#include "Rectangle.h"

Rectangle::Rectangle(const Point& upperLeft, const Point& lowerRight) :
	myUpperLeft(new Point(upperLeft)),
	myLowerRight(new Point(lowerRight))
{

}

const Point & Rectangle::getUpperLeft() const { return *myUpperLeft; }

const Point & Rectangle::getLowerRight() const { return *myLowerRight; }

void Rectangle::draw(std::ostream & os) const
{
	this->stream(os);
}

void Rectangle::stream(std::ostream & os) const
{
	os << "draw rectangle: ";
	os << myUpperLeft->myX << "," << myUpperLeft->myY << ",";
	os << myLowerRight->myX << "," << myLowerRight->myY;
}

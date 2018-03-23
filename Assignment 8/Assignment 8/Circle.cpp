#include "Circle.h"


Circle::Circle(const Point& origin, double radius) :
	myOrigin(new Point(origin)),
	myRadius(new double(radius))
{

}

// getters
const Point& Circle::getOrigin() const { return *myOrigin; }

const double& Circle::getRadius() const { return *myRadius; }

// overloaded functions....
void Circle::draw(std::ostream& os) const
{
	this->stream(os);
}


void Circle::stream(std::ostream& os) const
{
	os << "draw circle: ";
	os << myOrigin->myX << "," << myOrigin->myY << ",";
	os << *myRadius;
}

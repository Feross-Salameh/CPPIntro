#include "Triangle.h"


Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3) :
	myV1(new Point(v1)),
	myV2(new Point(v2)),
	myV3(new Point(v3))

{
}

// returning const Points to 
const Point& Triangle::getV1() const { return *myV1; }
const Point& Triangle::getV2() const { return *myV2; }
const Point& Triangle::getV3() const { return *myV3; }


// overloaded functions....
void Triangle::draw(std::ostream& os) const
{
	this->stream(os);
}


void Triangle::stream(std::ostream& os) const
{
	os << "draw triangle: ";
	os << myV1->myX << "," << myV1->myY << ",";
	os << myV2->myX << "," << myV2->myY << ",";
	os << myV3->myX << "," << myV3->myY;
}
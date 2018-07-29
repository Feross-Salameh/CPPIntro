#include "Point.h"
using namespace VG;

//constexpr Point::Point(int x, int y) : MyX{ x }, MyY{ y }
//{
//}
//
//constexpr int Point::getX() const
//{
//	return MyX;
//}
//
//constexpr int Point::getY() const
//{
//	return MyY;
//}
//
bool VG::Point::operator==(const Point & rhs)
{
	return (x == rhs.x)&&(y == rhs.y);
}

bool VG::Point::operator!=(const Point & rhs)
{
	return !(*this == rhs);
}

std::ostream & VG::operator<<(std::ostream & os, Point p)
{
	return os << " {" << p.x << "," << p.y << "}";
}

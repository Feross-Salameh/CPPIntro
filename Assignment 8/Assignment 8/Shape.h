#pragma once

#include <ostream>
#include <memory>
#include <cmath>
class Shape
{
public:
	Shape() = default;

	Shape(const Shape& src) = delete;
	Shape& operator=(const Shape& rhs) = delete;

	virtual ~Shape() = default;

	virtual void draw(std::ostream& os) const = 0;

	virtual void stream(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
	shape.stream(os);
	return os;
}

// class to help contain the point object. 
// This also could be a struct.
class Point
{
public:
	Point(double x, double y) :
		myX(x),
		myY(y)
	{

	}
	double myX;
	double myY;

};

//std::ostream& operator<<(std::ostream& os, const Point& a)
//{
//	os << a.myX << "," << a.myY;
//	return os;
//}

#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
public:
	Rectangle(const Point& upperLeft, const Point& lowerRight);

	const Point& getUpperLeft() const;
	const Point& getLowerRight() const;

	void draw(std::ostream& os) const;

	void stream(std::ostream& os) const;
private:
	std::unique_ptr<Point> myUpperLeft;
	std::unique_ptr<Point> myLowerRight;

};


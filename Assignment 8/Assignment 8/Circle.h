#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:

	Circle(const Point& origin, double radius);

	const Point& getOrigin() const;
	const double& getRadius() const;

	void draw(std::ostream& os) const;


	void stream(std::ostream& os) const;


private:
	std::unique_ptr<Point> myOrigin;
	std::unique_ptr<double> myRadius;
};


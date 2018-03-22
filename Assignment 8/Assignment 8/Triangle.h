#pragma once
#include "Shape.h"

class Triangle :
	public Shape
{
public:

	Triangle(const Point& v1, const Point& v2, const Point& v3);

	const Point& getV1() const;
	const Point& getV2() const;
	const Point& getV3() const;

	void draw(std::ostream& os) const;


	void stream(std::ostream& os) const;

private:
	// making pointers unique. Conceptually this makes sense because 
	// each shape has it's own points and doesn't share them.

 	std::unique_ptr<Point> myV1;
	std::unique_ptr<Point> myV2;
	std::unique_ptr<Point> myV3;
};



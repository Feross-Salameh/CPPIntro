#include "TestHarness.h"

#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

TEST(draw, Triangle)
{
	Triangle t1(Point(11.1, 22.2), Point(33.3, 44.4), Point(55.5, 66.6));
	std::stringstream ss;
	t1.draw(ss);
	CHECK_EQUAL("draw triangle: 11.1,22.2,33.3,44.4,55.5,66.6", ss.str());

	CHECK_EQUAL(11.1, t1.getV1().myX);
	CHECK_EQUAL(22.2, t1.getV1().myY);
	CHECK_EQUAL(33.3, t1.getV2().myX);
	CHECK_EQUAL(44.4, t1.getV2().myY);
	CHECK_EQUAL(55.5, t1.getV3().myX);
	CHECK_EQUAL(66.6, t1.getV3().myY);
}

TEST(draw, Circle)
{
	Circle c1(Point(111.1, 222.2), 333.3);
	std::stringstream ss;
	c1.draw(ss);
	CHECK_EQUAL("draw circle: 111.1,222.2,333.3", ss.str());

	CHECK_EQUAL(c1.getOrigin().myX, 111.1);
	CHECK_EQUAL(c1.getOrigin().myY, 222.2);
	CHECK_EQUAL(c1.getRadius(), 333.3);
}

TEST(draw, Rectangle)
{
	Rectangle r1(Point(11.1, 22.2), Point(33.3, 44.4));
	std::stringstream ss;
	r1.draw(ss);
	CHECK_EQUAL("draw rectangle: 11.1,22.2,33.3,44.4", ss.str());

	CHECK_EQUAL(11.1, r1.getUpperLeft().myX);
	CHECK_EQUAL(22.2, r1.getUpperLeft().myY);
	CHECK_EQUAL(33.3, r1.getLowerRight().myX);
	CHECK_EQUAL(44.4, r1.getLowerRight().myY);

}
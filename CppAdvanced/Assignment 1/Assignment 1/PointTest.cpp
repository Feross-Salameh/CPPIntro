
#include "Point.h"
#include "..\..\CppUnitLite\TestHarness.h"

using namespace VG;

TEST(Properties, Point)
{
	auto P = Point(1, 2);

	//checking if properties are set correctly
	CHECK_EQUAL(P.getX(), 1);
	CHECK_EQUAL(P.getY(), 2);

}

TEST(copy, Point)
{
	Point p1(1, 2);

	auto p2 = p1;
	CHECK_EQUAL(p2.getX(), 1);
	CHECK_EQUAL(p2.getY(), 2);
}

TEST(move, Point)
{
	Point p1(1, 2);

	auto p2 = std::move(p1);
	CHECK_EQUAL(p2.getX(), 1);
	CHECK_EQUAL(p2.getY(), 2);
}

// test taken from examples. I know there was an announcement on not using the example unit tests. I added them as a reference and figured might as well use them for increased confidence.
// If I shouldn't add them at all. Please let me know.
TEST(equality, Point)
{
    CHECK_EQUAL(Point(1, 2), Point(1, 2));
}

TEST(inequality, Point)
{
    CHECK(Point(1, 2) != Point(3, 4));
}

TEST(constexprPoint, Point)
{
    constexpr int i = Point{4, 5}.getX();
    
    CHECK_EQUAL(i, 4);
}

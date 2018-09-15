//
//  PointTest.cpp
//  Assignment1
//
//  Created by Chris Elderkin on 4/26/15.
//  Copyright (c) 2015 Chris Elderkin. All rights reserved.
//

#include "Point.h"
#include "../../CppUnitLite/TestHarness.h"


TEST(equality, Point)
{
    CHECK_EQUAL(Framework::Point(1, 2), Framework::Point(1, 2));
}

TEST(copyCtor, Point)
{
	Framework::Point p1{ 2, 2 };

	Framework::Point p2{ p1 };

	CHECK_EQUAL(p1, p2);
}

TEST(copyAssign, Point)
{
	Framework::Point p1{ 2, 2 };
	Framework::Point p2 = p1;

	CHECK_EQUAL(p1, p2);
}

TEST(moveCtor, Point)
{
	Framework::Point p1{ 2, 2 };
	Framework::Point p2(std::move(p1));

	CHECK_EQUAL(p2, Framework::Point(2, 2));
}

TEST(moveAssign, Point)
{
	Framework::Point p1{ 2, 2 };
	Framework::Point p2 = std::move(p1);

	CHECK_EQUAL(p2, Framework::Point(2, 2));
}

TEST(inequality, Point)
{
    CHECK(Framework::Point(1, 2) != Framework::Point(3, 4));
}

TEST(constexprPoint, Point)
{
    constexpr int i = Framework::Point{4, 5}.getX();
    
    CHECK_EQUAL(i, 4);
}

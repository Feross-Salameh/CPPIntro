#include "Parse.h"
#include "VectorGraphic.h"
#include "VectorGraphicStreamer.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include <deque>

TEST(ctor, VectorGraphic)
{
    Framework::VectorGraphic Framework;
    CHECK_EQUAL(0, Framework.getPointCount());
    CHECK_EQUAL(true, Framework.isClosed());
    CHECK_EQUAL(false, Framework.isOpen());
}

TEST(copyCtor, VectorGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point(1, 1));
	
	Framework::VectorGraphic Framework2{ Framework };

	CHECK_EQUAL(1, Framework.getPointCount());
	CHECK_EQUAL(true, Framework.isClosed());
	CHECK_EQUAL(false, Framework.isOpen());

	CHECK_EQUAL(1, Framework2.getPointCount());
	CHECK_EQUAL(true, Framework2.isClosed());
	CHECK_EQUAL(false, Framework2.isOpen());
}

TEST(moveCtor, VectorGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point(1, 1));

	Framework::VectorGraphic Framework2{ std::move(Framework) };

	CHECK_EQUAL(0, Framework.getPointCount());

	CHECK_EQUAL(1, Framework2.getPointCount());
	CHECK_EQUAL(true, Framework2.isClosed());
	CHECK_EQUAL(false, Framework2.isOpen());
}

TEST(copyAssign, VectorGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point( 1,1));

	Framework::VectorGraphic Framework2;
	Framework2 = Framework;

	CHECK_EQUAL(1, Framework.getPointCount());
	CHECK_EQUAL(true, Framework.isClosed());
	CHECK_EQUAL(false, Framework.isOpen());

	CHECK_EQUAL(1, Framework2.getPointCount());
	CHECK_EQUAL(true, Framework2.isClosed());
	CHECK_EQUAL(false, Framework2.isOpen());
}

TEST(moveAssign, VectorGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point(1, 1));

	Framework::VectorGraphic Framework2;
	Framework2 = std::move(Framework);

	CHECK_EQUAL(0, Framework.getPointCount());

	CHECK_EQUAL(1, Framework2.getPointCount());
	CHECK_EQUAL(true, Framework2.isClosed());
	CHECK_EQUAL(false, Framework2.isOpen());
}

TEST(addPoint, VectorGraphic)
{
    Framework::VectorGraphic Framework;
	Framework::Point p{ 1,1 };
    Framework.addPoint(p);
    CHECK_EQUAL(1, Framework.getPointCount());
    
    Framework.addPoint(Framework::Point{2, 2});
    CHECK_EQUAL(2, Framework.getPointCount());
}

TEST(removePoint, VectorGraphic)
{
    Framework::VectorGraphic Framework;
    Framework.addPoint(Framework::Point{1, 1});
    Framework.addPoint(Framework::Point{2, 2});
    Framework.removePoint(Framework::Point{1, 1});
    
    CHECK_EQUAL(1, Framework.getPointCount());
    CHECK_EQUAL(Framework::Point(2, 2), Framework.getPoint(0));
}

TEST(removePointNotInFramework, VectorGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point{ 1, 1 });
	Framework.addPoint(Framework::Point{ 2, 2 });
	
	try
	{
		Framework.removePoint(Framework::Point{ 3, 3 });
	}
	catch (std::invalid_argument&)
	{
		CHECK(true);
		return;
	}

	CHECK(false);
}

TEST(erasePoint, VectorGraphic)
{
    Framework::VectorGraphic Framework;
    Framework.addPoint(Framework::Point{1, 1});
    Framework.addPoint(Framework::Point{2, 2});
    Framework.addPoint(Framework::Point{3, 3});
    Framework.erasePoint(1);
    
    CHECK_EQUAL(2, Framework.getPointCount());
    CHECK_EQUAL(Framework::Point(1, 1), Framework.getPoint(0));
    CHECK_EQUAL(Framework::Point(3, 3), Framework.getPoint(1));
}

TEST(erasePointOutOfRange, VectorGraphic)
{
    Framework::VectorGraphic Framework;
    Framework.addPoint(Framework::Point{1, 1});
    Framework.addPoint(Framework::Point{2, 2});
    Framework.addPoint(Framework::Point{3, 3});
    
    try
    {
        Framework.erasePoint(5);
    }
    catch (std::out_of_range&)
    {
        CHECK_EQUAL(3, Framework.getPointCount());
        return;
    }
    CHECK(false); // should have caught exception
}

TEST(equality, VectorGraphic)
{
    Framework::VectorGraphic Framework1;
    Framework1.addPoint(Framework::Point{1, 1});
    Framework1.addPoint(Framework::Point{2, 2});
    Framework1.addPoint(Framework::Point{3, 3});
    
    Framework::VectorGraphic Framework2;
    Framework2.addPoint(Framework::Point{1, 1});
    Framework2.addPoint(Framework::Point{2, 2});
    Framework2.addPoint(Framework::Point{3, 3});
    
    CHECK(Framework1 == Framework2);
}

TEST(inequality, VectorGraphic)
{
    Framework::VectorGraphic Framework1;
    Framework1.addPoint(Framework::Point{1, 1});
    Framework1.addPoint(Framework::Point{1, 2});
    Framework1.addPoint(Framework::Point{1, 3});
    
    Framework::VectorGraphic Framework2;
    Framework2.addPoint(Framework::Point{2, 1});
    Framework2.addPoint(Framework::Point{2, 2});
    Framework2.addPoint(Framework::Point{2, 3});
    
    CHECK(Framework1 != Framework2);
    
    Framework::VectorGraphic Framework3;
    Framework3.addPoint(Framework::Point{1, 1});
    Framework3.addPoint(Framework::Point{1, 2});
    Framework3.addPoint(Framework::Point{1, 3});
    Framework3.openShape();
    
    CHECK(Framework3 != Framework1);
}

TEST(closeShape, VectorGraphic)
{
    Framework::VectorGraphic Framework;
    Framework.closeShape();
    CHECK_EQUAL(true, Framework.isClosed());
    CHECK_EQUAL(false, Framework.isOpen());
}

TEST(openShape, VectorGraphic)
{
    Framework::VectorGraphic Framework;
    Framework.openShape();
    CHECK_EQUAL(false, Framework.isClosed());
    CHECK_EQUAL(true, Framework.isOpen());
}

TEST(widthHeight, VectorGraphic)
{
    Framework::VectorGraphic vectorGraphic;
    vectorGraphic.addPoint(Framework::Point{0, 2});
    vectorGraphic.addPoint(Framework::Point{4, 3});
    vectorGraphic.addPoint(Framework::Point{5, 8});
    vectorGraphic.addPoint(Framework::Point{2, 1});
    CHECK_EQUAL(5, vectorGraphic.getWidth());
    CHECK_EQUAL(7, vectorGraphic.getHeight());
    
    vectorGraphic.erasePoint(2);
    CHECK_EQUAL(4, vectorGraphic.getWidth());
    CHECK_EQUAL(2, vectorGraphic.getHeight());
}
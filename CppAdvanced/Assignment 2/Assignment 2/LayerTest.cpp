#include "Point.h"
#include "VectorGraphic.h"
#include "PlacedGraphic.h"
#include "Layer.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace VG;
using namespace std;


TEST(ctor, Layer)
{
	Layer lyr;
	string str = "";
	CHECK_EQUAL(str, lyr.getAlias());
	CHECK_EQUAL(0, lyr.getPlacedGraphicCount());
	
}

TEST(copy, Layer)
{
	Layer lyr1;
	lyr1.setAlias("Layer 1");
	lyr1.addPlacedGraphic(PlacedGraphic());

	Layer lyr2{ lyr1 };

	CHECK(strcmp(lyr1.getAlias(), lyr2.getAlias()) == 0);
	CHECK_EQUAL(lyr2.getPlacedGraphicCount(), lyr1.getPlacedGraphicCount());

}

TEST(move, Layer)
{
	Layer lyr1;
	lyr1.setAlias("Layer 1");
	lyr1.addPlacedGraphic(PlacedGraphic());

	Layer lyr2{ move(lyr1) };

	CHECK(strcmp("Layer 1", lyr2.getAlias()) == 0);
	CHECK_EQUAL(1, lyr2.getPlacedGraphicCount());
}

TEST(copyAssign, Layer)
{
	Layer lyr1;
	lyr1.setAlias("Layer 1");
	lyr1.addPlacedGraphic(PlacedGraphic());

	Layer lyr2 = lyr1;

	CHECK(strcmp(lyr1.getAlias(), lyr2.getAlias()) == 0);
	CHECK_EQUAL(lyr2.getPlacedGraphicCount(), lyr1.getPlacedGraphicCount());
}

TEST(moveAssign, Layer)
{
	Layer lyr1;
	lyr1.setAlias("Layer 1");
	lyr1.addPlacedGraphic(PlacedGraphic());

	Layer lyr2 = move(lyr1);

	CHECK(strcmp("Layer 1", lyr2.getAlias()) == 0);
	CHECK_EQUAL(1, lyr2.getPlacedGraphicCount());
}

TEST(setAlias, Layer)
{
	Layer lyr1;
	string str = "Layer 1";

	lyr1.setAlias(str);

	CHECK(strcmp(str.c_str(), lyr1.getAlias()) == 0);

	lyr1.setAlias("Layer 2");

	CHECK(strcmp(str.c_str(), lyr1.getAlias()) != 0);

}

TEST(addGraphic, Layer)
{
	Layer lyr1;

	PlacedGraphic pg1(Point(1, 1), VectorGraphic());
	PlacedGraphic pg2(Point(2, 2), VectorGraphic());
	PlacedGraphic pg3(Point(3, 3), VectorGraphic());

	lyr1.addPlacedGraphic(pg1);

	CHECK_EQUAL(1, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(1,1), lyr1.getPlacedGraphic(0).getPlacementPoint());

	lyr1.addPlacedGraphic(pg2);
	lyr1.addPlacedGraphic(pg3);

	CHECK_EQUAL(3, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(1).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(2).getPlacementPoint());
}

TEST(removeGraphic, Layer)
{
	Layer lyr1;
	VectorGraphic vg;
	PlacedGraphic pg1(Point(1, 1), vg);
	PlacedGraphic pg2(Point(2, 2), vg);
	PlacedGraphic pg3(Point(3, 3), vg);
	PlacedGraphic pg4(Point(4, 4), vg);
	lyr1.addPlacedGraphic(pg1);
	lyr1.addPlacedGraphic(pg2);
	lyr1.addPlacedGraphic(pg3);

	CHECK_EQUAL(3, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(1, 1), lyr1.getPlacedGraphic(0).getPlacementPoint());
	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(1).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(2).getPlacementPoint());

	lyr1.removeGraphic(pg4);

	CHECK_EQUAL(3, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(1, 1), lyr1.getPlacedGraphic(0).getPlacementPoint());
	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(1).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(2).getPlacementPoint());

	lyr1.removeGraphic(pg2);

	CHECK_EQUAL(2, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(1, 1), lyr1.getPlacedGraphic(0).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(1).getPlacementPoint());

	lyr1.removeGraphic(pg1);
	lyr1.removeGraphic(pg3);

	CHECK_EQUAL(0, lyr1.getPlacedGraphicCount());
}

TEST(eraseGraphic, Layer)
{
	Layer lyr1;

	PlacedGraphic pg1(Point(1, 1), VectorGraphic());
	PlacedGraphic pg2(Point(2, 2), VectorGraphic());
	PlacedGraphic pg3(Point(3, 3), VectorGraphic());

	CHECK_EQUAL(0, lyr1.getPlacedGraphicCount());

	try
	{
		lyr1.erasePlacedGraphic(0);
		CHECK(0);
	}
	catch (const std::out_of_range&)
	{
		CHECK(1);
	}

	try
	{
		lyr1.erasePlacedGraphic(2);
		CHECK(0);
	}
	catch (const std::out_of_range&)
	{
		CHECK(1);
	}

	lyr1.addPlacedGraphic(pg1);
	lyr1.addPlacedGraphic(pg2);
	lyr1.addPlacedGraphic(pg3);

	CHECK_EQUAL(3, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(1, 1), lyr1.getPlacedGraphic(0).getPlacementPoint());
	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(1).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(2).getPlacementPoint());

	try
	{
		lyr1.erasePlacedGraphic(5);
		CHECK(0);
	}
	catch (const std::out_of_range&)
	{
		CHECK(1);
	}
	
	lyr1.erasePlacedGraphic(0);

	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(0).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(1).getPlacementPoint());

	lyr1.erasePlacedGraphic(1);

	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(0).getPlacementPoint());

	try
	{
		lyr1.erasePlacedGraphic(1);
		CHECK(0);
	}
	catch (const std::out_of_range&)
	{
		CHECK(1);
	}
}

TEST(getPlacedGraphic, Layer)
{
	Layer lyr1;
	VectorGraphic vg;
	PlacedGraphic pg1(Point(1, 1), vg);
	PlacedGraphic pg2(Point(2, 2), vg);
	PlacedGraphic pg3(Point(3, 3), vg);
	PlacedGraphic pg4(Point(4, 4), vg);
	lyr1.addPlacedGraphic(pg1);
	lyr1.addPlacedGraphic(pg2);
	lyr1.addPlacedGraphic(pg3);

	try
	{
		lyr1.getPlacedGraphic(5);
		CHECK(0)
	}
	catch (const std::out_of_range&)
	{
		CHECK(1)
	}

	CHECK_EQUAL(3, lyr1.getPlacedGraphicCount());
	CHECK_EQUAL(Point(1, 1), lyr1.getPlacedGraphic(0).getPlacementPoint());
	CHECK_EQUAL(Point(2, 2), lyr1.getPlacedGraphic(1).getPlacementPoint());
	CHECK_EQUAL(Point(3, 3), lyr1.getPlacedGraphic(2).getPlacementPoint());
}
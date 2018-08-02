#include "../../CppUnitLite/TestHarness.h"
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "Point.h"
#include <memory>
#include <iostream>
#include <string>
using namespace std;
using namespace VG;
TEST(defaultCTOR, PlacedGraphic)
{
	PlacedGraphic pg(Point(1, 1), VectorGraphic());

	CHECK_EQUAL(pg.getPlacementPoint(), Point(1, 1));

	CHECK_EQUAL(*pg.getGraphic(), VectorGraphic());
}

TEST(CopyCTOR, PlacedGraphic)
{
	PlacedGraphic pg1(Point(1, 1), VectorGraphic());
	auto pg2(pg1);
	CHECK_EQUAL(pg2.getPlacementPoint(), Point(1, 1));

	CHECK_EQUAL(*pg2.getGraphic(), VectorGraphic());
}
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

TEST(move, PlacedGraphic)
{
	PlacedGraphic pg1(PlacedGraphic(Point(1, 1), VectorGraphic()));
	PlacedGraphic& pg2 = pg1;
	auto pg3(std::move(pg2));
	CHECK_EQUAL(pg3.getPlacementPoint(), Point(1, 1));

	CHECK_EQUAL(*pg3.getGraphic(), VectorGraphic());

}

TEST(setPont, PlacedGraphic)
{
	PlacedGraphic pg1(Point(1, 1), VectorGraphic());
	pg1.setPlacementPoint(Point(2, 2));
	CHECK_EQUAL(pg1.getPlacementPoint(), Point(2, 2));

}

TEST(setGraphic, PlacedGraphic)
{
	PlacedGraphic pg1(Point(1, 1), VectorGraphic());
	VectorGraphic vg1;
	vg1.addPoint(Point(2, 2));
	vg1.addPoint(Point(3, 3));
	vg1.addPoint(Point(4, 4));
	vg1.addPoint(Point(5, 5));
	
	pg1.setGraphic(vg1);
	VectorGraphic vg2;
	vg2.addPoint(Point(2, 2));
	vg2.addPoint(Point(3, 3));
	vg2.addPoint(Point(4, 4));
	vg2.addPoint(Point(5, 5));

	CHECK_EQUAL(vg2, *pg1.getGraphic());
	VectorGraphic vg3;
	vg2.addPoint(Point(2, 3));
	vg2.addPoint(Point(3, 4));
	vg2.addPoint(Point(4, 5));
	vg2.addPoint(Point(5, 6));
	auto pvg = make_unique<VectorGraphic>(vg3);
	pg1.setGraphic(pvg);
	CHECK_EQUAL(vg3, *pg1.getGraphic());
}

TEST(Comparison, PlacedGraphic)
{
	VectorGraphic vg1;
	vg1.addPoint(Point(2, 2));
	vg1.addPoint(Point(3, 3));
	vg1.addPoint(Point(4, 4));
	vg1.addPoint(Point(5, 5));

	PlacedGraphic pg1(Point(1, 1),vg1);
	PlacedGraphic pg2(Point(1, 1),vg1);


	CHECK(pg1 == pg2);

	pg2.getGraphic()->addPoint(Point(8, 8));

	CHECK(pg1 != pg2);

}
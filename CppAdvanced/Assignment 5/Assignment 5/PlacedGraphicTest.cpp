#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "../../CppUnitLite/TestHarness.h"

TEST(ctor, PlacedGraphic)
{
    Framework::VectorGraphic Framework;
	Framework::PlacedGraphic pg({ 44, 55 }, Framework);

	Framework::Point expected{ 44, 55 };
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    CHECK(Framework == pg.getGraphic());
}

TEST(copyCtor, PlacedGrapic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point{ 1, 1 });

	Framework::PlacedGraphic pg({ 2,2 }, Framework);

	Framework::PlacedGraphic pg2{ pg };

	CHECK(pg2 == pg);
	CHECK(pg.getGraphic().getPointCount() == 1);
}

TEST(moveCtor, PlacedGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point{ 1, 1 });

	Framework::PlacedGraphic pg({ 2,2 }, Framework);

	Framework::PlacedGraphic pg2{ std::move(pg) };

	Framework::Point expected{ 2,2 };

	CHECK(expected == pg2.getPlacementPoint());
	CHECK(pg2.getGraphic().getPointCount() == 1);
	CHECK(pg.getGraphic().getPointCount() == 0);
}

TEST(copyAssign, PlacedGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point{ 1, 1 });

	Framework::PlacedGraphic pg({ 2,2 }, Framework);

	Framework::PlacedGraphic pg2;
	pg2 = pg;

	CHECK(pg2 == pg);
	CHECK(pg.getGraphic().getPointCount() == 1);
}

TEST(moveAssign, PlacedGraphic)
{
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point{ 1, 1 });

	Framework::PlacedGraphic pg;
	pg = Framework::PlacedGraphic({ 2,2 }, Framework);
	
	Framework::Point expected{ 2,2 };

	CHECK(expected == pg.getPlacementPoint());
	CHECK(pg.getGraphic().getPointCount() == 1);
}

TEST(setPlacementPointRValue, PlacedGraphic)
{
    Framework::PlacedGraphic graphic;
    graphic.setPlacementPoint(Framework::Point(44, 55));

    Framework::Point expected(44, 55);
    CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(setPlacementPointLValue, PlacedGraphic)
{
	Framework::PlacedGraphic graphic;
	Framework::Point p{ 44, 55 };
	graphic.setPlacementPoint(p);

	Framework::Point expected{ 44, 55 };
	CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(setGraphicLValue_getGraphic, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    Framework::VectorGraphic Framework;
    pg.setGraphic(Framework);

    CHECK(Framework == pg.getGraphic());
}

TEST(setGraphicRValue_getGraphic, PlacedGraphic)
{
	Framework::PlacedGraphic pg;
	Framework::VectorGraphic Framework;
	Framework.addPoint(Framework::Point{ 1,2 });

	Framework::VectorGraphic Framework2{ Framework };

	pg.setGraphic(std::move(Framework));

	CHECK(Framework2 == pg.getGraphic());
	CHECK(Framework.getPointCount() == 0);
}
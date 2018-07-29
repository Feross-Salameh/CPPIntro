#include "../../CppUnitLite/TestHarness.h"
#include "VectorGraphic.h"
#include "Point.h"

using namespace VG;

TEST(IsOpenProperty, VectorGraphic)
{
	VectorGraphic vg1;
	vg1.closeShape();
	CHECK_EQUAL(false, vg1.isOpen());
	CHECK_EQUAL(true, vg1.isClosed());
	vg1.openShape();
	CHECK_EQUAL(true, vg1.isOpen());
	CHECK_EQUAL(false, vg1.isClosed());
}

TEST(Insert, VectorGraphic)
{
	VectorGraphic vg1;
	vg1.addPoint(Point(1, 2));
	CHECK_EQUAL(vg1.getPoint(0), Point(1, 2));
}

TEST(ModifyPoints, VectorGraphic)
{
	VectorGraphic vg1;
	vg1.addPoint(Point(1, 2));
	CHECK_EQUAL(Point(1, 2), vg1.getPoint(0));

	vg1.addPoint(Point(4, 4));
	CHECK_EQUAL(Point(1, 2), vg1.getPoint(0));
	CHECK_EQUAL(Point(4, 4), vg1.getPoint(1));

	vg1.erasePoint(0);
	CHECK_EQUAL(Point(4, 4), vg1.getPoint(0));

	vg1.addPoint(Point(10, 10));
	CHECK_EQUAL(Point(4, 4), vg1.getPoint(0));
	CHECK_EQUAL(Point(10, 10), vg1.getPoint(1));

}

TEST(PointCount, VectorGraphic)
{
	VectorGraphic vg1; 
	CHECK_EQUAL(0, vg1.getPointCount());

	vg1.addPoint(Point(1, 2));
	CHECK_EQUAL(1, vg1.getPointCount());

	vg1.erasePoint(0);
	CHECK_EQUAL(0, vg1.getPointCount());

	try
	{
		vg1.erasePoint(0);
	}
	catch (const std::exception&)
	{
		//Exception should be thrown here...
	}
	CHECK_EQUAL(0, vg1.getPointCount());
}

TEST(Height, VectorGraphic)
{
	VectorGraphic vg1;
	vg1.addPoint(Point(0, 0));
	vg1.addPoint(Point(0, 10));
	CHECK_EQUAL(10, vg1.getHeight());
	vg1.addPoint(Point(0, 20));
	CHECK_EQUAL(20, vg1.getHeight());
}

TEST(Width, VectorGraphic)
{
	VectorGraphic vg1;
	vg1.addPoint(Point(0, 0));
	vg1.addPoint(Point(10, 0));
	CHECK_EQUAL(10, vg1.getWidth());
	vg1.addPoint(Point(20, 0));
	CHECK_EQUAL(20, vg1.getWidth());
}


// test taken from examples. I know there was an announcement on not using the example unit tests. I added them as a reference and figured might as well use them for increased confidence.
// If I shouldn't add them at all. Please let me know.
TEST(ctor, VectorGraphic)
{
	VG::VectorGraphic vg;
	CHECK_EQUAL(0, vg.getPointCount());
	CHECK_EQUAL(true, vg.isClosed());
	CHECK_EQUAL(false, vg.isOpen());
}

TEST(insertPoint, VectorGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 1, 1 });
	CHECK_EQUAL(1, vg.getPointCount());

	vg.addPoint(VG::Point{ 2, 2 });
	CHECK_EQUAL(2, vg.getPointCount());
}

TEST(removePoint, VectorGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 1, 1 });
	vg.addPoint(VG::Point{ 2, 2 });
	vg.removePoint(VG::Point{ 1, 1 });

	CHECK_EQUAL(1, vg.getPointCount());
	CHECK_EQUAL(VG::Point(2, 2), vg.getPoint(0));
}

TEST(erasePoint, VectorGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 1, 1 });
	vg.addPoint(VG::Point{ 2, 2 });
	vg.addPoint(VG::Point{ 3, 3 });
	vg.erasePoint(1);

	CHECK_EQUAL(2, vg.getPointCount());
	CHECK_EQUAL(VG::Point(1, 1), vg.getPoint(0));
	CHECK_EQUAL(VG::Point(3, 3), vg.getPoint(1));
}

TEST(erasePointOutOfRange, VectorGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 1, 1 });
	vg.addPoint(VG::Point{ 2, 2 });
	vg.addPoint(VG::Point{ 3, 3 });

	try
	{
		vg.erasePoint(5);
	}
	catch (std::out_of_range&)
	{
		CHECK_EQUAL(3, vg.getPointCount());
		return;
	}
	CHECK(false); // should have caught exception
}

TEST(equality, VectorGraphic)
{
	VG::VectorGraphic vg1;
	vg1.addPoint(VG::Point{ 1, 1 });
	vg1.addPoint(VG::Point{ 2, 2 });
	vg1.addPoint(VG::Point{ 3, 3 });

	VG::VectorGraphic vg2;
	vg2.addPoint(VG::Point{ 1, 1 });
	vg2.addPoint(VG::Point{ 2, 2 });
	vg2.addPoint(VG::Point{ 3, 3 });

	CHECK(vg1 == vg2);
}

TEST(inequality, VectorGraphic)
{
	VG::VectorGraphic vg1;
	vg1.addPoint(VG::Point{ 1, 1 });
	vg1.addPoint(VG::Point{ 1, 2 });
	vg1.addPoint(VG::Point{ 1, 3 });

	VG::VectorGraphic vg2;
	vg2.addPoint(VG::Point{ 2, 1 });
	vg2.addPoint(VG::Point{ 2, 2 });
	vg2.addPoint(VG::Point{ 2, 3 });

	CHECK(vg1 != vg2);

	VG::VectorGraphic vg3;
	vg3.addPoint(VG::Point{ 1, 1 });
	vg3.addPoint(VG::Point{ 1, 2 });
	vg3.addPoint(VG::Point{ 1, 3 });
	vg3.openShape();

	CHECK(vg3 != vg1);
}

TEST(closeShape, VectorGraphic)
{
	VG::VectorGraphic vg;
	vg.closeShape();
	CHECK_EQUAL(true, vg.isClosed());
	CHECK_EQUAL(false, vg.isOpen());
}

TEST(openShape, VectorGraphic)
{
	VG::VectorGraphic vg;
	vg.openShape();
	CHECK_EQUAL(false, vg.isClosed());
	CHECK_EQUAL(true, vg.isOpen());
}

TEST(widthHeight, VectorGraphic)
{
	VG::VectorGraphic vectorGraphic;
	vectorGraphic.addPoint(VG::Point{ 0, 2 });
	vectorGraphic.addPoint(VG::Point{ 4, 3 });
	vectorGraphic.addPoint(VG::Point{ 5, 8 });
	vectorGraphic.addPoint(VG::Point{ 2, 1 });
	CHECK_EQUAL(5, vectorGraphic.getWidth());
	CHECK_EQUAL(7, vectorGraphic.getHeight());

	vectorGraphic.erasePoint(2);
	CHECK_EQUAL(4, vectorGraphic.getWidth());
	CHECK_EQUAL(2, vectorGraphic.getHeight());
}

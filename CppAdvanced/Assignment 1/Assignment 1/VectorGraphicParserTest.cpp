#include "../../CppUnitLite/TestHarness.h"
#include "VectorGraphicParser.h"
#include "VectorGraphic.h"
#include "Point.h"
#include "FS_GenLib.h"

const std::string VectorGraphicXml = R"(
<VectorGraphic closed="true">
<Point x="0" y="0"/>
<Point x="10" y="0">
</Point>
<Point x="10" y="10"/>
<Point x="0" y="10"/>
</VectorGraphic>
)";

TEST(vg, VectorGraphicParser)
{
	VG::VectorGraphicParser vgp;

	auto vg = vgp.XMLtoVG(VectorGraphicXml);
	CHECK_EQUAL(true, vg.isClosed());
	CHECK_EQUAL(VG::Point(0, 0), vg.getPoint(0));
	CHECK_EQUAL(VG::Point(10, 0), vg.getPoint(1));
	CHECK_EQUAL(VG::Point(10, 10), vg.getPoint(2));
	CHECK_EQUAL(VG::Point(0, 10), vg.getPoint(3));
}

TEST(xml, VectorGraphicParser)
{
	VG::VectorGraphic vg;
	VG::VectorGraphicParser vgp;
	vg.closeShape();
	vg.addPoint(VG::Point(0, 1));
	vg.addPoint(VG::Point(2, 3));
	vg.addPoint(VG::Point(4, 5));
	vg.addPoint(VG::Point(6, 7));
	//std::cout << VG::VectorGraphicParser().VGtoXML(vg) << std::endl; // seems easier to test by just looking at it.

	VG::VectorGraphic vg2(vgp.XMLtoVG(vgp.VGtoXML(vg)));
	CHECK_EQUAL(true, vg.isClosed());
	CHECK_EQUAL(VG::Point(0, 1), vg2.getPoint(0));
	CHECK_EQUAL(VG::Point(2, 3), vg2.getPoint(1));
	CHECK_EQUAL(VG::Point(4, 5), vg2.getPoint(2));
	CHECK_EQUAL(VG::Point(6, 7), vg2.getPoint(3));
}

// for this test. I needed to check my output file to make sure it was created successfully. 
TEST(parsing, VectorGraphicParser)
{
	VG::VectorGraphicParser vgp;
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	std::string str(buf);
	vgp.Parse("VectorGraphic.xml", "output.xml");
}

TEST(trim, FS_genlib)
{
	FS_GenLib lib;
	std::string toTrim = "xxxhello444";
	lib.trim(toTrim, " x4");
	CHECK_EQUAL("hello", toTrim);

	lib.trim(toTrim, "cdgf");
	CHECK_EQUAL("hello", toTrim);

	lib.trim(toTrim, "hello");
	CHECK_EQUAL("", toTrim);
}
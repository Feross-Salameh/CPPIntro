#include "../../CppUnitLite/TestHarness.h"
#include "../../../../tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include "PlacedGraphic.h"
#include "PlacedGraphicXMLReader.h"

TEST(HappyPath, PlacedGraphicReader)
{
	std::string xml = R"(<PlacedGraphic x="0" y="0">
							<VectorGraphic closed="true">
								<Point x="0" y="10" />
								<!-- etc... -->
							</VectorGraphic>
						</PlacedGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::PlacedGraphicXMLReader myReader;

	try
	{
		auto pg = myReader.getPlacedGraphic(element);
		CHECK_EQUAL(pg.getPlacementPoint(), VG::Point(0, 0));
		CHECK_EQUAL(pg.getGraphic()->isClosed(), true);
		CHECK_EQUAL(pg.getGraphic()->getPointCount(), 1);
		CHECK_EQUAL(pg.getGraphic()->getPoint(0), VG::Point(0, 10));
	}
	catch (const std::invalid_argument&)
	{
		CHECK(0);
	}
	
}

TEST(badName, PlacedGraphicReader)
{
	std::string xml = R"(<scene x="0" y="0">
							<VectorGraphic closed="true">
								<Point x="0" y="10" />
								<!-- etc... -->
							</VectorGraphic>
						</scene>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::PlacedGraphicXMLReader myReader;

	try
	{
		auto pg = myReader.getPlacedGraphic(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1);
	}

}

TEST(badAttributeX, PlacedGraphicReader)
{
	std::string xml = R"(<PlacedGraphic b="0" y="0">
							<VectorGraphic closed="true">
								<Point x="0" y="10" />
								<!-- etc... -->
							</VectorGraphic>
						</PlacedGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::PlacedGraphicXMLReader myReader;

	try
	{
		auto pg = myReader.getPlacedGraphic(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1);
	}

}

TEST(badAttributeY, PlacedGraphicReader)
{
	std::string xml = R"(<PlacedGraphic x="0" z="0">
							<VectorGraphic closed="true">
								<Point x="0" y="10" />
								<!-- etc... -->
							</VectorGraphic>
						</PlacedGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::PlacedGraphicXMLReader myReader;

	try
	{
		auto pg = myReader.getPlacedGraphic(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1);
	}

}

TEST(noVectorgraphic, PlacedGraphicReader)
{
	std::string xml = R"(<PlacedGraphic x="0" y="0">
							
						</PlacedGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::PlacedGraphicXMLReader myReader;

	try
	{
		auto pg = myReader.getPlacedGraphic(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1);
	}

}

TEST(comment, PlacedGraphicReader)
{
	std::string xml = R"(<PlacedGraphic x="0" y="0">
							<!-- etc... -->
							<VectorGraphic closed="true">
								<Point x="0" y="10" />
							</VectorGraphic>
						</PlacedGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::PlacedGraphicXMLReader myReader;

	try
	{
		auto pg = myReader.getPlacedGraphic(element);
		CHECK(1);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(0);
	}

}
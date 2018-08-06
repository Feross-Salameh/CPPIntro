#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include"Point.h"
#include "PointXMLReader.h"
#include "../../../../tinyxml2/tinyxml2.h"


TEST(happyPath, PointXMLReader)
{
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(R"(<Point x="0" y="10" />)");
	auto element = doc.RootElement();
	XML::PointXMLReader pointReader;
	try
	{
		auto p = pointReader.getPoint(element);
		CHECK(1);
		CHECK_EQUAL(p.getX(), 0);
		CHECK_EQUAL(p.getY(), 10);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(0)
	}
}
TEST(notPoint, PointXMLReader)
{
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(R"(<scene x="0" y="10" />)");
	auto element = doc.RootElement();
	XML::PointXMLReader pointReader;
	try
	{
		auto p = pointReader.getPoint(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1)
	}
}

TEST(notX, PointXMLReader)
{
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(R"(<scene z="0" y="10" />)");
	auto element = doc.RootElement();
	XML::PointXMLReader pointReader;
	try
	{
		auto p = pointReader.getPoint(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1)
	}
}

TEST(notY, PointXMLReader)
{
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(R"(<scene x="0" b="10" />)");
	auto element = doc.RootElement();
	XML::PointXMLReader pointReader;
	try
	{
		auto p = pointReader.getPoint(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1)
	}
}
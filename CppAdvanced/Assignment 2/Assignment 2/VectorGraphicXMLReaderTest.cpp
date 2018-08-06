#include "../../CppUnitLite/TestHarness.h"
#include "../../../../tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include "VectorGraphic.h"
#include "VectorGraphicXMLReader.h"

TEST(happyPath, VectorGraphic)
{
	std::string xml = R"(<VectorGraphic closed="true">
							<Point x="0" y="0"/>
							<Point x="10" y="0"/>
							<Point x="10" y="10"/>
							<Point x="0" y="10"/>
							</VectorGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();
	XML::VectorGraphicXMLReader vgReader;
	auto vg = vgReader.getVectorGraphic(element);

	CHECK(vg.isClosed());
	CHECK_EQUAL(vg.getPointCount(), 4);
}

TEST(noPoints, VectorGraphic)
{
	std::string xml = R"(<VectorGraphic closed="true">
							</VectorGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();
	XML::VectorGraphicXMLReader vgReader;
	auto vg = vgReader.getVectorGraphic(element);

	CHECK(vg.isClosed());
	CHECK_EQUAL(vg.getPointCount(), 0);
}

TEST(withComment, VectorGraphic)
{
	std::string xml = R"(<VectorGraphic closed="true">
							<Point x="0" y="0"/>
							<Point x="10" y="0"/>
							<Point x="10" y="10"/>
							<Point x="0" y="10"/>
							<!-- etc... -->
							</VectorGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();
	XML::VectorGraphicXMLReader vgReader;
	auto vg = vgReader.getVectorGraphic(element);

	CHECK(vg.isClosed());
	CHECK_EQUAL(vg.getPointCount(), 4);
}
TEST(badName, VectorGraphic)
{
	std::string xml = R"(<Scene closed="true">
							<Point x="0" y="0"/>
							<Point x="10" y="0"/>
							<Point x="10" y="10"/>
							<Point x="0" y="10"/>
							</Scene>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();
	XML::VectorGraphicXMLReader vgReader;
	try
	{
		auto vg = vgReader.getVectorGraphic(element);
		CHECK(0);
	}
	catch (const std::invalid_argument&)
	{
		CHECK(1)
	}
	
}

TEST(badPropertyName, VectorGraphic)
{
	std::string xml = R"(<VectorGraphic opens="true">
							<Point x="0" y="0"/>
							<Point x="10" y="0"/>
							<Point x="10" y="10"/>
							<Point x="0" y="10"/>
							</VectorGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();
	XML::VectorGraphicXMLReader vgReader;
	//try
	//{
	//	auto vg = vgReader.getVectorGraphic(element);
	//	CHECK(0);
	//}
	//catch (const std::invalid_argument&)
	//{
	//	CHECK(1);
	//}

}

TEST(badPropertyValue, VectorGraphic)
{
	std::string xml = R"(<VectorGraphic closed="opened">
							<Point x="0" y="0"/>
							<Point x="10" y="0"/>
							<Point x="10" y="10"/>
							<Point x="0" y="10"/>
							</VectorGraphic>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();
	XML::VectorGraphicXMLReader vgReader;
	//try
	//{
	//	auto vg = vgReader.getVectorGraphic(element);
	//	CHECK(0);
	//}
	//catch (const std::invalid_argument&)
	//{
	//	CHECK(1);
	//}
}
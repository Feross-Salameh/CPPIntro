#include "../../CppUnitLite/TestHarness.h"
#include "../../../../tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include "Layer.h"
#include "LayerXMLReader.h"

TEST(happyPath, LayerXMLReader)
{
	std::string xml = R"(<Layer alias="sky">
							<PlacedGraphic x="0" y="0">
								<VectorGraphic closed="true">
									<Point x="0" y="10" />
									<!-- etc... -->
								</VectorGraphic>
							</PlacedGraphic>
							<PlacedGraphic x="700" y="0">
								<VectorGraphic closed="true">
									<!-- etc... -->
								</VectorGraphic>
							</PlacedGraphic>
						</Layer>)";
	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::LayerXMLReader reader;
	try
	{
		auto layer = reader.getLayer(element);
		CHECK(std::strcmp(layer.getAlias(), "sky") == 0);
		CHECK_EQUAL(layer.getPlacedGraphicCount(), 2);
	}
	catch (const std::exception&)
	{
		CHECK(0);
	}
	
}
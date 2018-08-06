#include "../../CppUnitLite/TestHarness.h"
#include "../../../../tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include "Scene.h"
#include "SceneXMLReader.h"

TEST(HappyPath, SceneXMLReader)
{
	std::string xml = R"(<Scene width="800" height="600">
							 <Layer alias="sky">
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
							</Layer>
							<Layer alias="mountains">
								<PlacedGraphic x="0" y="0">
									<VectorGraphic closed="false">
										<!-- etc... -->
									</VectorGraphic>
								</PlacedGraphic>
							 </Layer>
							 <Layer alias="houses">
								 <!-- etc... -->
							</Layer>
						</Scene>)";

	tinyxml2::XMLDocument doc;
	auto sucess = doc.Parse(xml.c_str());
	auto element = doc.RootElement();

	XML::SceneXMLReader sceneReader;

	try
	{
		auto scene = sceneReader.getScene(element);
		CHECK_EQUAL(3, scene.getLayercCount());
		CHECK(std::strcmp(scene.getLayer(1).getAlias(), "mountains") == 0);

		tinyxml2::XMLDocument doc2;
		sceneReader.setScene(&doc2, scene);
		doc2.SaveFile("Scene.xml");
	}
	catch (const std::exception&)
	{
		CHECK(0);
	}




}
#include "SceneXMLReader.h"

VG::Scene XML::SceneXMLReader::getScene(const tinyxml2::XMLElement* scElement)
{
	if (std::strcmp(scElement->Name(), "Scene") != 0)
		throw std::invalid_argument("XML element is not a Scene");

	int width, height;
	auto attribute = scElement->FirstAttribute();
	int count = 0;
	while (attribute != nullptr)
	{
		++count;
		attribute = attribute->Next();
	}

	if (count != 2)
		throw std::invalid_argument("PlacedGraphic XML atrributes are incorrect");
	auto xSuccess = scElement->QueryIntAttribute("width", &width);
	if (xSuccess)
		throw std::invalid_argument("unable to access width in Scene");
	auto ySuccess = scElement->QueryIntAttribute("height", &height);
	if (ySuccess)
		throw std::invalid_argument("unable to access height in Scene");

	VG::Scene sc;
	sc.setHeight(height);
	sc.setWidth(width);
	auto pg = scElement->FirstChildElement();
	while (pg != nullptr)
	{
		sc.addLayer(myReader.getLayer(pg));
		pg = pg->NextSiblingElement();
	}


	return sc;
}

void XML::SceneXMLReader::setScene(tinyxml2::XMLDocument * doc, const VG::Scene & scene)
{
	auto scnElement = doc->NewElement("Scene");
	scnElement->SetAttribute("width", scene.getWidth());
	scnElement->SetAttribute("height", scene.getHeight());

	for (size_t i = 0; i < scene.getLayercCount(); i++)
	{
		myReader.setLayer(scnElement, scene.getLayer(i));
	}
	doc->InsertFirstChild(scnElement);
}

#include "LayerXMLReader.h"

using namespace tinyxml2;
VG::Layer XML::LayerXMLReader::getLayer(const tinyxml2::XMLElement* lyrElement)
{
	if (std::strcmp(lyrElement->Name(), "Layer") != 0)
		throw std::invalid_argument("XML element is not a Layer");

	VG::Layer lyr;
	const char* name;
	auto aliasSuccess = lyrElement->QueryStringAttribute("alias", &name);
	if (aliasSuccess)
		throw std::invalid_argument("Layer object does not have an alias attribute");
	lyr.setAlias(name);
	auto pg = lyrElement->FirstChildElement();
	while (pg != nullptr)
	{
		lyr.addPlacedGraphic(myReader.getPlacedGraphic(pg));
		pg = pg->NextSiblingElement();
	}
	return lyr;
}

void XML::LayerXMLReader::setLayer(tinyxml2::XMLElement * scnElement, const VG::Layer & lyr)
{
	if (strcmp("Scene", scnElement->Name()) != 0)
		throw new std::invalid_argument("attemping to insert layer into non scene object");
	auto doc = const_cast<XMLDocument*>(scnElement->GetDocument());
	auto lyrElement = doc->NewElement("Layer");

	lyrElement->SetAttribute("alias", lyr.getAlias());
	for (size_t i = 0; i < lyr.getPlacedGraphicCount(); i++)
	{
		myReader.setPlacedGraphic(lyrElement, lyr.getPlacedGraphic(i));
	}
	scnElement->InsertEndChild(lyrElement);
}

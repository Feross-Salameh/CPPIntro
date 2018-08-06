#include "PlacedGraphicXMLReader.h"

using namespace tinyxml2;
VG::PlacedGraphic XML::PlacedGraphicXMLReader::getPlacedGraphic(const tinyxml2::XMLElement * pgElement)
{
	if (std::strcmp(pgElement->Name(), "PlacedGraphic") != 0)
		throw std::invalid_argument("XML element is not a PlacedGraphic");

	int x, y;
	auto attribute = pgElement->FirstAttribute();
	int count = 0;
	while (attribute != nullptr)
	{
		++count;
		attribute = attribute->Next();
	}

	if (count != 2)
		throw std::invalid_argument("PlacedGraphic XML atrributes are incorrect");
	auto xSuccess = pgElement->QueryIntAttribute("x", &x);
	if (xSuccess)
		throw std::invalid_argument("unable to access X coordinate in PlacedGraphic");
	auto ySuccess = pgElement->QueryIntAttribute("y", &y);
	if (ySuccess)
		throw std::invalid_argument("unable to access Y coordinate in PlacedGraphic");
	VG::Point placementPoint(x, y);

	auto vgNode = pgElement->FirstChildElement();
	if (vgNode == nullptr)
		throw std::invalid_argument("PlacedGraphic XML object missing VectorGraphic XML object");
	auto vg = myVectorGraphicReader.getVectorGraphic(vgNode);

	return  VG::PlacedGraphic(placementPoint, vg);
}

void XML::PlacedGraphicXMLReader::setPlacedGraphic(tinyxml2::XMLElement * lyrElement, const VG::PlacedGraphic& pg)
{
	if (strcmp("Layer", lyrElement->Name()) != 0)
		throw new std::invalid_argument("attemping to insert placed graphic into non layer object");
	auto doc = const_cast<XMLDocument*>(lyrElement->GetDocument());
	auto pgElement = doc->NewElement("PlacedGraphic");
	pgElement->SetAttribute("x", pg.getPlacementPoint().getX());
	pgElement->SetAttribute("y", pg.getPlacementPoint().getY());

	myVectorGraphicReader.setVectorGraphic(pgElement, *pg.getGraphic());

	lyrElement->InsertEndChild(pgElement);
}

#include "VectorGraphicXMLReader.h"

using namespace tinyxml2;
VG::VectorGraphic XML::VectorGraphicXMLReader::getVectorGraphic(const tinyxml2::XMLElement* vgElement)
{
	if (std::strcmp(vgElement->Name(), "VectorGraphic") != 0)
		throw std::invalid_argument("XML element is not a VectorGraphic");
	const char* closed;
	auto closedSuccess = vgElement->QueryStringAttribute("closed", &closed);
	if (closedSuccess)
		throw new std::invalid_argument("unable to find closed attribute in vector graphic");
	VG::VectorGraphic vg;
	if (std::strcmp("true", closed) == 0)
		vg.closeShape();
	else if (std::strcmp("false", closed) == 0)
		vg.openShape();
	else
		throw new std::invalid_argument("attribute 'closed' does not have the correct value");

	auto child = vgElement->FirstChildElement();

	while (child != nullptr)
	{
		vg.addPoint(myPointReader.getPoint(child->ToElement()));
		child = child->NextSiblingElement();
	}


	return std::move(vg);
}

void XML::VectorGraphicXMLReader::setVectorGraphic(tinyxml2::XMLElement * pgElement, const VG::VectorGraphic & vg)
{
	if (strcmp("PlacedGraphic", pgElement->Name()) != 0)
		throw new std::invalid_argument("attemping to insert vector graphic into non Placed Graphic object");
	auto doc = const_cast<XMLDocument*>(pgElement->GetDocument());
	auto vgElement = doc->NewElement("VectorGraphic");
	std::string isClosed = vg.isClosed() ? "true" : "false";
	vgElement->SetAttribute("closed", isClosed.c_str());

	for (size_t i = 0; i < vg.getPointCount(); i++)
	{
		myPointReader.setPoint(vgElement, vg.getPoint(i));
	}

	pgElement->InsertEndChild(vgElement);
}

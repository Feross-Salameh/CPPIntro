#include "PointXMLReader.h"
using namespace tinyxml2;

VG::Point XML::PointXMLReader::getPoint(const tinyxml2::XMLElement * pointElement)
{
	if (std::strcmp(pointElement->Name(), "Point") != 0)
		throw std::invalid_argument("xml element is not a point");
	int x, y;
	auto attribute = pointElement->FirstAttribute();
	int count = 0;
	while (attribute != nullptr)
	{
		++count;
		attribute = attribute->Next();
	}

	if (count != 2)
		throw std::invalid_argument("Point XML atrributes are incorrect");
	auto xSuccess = pointElement->QueryIntAttribute("x", &x);
	if (xSuccess)
		throw std::invalid_argument("unable to access X coordinate in Point");
	auto ySuccess = pointElement->QueryIntAttribute("y", &y);
	if (ySuccess)
		throw std::invalid_argument("unable to access Y coordinate in Point");
	return VG::Point(x,y);
}

void XML::PointXMLReader::setPoint(tinyxml2::XMLElement * vgElement, const VG::Point & p)
{
	auto doc = const_cast<XMLDocument*>(vgElement->GetDocument());
	auto pElement = doc->NewElement("Point");
	pElement->SetAttribute("x", p.getX());
	pElement->SetAttribute("y", p.getY());

	vgElement->InsertEndChild(pElement);

}

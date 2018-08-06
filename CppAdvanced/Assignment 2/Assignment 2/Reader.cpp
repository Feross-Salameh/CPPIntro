#include "Reader.h"

VG::Scene XML::Reader::readXMLFile(const char * xmlFilePath)
{
	tinyxml2::XMLDocument doc;
	auto sucess = doc.LoadFile(xmlFilePath);
	if (sucess)
		throw std::invalid_argument("Unable to load XML file");
	auto element = doc.RootElement();
	SceneXMLReader reader;

	return reader.getScene(element);
}

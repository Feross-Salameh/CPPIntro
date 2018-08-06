#pragma once
#include <vector>
#include <cstdlib>
#include <string>

#include "../../../../tinyxml2/tinyxml2.h"

#include "Point.h"
#include "PointXMLReader.h"

#include "VectorGraphic.h"
#include "VectorGraphicXMLReader.h"

#include "PlacedGraphic.h"
#include "PlacedGraphicXMLReader.h"

#include "Layer.h"
namespace XML
{
	class LayerXMLReader
	{
	public:
		LayerXMLReader() = default;
		VG::Layer getLayer(const tinyxml2::XMLElement* lyrElement);
		void setLayer(tinyxml2::XMLElement* lyrElement, const VG::Layer& lyr);

	private:
		PlacedGraphicXMLReader myReader;
	};
}



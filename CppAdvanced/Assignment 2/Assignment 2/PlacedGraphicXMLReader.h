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

namespace XML
{
	class PlacedGraphicXMLReader
	{
	public:
		PlacedGraphicXMLReader() = default;

		VG::PlacedGraphic getPlacedGraphic(const tinyxml2::XMLElement* pgElement);
		void setPlacedGraphic(tinyxml2::XMLElement* lyrElement, const VG::PlacedGraphic& pg);
	private:
		VectorGraphicXMLReader myVectorGraphicReader;
		PointXMLReader myPointReader;

	};
}



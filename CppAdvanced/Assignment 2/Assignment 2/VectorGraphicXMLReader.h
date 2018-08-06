#pragma once
#include <vector>
#include <cstdlib>
#include <string>

#include "../../../../tinyxml2/tinyxml2.h"

#include "Point.h"
#include "PointXMLReader.h"

#include "VectorGraphic.h"

namespace XML
{
	class VectorGraphicXMLReader
	{
	public:
		VectorGraphicXMLReader() = default;

		VG::VectorGraphic getVectorGraphic(const tinyxml2::XMLElement* vgElement);
		void setVectorGraphic(tinyxml2::XMLElement* pgElement, const VG::VectorGraphic& vg);

	private:
		PointXMLReader myPointReader;
	};
}



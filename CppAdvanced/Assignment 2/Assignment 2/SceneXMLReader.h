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
#include "LayerXMLReader.h"

#include "Scene.h"

namespace XML
{
	class SceneXMLReader
	{
	public:
		SceneXMLReader() = default;

		VG::Scene getScene(const tinyxml2::XMLElement* scElement);
		void setScene(tinyxml2::XMLDocument* doc, const VG::Scene& scene);
	private:
		LayerXMLReader myReader;
	};
}




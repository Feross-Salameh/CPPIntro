#pragma	once
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
#include "SceneXMLReader.h"


namespace XML
{
	class Reader
	{
	public:
		Reader() = default;

		VG::Scene readXMLFile(const char* xmlFilePath);

	
	};
}



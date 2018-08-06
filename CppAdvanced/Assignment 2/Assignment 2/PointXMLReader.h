#pragma once
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include "Point.h"
#include "../../../../tinyxml2/tinyxml2.h"

namespace XML
{
	class PointXMLReader
	{
	public:
		PointXMLReader() = default;

		VG::Point getPoint(const tinyxml2::XMLElement* pointElement);
		void setPoint(tinyxml2::XMLElement* vgElement, const VG::Point& p);
	};
}




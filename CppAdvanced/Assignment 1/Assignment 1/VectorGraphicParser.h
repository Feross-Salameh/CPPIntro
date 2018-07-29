#pragma once
#include <regex>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Point.h"
#include "VectorGraphic.h"
#include "FS_GenLib.h"
namespace VG
{
	class VectorGraphicParser
	{
	public:
		VectorGraphicParser() = default;

		VectorGraphic Parse(const std::string& sourceFilePath, const std::string& destinaltionFilePath);

		// TODO: move this functions to private when done testing.

		VectorGraphic XMLtoVG(const std::string& source);
		std::string VGtoXML(const VectorGraphic& vg);

	private:
		
	};
}



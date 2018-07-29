#include "VectorGraphicParser.h"

using namespace VG;
using namespace std;
VectorGraphic VG::VectorGraphicParser::Parse(const std::string& sourceFilePath, const std::string& destinaltionFilePath)
{
	ifstream ifs(sourceFilePath, std::fstream::in);
	if (!ifs.is_open())
		throw "Error with Source file.";

	string xml = "", line;

	while (getline(ifs, line))
		xml += line + "\n\r";
	ifs.close();

	VectorGraphic vg = XMLtoVG(xml);
	try
	{
		ofstream ofs;
		ofs.open(destinaltionFilePath);
		ofs << VGtoXML(vg);
		ofs.close();
	}
	catch (const std::exception& ex)
	{
		// I don't know what the responce should be, best effort or all or nothing.
		cout << ex.what() << endl;
	}
	return forward<VectorGraphic>(vg);
}
// parses an XML string into a Vector graphic
VectorGraphic VG::VectorGraphicParser::XMLtoVG(const std::string& source)
{
	VectorGraphic vg;
	// getting if VG is open or closed:
	regex reg1("closed=\".*\"");
	smatch m;
	regex_search(source, m, reg1);
	string closed = m[0];
	FS_GenLib().trim(closed, "closed=");
	FS_GenLib().trim(closed, "\"");
	if (closed == "true")
		vg.closeShape();
	else if (closed == "false")
		vg.openShape();
	else
		throw "Error parsing xml file. Cannot find 'closed' attribute";

	regex reg2("<Point x=\"(.*)\" y=\"(.*)\"");
	smatch m2;
	string pointStr = source;
	while (regex_search(pointStr, m2, reg2))
	{
		int x = stoi(m2[1]);
		int y = stoi(m2[2]);
		vg.addPoint(Point(x, y));
		pointStr = m2.suffix().str();
	}

	return std::forward<VectorGraphic>(vg);
}

std::string VG::VectorGraphicParser::VGtoXML(const VectorGraphic & vg)
{
	stringstream ss;
	string closed = vg.isClosed() ? "true" : "false";
	ss << "<VectorGraphic closed=\"" << closed << "\">" << endl;

	for (int i = 0; i < vg.getPointCount(); ++i)
	{
		auto p = vg.getPoint(i);
		ss << "<Point x=\""<< p.getX() <<"\" y=\"" << p.getY() << "\"/>" << endl;
	}

	ss << "</VectorGraphic>" << endl;
	return ss.str();
}

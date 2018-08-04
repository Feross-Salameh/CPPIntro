#include "Layer.h"


VG::Layer::Layer(const std::string & alias, const PlacedGraphicList & graphicList) : myName{ const_cast<std::string&>(alias) }, myPlacedGrapics{const_cast<std::vector<PlacedGraphic>&>(graphicList)}
{
}

void VG::Layer::setAlias(const std::string & alias)
{
	myName = alias;
}

std::string const & VG::Layer::getAlias() const
{
	// TODO: insert return statement here
	return myName;
}

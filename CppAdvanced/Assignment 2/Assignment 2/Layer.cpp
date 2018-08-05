#include "Layer.h"

#include <algorithm>
using namespace VG;

VG::Layer::Layer() : myName{ }, myPlacedGraphics{ }
{
}

VG::Layer::Layer(const char* alias, const PlacedGraphicList & graphicList) : myName{alias}, myPlacedGraphics{graphicList}
{
}

void VG::Layer::setAlias(const char* alias)
{
	myName = alias;
}

void VG::Layer::setAlias(const std::string & alias)
{
	myName = alias;
}

const char*  VG::Layer::getAlias() const
{
	return myName.c_str();
}

void VG::Layer::addPlacedGraphic(const PlacedGraphic & graphic)
{
	myPlacedGraphics.push_back(graphic);
}
/*
	I was wondering what the difference is between emplace and push back, here are some research links
	https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
	https://www.quora.com/In-what-scenarios-should-I-use-emplace_back-instead-of-push_back-in-C++
*/
void VG::Layer::addPlacedGraphic(PlacedGraphic && graphic)
{
	myPlacedGraphics.emplace_back(std::forward<PlacedGraphic>(graphic));
}

void VG::Layer::removeGraphic(const PlacedGraphic & graphic)
{
	auto newEnd = std::remove(myPlacedGraphics.begin(), myPlacedGraphics.end(), graphic);
	// In the VectorGraphic.cpp, an exception is thrown if the graphic doesn't exist. 
	// I left that out here because I don't believe an error should be thrown if the object doesn't exist.
	// all that matters to the user is that specific object isn't in the Layer. 
	if (newEnd != myPlacedGraphics.end())
		myPlacedGraphics.erase(newEnd, myPlacedGraphics.end());
}

void VG::Layer::erasePlacedGraphic(size_t index)
{
	if (index < myPlacedGraphics.size())
	{
		myPlacedGraphics.erase(myPlacedGraphics.begin() + index);
	}
	else
	{
		throw std::out_of_range{ "index out of range" };
	}
}

size_t VG::Layer::getPlacedGraphicCount() const
{
	return myPlacedGraphics.size();
}

const PlacedGraphic & VG::Layer::getPlacedGraphic(int index) const
{
	return myPlacedGraphics.at(index);
}

std::ostream& VG::operator<<(std::ostream& os, const Layer& p)
{
	os << "Layer: " << p.getAlias() << ": ";
	for (size_t i = 0; i < p.getPlacedGraphicCount(); i++)
	{
		os << p.getPlacedGraphic(i);
	}
	return os;
}

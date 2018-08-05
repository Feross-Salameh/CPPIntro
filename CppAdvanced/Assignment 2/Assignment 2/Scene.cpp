#include "Scene.h"

VG::Scene::Scene(unsigned int width, unsigned int height, const LayersList & layers) : myWidth(width), myHeight(height), myLayers{layers}
{
}

void VG::Scene::addLayer(const Layer & lyr)
{
	myLayers.push_back(lyr);
}

void VG::Scene::addLayer(Layer && lyr)
{
	myLayers.emplace_back(lyr);
}

void VG::Scene::removeLayer(const Layer & lyr)
{
	auto newEnd = std::remove(myLayers.begin(), myLayers.end(), lyr);
	// In the VectorGraphic.cpp, an exception is thrown if the graphic doesn't exist. 
	// I left that out here because I don't believe an error should be thrown if the object doesn't exist.
	// all that matters to the user is that specific object isn't in the Layer. 
	if (newEnd != myLayers.end())
		myLayers.erase(newEnd, myLayers.end());
}

void VG::Scene::eraseLayer(size_t index)
{
	if (index < myLayers.size())
	{
		auto iter = myLayers.begin();
		std::advance(iter, index);
		myLayers.erase(iter);
	}
	else
	{
		throw std::out_of_range{ "index out of range" };
	}
}


void VG::Scene::setWidth(unsigned int width)
{
	myWidth = width;
}

void VG::Scene::setHeight(unsigned int height)
{
	myHeight = height;
}

size_t VG::Scene::getLayercCount() const
{
	return myLayers.size();
}

const VG::Layer & VG::Scene::getLayer(int index) const
{
	// TODO: insert return statement here
	if (static_cast<size_t>(index) < myLayers.size())
	{
		auto iter = myLayers.begin();
		std::advance(iter, index);
		return *iter;
	}
	else
	{
		throw std::out_of_range{ "index out of range" };
	}
}

bool VG::Scene::operator==(const Scene & rhs) const
{
	return (myHeight == rhs.myHeight)&&(myWidth == rhs.myWidth)&&(myLayers == rhs.myLayers);
}

bool VG::Scene::operator!=(const Scene & rhs) const
{
	return !(*this == rhs);
}



std::ostream & VG::operator<<(std::ostream & os, const Scene & p)
{
	// TODO: insert return statement here
	os << "Scene: width - " << p.getWidth() << " height - " << p.getHeight() << "; ";

	for (size_t i = 0; i < p.getLayercCount(); i++)
	{
		os << p.getLayer(i);
	}
	return os;
}

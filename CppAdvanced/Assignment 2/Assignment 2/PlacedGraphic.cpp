#include "PlacedGraphic.h"
using namespace VG;

VG::PlacedGraphic::PlacedGraphic() : myPlacementPoint{ Point(1,1) }, myGraphic{new VectorGraphic() }
{
}

PlacedGraphic::PlacedGraphic(const Point & placementPoint, const VectorGraphic & graphic) : myPlacementPoint{ placementPoint }, myGraphic{std::make_unique<VectorGraphic>(graphic)}
{

}

VG::PlacedGraphic::PlacedGraphic(const PlacedGraphic & rhs) : myPlacementPoint{rhs.getPlacementPoint()}, myGraphic{ std::make_unique<VectorGraphic>(new VectorGraphic(*rhs.getGraphic())) }
{
}

VG::PlacedGraphic::PlacedGraphic(PlacedGraphic && rhs) : myPlacementPoint{ rhs.getPlacementPoint() }, myGraphic{ std::make_unique<VectorGraphic>(new VectorGraphic(*rhs.getGraphic())) }
{

}

PlacedGraphic & VG::PlacedGraphic::operator=(const PlacedGraphic & rhs)
{
	if (*this != rhs)
	{
		auto tmp = const_cast<PlacedGraphic&>(rhs);
		*this = std::move(tmp);
	}
	// TODO: insert return statement here
	return *this;
}

PlacedGraphic & VG::PlacedGraphic::operator=(PlacedGraphic && rhs)
{
	if (*this != rhs)
	{
		*this = std::move(rhs);
	}
	// TODO: insert return statement here
	return *this;
}


void VG::PlacedGraphic::setPlacementPoint(Point const & placement)
{
	myPlacementPoint = placement;
}

void VG::PlacedGraphic::setPlacementPoint(Point && placement)
{
	myPlacementPoint = std::forward<Point>(placement);
}

Point const & VG::PlacedGraphic::getPlacementPoint() const
{
	return myPlacementPoint;
}

void VG::PlacedGraphic::setGraphic(HVectorGraphic const & graphic)
{
	myGraphic.reset(new VectorGraphic(*graphic));
}

void VG::PlacedGraphic::setGraphic(HVectorGraphic && graphic)
{
	graphic = std::move(graphic);
}

void VG::PlacedGraphic::setGraphic(VectorGraphic const & graphic)
{
	myGraphic.reset(new VectorGraphic(graphic));
}

void VG::PlacedGraphic::setGraphic(VectorGraphic && graphic)
{
	myGraphic = std::make_unique<VectorGraphic>(std::forward<VectorGraphic>(graphic));
}

HVectorGraphic const & VG::PlacedGraphic::getGraphic() const
{
	return myGraphic;
}

bool VG::PlacedGraphic::operator==(const PlacedGraphic & rhs) const
{
	return (myPlacementPoint == rhs.myPlacementPoint) && (myGraphic == rhs.myGraphic);
}

bool VG::PlacedGraphic::operator!=(const PlacedGraphic & rhs) const
{
	return !(*this == rhs);
}

std::ostream& VG::operator<<(std::ostream& os, const PlacedGraphic& p)
{
	os << "PlacedGraphic: " << p.getPlacementPoint() << ",[" << *p.getGraphic() << "]";
	return os;
}
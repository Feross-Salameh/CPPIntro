#pragma once
#include "VectorGraphic.h"
#include "Point.h"
#include <memory>
#include <iostream>
namespace VG
{
	using HVectorGraphic = std::unique_ptr<VectorGraphic>;
	// allows the placed of VectorGraphics on spesific locations on the layer/scene
	class PlacedGraphic
	{
	public:
		
		PlacedGraphic();
		PlacedGraphic(const Point& placementPoint, const VectorGraphic& graphic);
		// Other constructors will be default, I don't see a need to do anything special:
		PlacedGraphic(const PlacedGraphic& rhs) ;
		PlacedGraphic(PlacedGraphic&& rhs);

		PlacedGraphic& operator=(const PlacedGraphic& rhs);
		PlacedGraphic& operator=(PlacedGraphic&& rhs);

		// taken from code example 2.1
		void setPlacementPoint(Point const& placement);
		void setPlacementPoint(Point&& placement);
		Point const& getPlacementPoint() const;

		void setGraphic(HVectorGraphic const& graphic);
		void setGraphic(HVectorGraphic&& graphic);
		void setGraphic(VectorGraphic const& graphic);
		void setGraphic(VectorGraphic&& graphic);
		HVectorGraphic const& getGraphic() const;

		bool operator==(const PlacedGraphic& rhs) const;
		bool operator!=(const PlacedGraphic& rhs) const;

	private:
		Point myPlacementPoint;
		HVectorGraphic myGraphic;
	};
	std::ostream& operator<<(std::ostream& os, const PlacedGraphic& p);

}



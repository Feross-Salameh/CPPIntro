#pragma once
#include "VectorGraphic.h"
#include "Point.h"

namespace VG
{
	// allows the placed of VectorGraphics on spesific locations on the layer/scene
	class PlacedGraphic
	{
	public:
		PlacedGraphic(const Point& placementPoint, const VectorGraphic& vGrapic);
		// Other constructors will be default, I don't see a need to do anything special:
		PlacedGraphic(const PlacedGraphic& rhs) = default;
		PlacedGraphic(PlacedGraphic&& rhs) = default;

		PlacedGraphic& operator=(const PlacedGraphic&) = default;
		PlacedGraphic& operator=(PlacedGraphic&&) = default;

		// taken from code example 2.1
		void setPlacementPoint(Point const& placement);
		Point const& getPlacementPoint() const;

		void setGraphic(VectorGraphic const& graphic);
		VectorGraphic const& getGraphic() const;

	private:
		Point placementPoint;
		VectorGraphic graphic;
	};
}



#pragma once

#include "Point.h"
#include "VectorGraphic.h"

namespace Framework
{
    
    class PlacedGraphic
    {
    public:
        PlacedGraphic(const Framework::Point& placement,
                      const Framework::VectorGraphic& graphic);
        
        PlacedGraphic();

		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;

		PlacedGraphic & operator=(const PlacedGraphic&) = default;
		PlacedGraphic & operator=(PlacedGraphic&&) = default;

		template<class P> void setPlacementPoint(P&& p)
		{
			myPlacementPoint = std::forward<P>(p);
		}

        const Framework::Point& getPlacementPoint() const;

		template<class Framework> void setGraphic(Framework&& graphic)
		{
			myGraphic = std::forward<Framework>(graphic);
		}

        const Framework::VectorGraphic& getGraphic() const;
        
    private:
        Framework::Point myPlacementPoint;
        Framework::VectorGraphic myGraphic;
    };
    
    bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
    bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
}

#include "PlacedGraphic.h"
#include <memory>

namespace Framework
{
    PlacedGraphic::PlacedGraphic() :
		myGraphic{}, myPlacementPoint{ 0, 0 }
    {
    }
    
    PlacedGraphic::PlacedGraphic(const Framework::Point& placement,
                                 const Framework::VectorGraphic& graphic) :
		myPlacementPoint{ placement },
		myGraphic{ graphic }
    {
    }
    
    const Framework::Point& PlacedGraphic::getPlacementPoint() const
    {
        return myPlacementPoint;
    }
    
    const Framework::VectorGraphic& PlacedGraphic::getGraphic() const
    {
        return myGraphic;
    }
    
    bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs)
    {
        return (lhs.getPlacementPoint() == rhs.getPlacementPoint()) &&
               (lhs.getGraphic() == rhs.getGraphic());
    }
    
    bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs)
    {
        return !(lhs == rhs);
    }
}


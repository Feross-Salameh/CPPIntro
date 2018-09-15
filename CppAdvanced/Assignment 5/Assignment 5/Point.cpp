#include "Point.h"
#include <iostream>

namespace Framework
{
    
    std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.getX() << ", " << p.getY() << ")";
        return os;
    }
    
    bool operator==(const Point& lhs, const Point& rhs)
    {
        return rhs.getX() == lhs.getX() && rhs.getY() == lhs.getY();
    }
    
    bool operator!=(const Point& lhs, const Point& rhs)
    {
        return ! (lhs == rhs);
    }
    
}

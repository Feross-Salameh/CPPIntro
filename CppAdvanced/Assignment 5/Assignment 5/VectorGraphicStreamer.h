#pragma once

#include "VectorGraphic.h"
#include <iosfwd>

namespace Framework
{
    
    class VectorGraphicStreamer
    {
    public:
        static VectorGraphic fromXml(std::istream& xmlSourceStream);
        
        static void toXml(const VectorGraphic& Framework,
                          std::ostream& os);
    };
    
}
#pragma once

#include "Point.h"
#include "IStroke.h"
#include "ICanvas.h"
#include <vector>

namespace Framework
{
    using Points = std::vector<Point>;
    
    class VectorGraphic
    {
    public:
        VectorGraphic();
        
		VectorGraphic(const VectorGraphic& other) = default;
		VectorGraphic(VectorGraphic&& other) = default;

		VectorGraphic& operator=(const VectorGraphic&) = default;
		VectorGraphic& operator=(VectorGraphic&&) = default;

		template<class C> void addPoint(C&& p)
		{
			myPath.emplace_back(std::forward<C>(p));
		}

        void removePoint(const Point& p);
        void erasePoint(int index);
        
        void openShape();
        void closeShape();
        
        bool isOpen() const;
        bool isClosed() const;
        
        int getWidth() const;
        int getHeight() const;
        
        size_t getPointCount() const;
        const Point& getPoint(int index) const;
        
        bool operator==(const VectorGraphic& rhs) const;
        bool operator!=(const VectorGraphic& rhs) const;
        
		void draw(HCanvas& canvas, const Point& offset);
    private:
        Points myPath;
		IStroke* myPenStroke;
        enum class ShapeStyle { Open, Closed } myShapeStyle;
    };
    
}

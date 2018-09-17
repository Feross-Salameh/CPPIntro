#pragma once

#include "Point.h"
#include "Color.h"
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

		VectorGraphic& operator=(const VectorGraphic& other) = default;
		VectorGraphic& operator=(VectorGraphic&& other) = default;

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
        
		std::string getStrokeTip() const { return myStrokeTip; }
		void setStrokeTip(std::string strokeTip) { myStrokeTip = strokeTip; }

		Color getStrokeColor() const { return myStrokeColor; }
		void setStrokeColor(Color strokeColor) { myStrokeColor = strokeColor; }

		int getStrokeSize() { return myStrokeSize; }
		void setStrokeSize(int strokeSize) { myStrokeSize = strokeSize; }

		void draw(HCanvas& canvas, const Point& offset);
    private:
        Points myPath;
		std::string myStrokeTip;
		Color myStrokeColor;
		int myStrokeSize;
        enum class ShapeStyle { Open, Closed } myShapeStyle;

		HStroke generateStroke();
    };
    
}

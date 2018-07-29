#pragma once
#include <vector>
#include "Point.h"

namespace VG
{
	class VectorGraphic
	{
	public:
		VectorGraphic();

		// NOTE: these functions were taken out of Code example 1.3.

		void addPoint(const Point& p);
		void removePoint(const Point& p);
		void erasePoint(int index);

		void openShape();
		void closeShape();

		bool isOpen() const;
		bool isClosed() const;

		
		int getWidth() const;
		int getHeight() const;

		int getPointCount() const;
		Point getPoint(int index) const;


		bool operator== (const VectorGraphic& rhs);
		bool operator!= (const VectorGraphic& rhs);

	private:
		std::vector<Point> myPath;
		bool IsOpen;
	};
}




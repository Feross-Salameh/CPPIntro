#pragma once
#include <vector>
#include "Point.h"

namespace VG
{
	class VectorGraphic
	{
	public:
		VectorGraphic();

		VectorGraphic(const VectorGraphic& other) = default;
		VectorGraphic(VectorGraphic&& other) = default;

		VectorGraphic& operator=(const VectorGraphic&) = default;
		VectorGraphic& operator=(VectorGraphic&&) = default;

		// NOTE: these functions were taken out of Code example 1.3.

		void addPoint(const Point& p);
		void addPoint(Point&& p); // Added from looking at Assignment 1 solution
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




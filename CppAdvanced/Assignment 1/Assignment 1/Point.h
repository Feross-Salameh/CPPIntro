#pragma once
#include <cstdlib>
#include <iostream>
// Using namespace VG in accordance with unit tests.
namespace VG
{
	// //Point class that will be used in my Vector graphic.
	//class Point
	//{ // NOTE: this class is probably simple enough to create everything inline. But just in case there needs to be more functionality added later I'm using .h/.cpp method.
	//public:
	//	// regular ctor
	//	constexpr Point(int x, int y);

	//	// explicitly declaring other ctors and dtor to set them to default.

	//	Point(const Point& rhs) = default; // copy CTOR
	//	Point& operator=(const Point& rhs) = default; // assignment copy 

	//	Point(Point&& rhs) = default; // move CTOR
	//	Point& operator=(Point&& rhs) = default; // assignment move

	//	~Point() = default;


	//	// getters for X and Y. doesn't really make sense to have setters because you can just make a new point easily enough. 

	//	// Gets X coordinate
	//	constexpr int getX() const;
	//	// Gets Y corrdinate
	//	constexpr int getY() const;

	//	// other overloaded functions
	//	// Comparisison Operator
	//	bool operator==(const Point& rhs);
	//	bool operator!=(const Point& rhs);
	//	// 
	//	friend std::ostream& operator<< (std::ostream &os, Point p);
	//private:
	//	// making the coordinates ints instead of doubles. If I need to change them later this shouldn't be a huge problem. Hopefully...

	//	int MyX;
	//	int MyY;
	//};
	class Point 
	{
		int x;
		int y;
	public:
		constexpr Point(int ix, int iy) : x{ ix }, y{ iy } {}
		constexpr int getX() const { return x; }
		constexpr int getY() const { return y; }

		// explicitly declaring other ctors and dtor to set them to default.

		Point(const Point& rhs) = default; // copy CTOR
		Point& operator=(const Point& rhs) = default; // assignment copy 

		Point(Point&& rhs) = default; // move CTOR
		Point& operator=(Point&& rhs) = default; // assignment move

		// other overloaded functions

		// Comparisison Operator
		bool operator==(const Point& rhs);
		bool operator!=(const Point& rhs);
		
		friend std::ostream& operator<< (std::ostream &os, Point p);
	};
}



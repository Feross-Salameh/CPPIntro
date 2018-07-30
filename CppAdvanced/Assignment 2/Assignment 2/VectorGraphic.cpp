#include "VectorGraphic.h"



VG::VectorGraphic::VectorGraphic() : myPath{std::vector<Point>()}, IsOpen(false)
{
}

void VG::VectorGraphic::addPoint(const Point & p)
{
	myPath.push_back(p);
}
void VG::VectorGraphic::addPoint(Point && p)
{
	myPath.emplace_back(std::forward<Point>(p));
}
// Removes p object from mypath.
void VG::VectorGraphic::removePoint(const Point & p)
{ // this is really just a guess on what this function should do. I couldn't really figure out a good sense for it.
	for (size_t i = 0; i < myPath.size(); i++)
	{
		if (myPath[i] == p) // if both pointers POINT to the same object.
		{
			myPath.erase(myPath.begin() + i);
			--i;
		}
	}
}
// Removes point from vector using index.
void VG::VectorGraphic::erasePoint(int index)
{
	if (index < 0)
		throw std::out_of_range("Error in erasePoint: passed index is negative number");
	else if ((size_t)index >= myPath.size())
		throw std::out_of_range("Error in erasePoint: index outside bounds of the array");
	myPath.erase(myPath.begin() + index);
}

void VG::VectorGraphic::openShape()
{
	IsOpen = true;
}

void VG::VectorGraphic::closeShape()
{
	IsOpen = false;
}

bool VG::VectorGraphic::isOpen() const
{
	return IsOpen;
}

bool VG::VectorGraphic::isClosed() const
{
	return !IsOpen;
}

// returns largest difference of width of vector graphic
int VG::VectorGraphic::getWidth() const
{
	int smallest = INT_MAX, largest = INT_MIN;

	for (auto p : myPath)
	{
		if (p.getX() > largest)
			largest = p.getX();
		if (p.getX() < smallest)
			smallest = p.getX();
	}
	if (smallest > largest) // this is here in case there are no points to compare.
		return -1;
	return largest - smallest;
}

// return lagest difference of height of vector graphic
int VG::VectorGraphic::getHeight() const
{

	int smallest = INT_MAX, largest = INT_MIN;

	for (auto p : myPath)
	{
		if (p.getY() > largest)
			largest = p.getY();
		if (p.getY() < smallest)
			smallest = p.getY();
	}
	if (smallest > largest) // this is here in case there are no points to compare.
		return -1;
	return largest - smallest;
}

int VG::VectorGraphic::getPointCount() const
{
	return myPath.size();
}

VG::Point VG::VectorGraphic::getPoint(int index) const
{
	if (index < 0)
		throw std::out_of_range("Error in getPoint: passed index is negative number");
	else if ((size_t)index >= myPath.size())
		throw std::out_of_range("Error in getPoint: index outside bounds of the array");
	return myPath[index];
}

bool VG::VectorGraphic::operator==(const VectorGraphic & rhs)
{
	if (IsOpen != rhs.IsOpen)
		return false;
	if (myPath.size() != rhs.myPath.size())
		return false;
	for (size_t i = 0; i < myPath.size(); i++)
	{
		if (myPath[i] != rhs.myPath[i])
			return false;
	}
	return true;
}

bool VG::VectorGraphic::operator!=(const VectorGraphic & rhs)
{
	return !(*this == rhs);
}




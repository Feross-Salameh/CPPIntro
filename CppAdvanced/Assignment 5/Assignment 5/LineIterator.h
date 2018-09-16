#pragma once

#include "Point.h"

class LineIterator
{
public:
    LineIterator(const Framework::Point& beginPoint, const Framework::Point& endPoint);
    bool isEnd() const;
    Framework::Point getBeginPoint() const;
    Framework::Point getEndPoint() const;
    Framework::Point getCurrentPoint() const;
    void nextPoint();

private:
    Framework::Point myBeginPoint;
    Framework::Point myEndPoint;
    Framework::Point myCurrentPoint;

    int myDeltaX;
    int myDeltaY;
    int myStepX;
    int myStepY;
	int myFraction;
};

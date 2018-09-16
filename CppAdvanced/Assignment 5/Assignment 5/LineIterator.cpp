#include "LineIterator.h"

LineIterator::LineIterator(Framework::Point const& beginPoint, Framework::Point const& endPoint)
	: myBeginPoint(beginPoint),
	myEndPoint(endPoint),
	myCurrentPoint(beginPoint)
{
	myDeltaX = myEndPoint.getX() - myBeginPoint.getX();

	if (myDeltaX < 0)
	{
		myDeltaX = -myDeltaX;
		myStepX = -1;
	}
	else
	{
		myStepX = 1;
	}

	myDeltaX <<= 1;

	myDeltaY = myEndPoint.getY() - myBeginPoint.getY();
	if (myDeltaY < 0)
	{
		myDeltaY = -myDeltaY;
		myStepY = -1;
	}
	else
	{
		myStepY = 1;
	}

	myDeltaY <<= 1;

	if (myDeltaX >= myDeltaY)
	{
		myFraction = myDeltaY - (myDeltaX >> 1);
	}
	else
	{
		myFraction = myDeltaX - (myDeltaY >> 1);
	}
}

Framework::Point LineIterator::getBeginPoint() const
{
	return myBeginPoint;
}

Framework::Point LineIterator::getEndPoint() const
{
	return myEndPoint;
}

Framework::Point LineIterator::getCurrentPoint() const
{
	return myCurrentPoint;
}

bool LineIterator::isEnd() const
{
	return getEndPoint() == getCurrentPoint();
}

void LineIterator::nextPoint()
{
	int x0 = myCurrentPoint.getX();
	int y0 = myCurrentPoint.getY();
	if (myDeltaX >= myDeltaY)
	{
		if (myCurrentPoint.getX() != myEndPoint.getX())
		{
			if (myFraction >= 0)
			{
				y0 += myStepY;
				myFraction -= myDeltaX;
			}

			x0 += myStepX;
			myFraction += myDeltaY;
			myCurrentPoint = Framework::Point(x0, y0);
			return;
		}
	}
	else
	{
		if (y0 != myEndPoint.getY())
		{
			if (myFraction >= 0)
			{
				x0 += myStepX;
				myFraction -= myDeltaY;
			}
			y0 += myStepY;
			myFraction += myDeltaX;
			myCurrentPoint = Framework::Point(x0, y0);
			return;
		}
	}

	myCurrentPoint = myEndPoint;
}

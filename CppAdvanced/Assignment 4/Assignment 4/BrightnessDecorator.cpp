#include "BrightnessDecorator.h"

namespace BitmapGraphics
{
	BrightnessDecorator::BrightnessDecorator(HBitmapIterator iterator) : BrightnessDecorator(iterator, 0)
	{
	}
	BrightnessDecorator::BrightnessDecorator(HBitmapIterator iterator, int brightness) :myOriginalIterator {iterator}, myBrightnessAdjustment{brightness}
	{
	}
	Color BrightnessDecorator::getColor() const
	{
		Color const oldColor = myOriginalIterator->getColor();

		ColorComponent const red = oldColor.getRed() +
			myBrightnessAdjustment;

		ColorComponent const green = oldColor.getGreen() +
			myBrightnessAdjustment;

		ColorComponent const blue = oldColor.getBlue() +
			myBrightnessAdjustment;

		return Color(red.operator int(), green.operator int(), blue.operator int());
	}
}
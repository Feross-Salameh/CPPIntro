#include "ColorInversionDecorator.h"

namespace BitmapGraphics
{
	ColorInversionDecorator::ColorInversionDecorator(HBitmapIterator iterator) : myOriginalIterator(iterator)
	{
	}
	Color ColorInversionDecorator::getColor() const
	{
		Color const oldColor = myOriginalIterator->getColor();

		ColorComponent const red = 255 - oldColor.getRed();

		ColorComponent const green = 255 - oldColor.getGreen();

		ColorComponent const blue = 255 - oldColor.getBlue();

		return Color(red.operator int(), green.operator int(), blue.operator int());

	}
}

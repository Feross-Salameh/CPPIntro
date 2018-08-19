#pragma once
#include "SizeWord.h"
namespace Bitmap
{
	class Color
	{
	public:
		constexpr Color(const Binary::Byte& blue, const Binary::Byte& green, const Binary::Byte& red)
			: myRed{ red }, myGreen{ green }, myBlue{ blue } {}

		Color(const Color& other) = default;
		Color(Color&& other) = default;

		Color& operator=(const Color&) = default;
		Color& operator=(Color&&) = default;

		~Color() = default;

		constexpr uint8_t getRed() const { uint8_t ret = myRed; return ret; }
		constexpr uint8_t getGreen() const { uint8_t ret = myGreen; return ret; }
		constexpr uint8_t getBlue() const { uint8_t ret = myBlue; return ret; }

		void setRed(Binary::Byte&& red) { myRed = red; }
		void setGreen(Binary::Byte&& green) { myGreen = green; }
		void setBlue(Binary::Byte&& blue) { myBlue = blue; }

		void setRed(uint8_t red) { myRed = red; }
		void setGreen(uint8_t green) { myGreen = green; }
		void setBlue(uint8_t blue) { myBlue = blue; }

	private:
		Binary::Byte myBlue{ 0 };
		Binary::Byte myGreen{ 0 };
		Binary::Byte myRed{ 0 };
	};
}


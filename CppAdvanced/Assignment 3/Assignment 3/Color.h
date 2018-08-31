#pragma once
#include "SizeWord.h"
namespace Bitmap
{
	class Color
	{
	public:
		constexpr Color(const Binary::Byte& blue, const Binary::Byte& green, const Binary::Byte& red)
			: myRed{ red }, myGreen{ green }, myBlue{ blue } {}
		Color(int blue, int green, int red)
			: myRed{ red }, myGreen{ green }, myBlue{ blue } {}
		Color() = default;
		Color(const Color& other) = default;
		Color(Color&& other) = default;

		Color& operator=(const Color&) = default;
		Color& operator=(Color&&) = default;

		~Color() = default;

		constexpr int getRed() const { int ret = myRed; return ret; }
		constexpr int getGreen() const { int ret = myGreen; return ret; }
		constexpr int getBlue() const { int ret = myBlue; return ret; }

		void setRed(int red) { myRed = static_cast<uint8_t>(red); }
		void setGreen(int green) { myGreen = static_cast<uint8_t>(green); }
		void setBlue(int blue) { myBlue = static_cast<uint8_t>(blue); }

		void Write(std::ostream& destinationStream)
		{
			myBlue.write(destinationStream);
			myGreen.write(destinationStream);
			myRed.write(destinationStream);
		}

		bool operator==(const Color& rhs) const
		{
			return myBlue == rhs.myBlue && myGreen == rhs.myGreen && myRed == rhs.myRed;
		}

		bool operator!=(const Color& rhs) const
		{
			return !(*this == rhs);
		}

	private:
		Binary::Byte myBlue{ 0 };
		Binary::Byte myGreen{ 0 };
		Binary::Byte myRed{ 0 };
	};
}


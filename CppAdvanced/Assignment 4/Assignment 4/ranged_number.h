#pragma once
#include <type_traits>
#include <iostream>
namespace BitmapGraphics
{
	template<class Number, Number lowerLimit, Number upperLimit>
	class ranged_number
	{
	public:
		ranged_number() = default;

		ranged_number(const ranged_number&) = default;
		ranged_number(ranged_number&&) = default;
		ranged_number(Number num) : myNumber{ num } { checkNumber(); }

		ranged_number& operator=(const ranged_number&) = default;
		ranged_number& operator=(ranged_number&&) = default;
		ranged_number& operator=(Number number)
		{
			myNumber = number;
			checkNumber();
			return *this;
		}
		
		ranged_number& operator+(const ranged_number& rhs)
		{
			myNumber += rhs.myNumber;
			checkNumber();
			return *this;
		}
		ranged_number& operator-(const ranged_number& rhs)
		{
			myNumber -= rhs.myNumber;
			checkNumber();
			return *this;
		}



		operator Number() const { return myNumber; }

		bool operator==(const ranged_number& rhs) const noexcept { return myNumber == rhs.myNumber; }
		bool operator!=(const ranged_number& rhs) const noexcept { return !(*this == rhs); }

		bool operator==(const Number& rhs) const noexcept { return myNumber == rhs; }
		bool operator!=(const Number& rhs) const noexcept { return !(*this == rhs); }

		friend std::ostream& operator<<(std::ostream& os, ranged_number rn)
		{
			os << rn.myNumber;
			return os;
		}
	private:
		Number myNumber;
		static_assert(std::is_integral_v<Number>, "Integral Type required for template creation of base type");
		static_assert(upperLimit > lowerLimit, " Upper Limit must be greater than Lower Limit of number");
		void checkNumber()
		{
			if (myNumber > upperLimit)
				myNumber = upperLimit;
			else if (myNumber < lowerLimit)
				myNumber = lowerLimit;
		}
	};

}


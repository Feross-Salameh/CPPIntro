#pragma once
#include <iostream>
namespace Binary
{
	class Word
	{
	public:
		Word(unsigned short value = 0) : myValue(value) { }
		Word(const Word& other) = default;

		Word& operator=(Word const& original)
		{
			this->myValue = original.myValue;
			return *this;
		}
		Word& operator=(unsigned short value)
		{
			this->myValue = value;
			return *this;
		}

		Word(Word && other) = delete;
		Word& operator=(Word&& original) = delete;
		operator unsigned short() const { return myValue; }


		friend std::ostream& operator<<(std::ostream& os, const Word& word)
		{
			os << std::hex << "0x" << std::uppercase;
			if (word.myValue < 16)
				os << "0";
			os << word.myValue;
			return os;
		}

	private:
		unsigned short myValue;
	};

}


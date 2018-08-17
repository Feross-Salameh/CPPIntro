#pragma once
#include "Byte.h"
#include <iostream>
namespace Binary
{

	class Word
	{
	public:
		Word(unsigned short value = 0) : myValue(value) { }
		Word(const Word& other) = default;
		~Word() = default;
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

		void write(std::ostream& os);
		void read(std::istream& is);

		friend std::ostream& operator<<(std::ostream& os, const Word& word)
		{
			os << std::hex << "0x" << std::uppercase;
			if (word.myValue < 16)
				os << "0";
			os << word.myValue;
			return os;
		}
		const static size_t Length = sizeof(uint16_t);
	private:
		unsigned __int16 myValue;
	};

	// template reads and writes NOTE: cannot be used with Binary::Byte
	template <class T>
	void TemplateWrite(const T& Data, std::ostream& os)
	{
		std::vector<Byte> b(T().Length / Byte().Length);
		auto tempD = Data;

		std::for_each(b.begin(), b.end(), [&tempD](Byte& b)
		{
			b = tempD & 0xFF;
			tempD = tempD >> (b.Length * 8);
		});

		if (!is_big_endian())
			std::for_each(b.begin(), b.end(), [&os](Byte& b) { b.write(os); });
		else
			std::for_each(b.rbegin(), b.rend(), [&os](Byte& b) { b.write(os); });
	}
	template <class T>
	void TemplateRead(T& Data, std::istream& is)
	{
		std::vector<Byte> b(T().Length / Byte().Length);

		if (!is_big_endian())
			std::for_each(b.begin(), b.end(), [&is](Byte& b) { b.read(is); });
		else
			std::for_each(b.rbegin(), b.rend(), [&is](Byte& b) { b.read(is); });
		Data = 0;
		if (b.size() > 2)
			std::for_each(b.rbegin(), b.rend() - 1, [&Data](Byte& b)
		{
			Data = Data + b;
			Data = Data << (b.Length * 8);
		});
		else if (b.size() == 2)
			Data = (b[1] << 8);

		Data = Data + b.front();
	}


}


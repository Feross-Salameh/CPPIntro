#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>
namespace Binary
{
	/*
	source: https://stackoverflow.com/questions/1001307/detecting-endianness-programmatically-in-a-c-program
	*/
	constexpr int is_big_endian()
	{
		union {
			uint32_t i;
			char c[4];
		} bint = { 0x01020304 };

		return bint.c[0] == 1;
	}

	template< typename T>
	class SizeWord
	{
	public:
		SizeWord(T value = 0) : myValue(value) { }
		SizeWord(const SizeWord& other) = default;
		~SizeWord() = default;

		SizeWord& operator=(SizeWord const& original) = default;
		SizeWord& operator=(T value)
		{
			this->myValue = value;
			return *this;
		}

		SizeWord(SizeWord && other) = default;
		SizeWord& operator=(SizeWord&& original) = default;
		operator T() const { return myValue; }
		const static size_t Length = sizeof(T);
		const void write(std::ostream& os);
		const void read(std::istream& is);

	private:
		T myValue;
		static_assert(std::is_arithmetic<T>::value, "value in SizeWoerd must be numeric");
		static_assert(std::is_unsigned<T>::value, "value in SizeWord must be unsigned");
	};
	// predefined sizes of data containers;
	using Byte = SizeWord<uint8_t>;
	using Word = SizeWord<uint16_t>;
	using DoubleWord = SizeWord<uint32_t>;

	template<class T>
	inline const void SizeWord<T>::write(std::ostream & os)
	{
		std::vector<Byte> b(sizeof(T) / sizeof(Byte));
		auto tempD = myValue;
		auto write = [&os](const Byte& b) {
			char * buffer = new char;
			*buffer = b;
			os.write(buffer, 1);
			delete buffer;
		};

		std::for_each(b.begin(), b.end(), [&](Byte& b)
		{
			b = tempD & 0xFF;
			tempD = tempD >> (b.Length * 8);
		});
		if (!is_big_endian())
			std::for_each(b.begin(), b.end(), [&](Byte& b) { write(b); });
		else
			std::for_each(b.rbegin(), b.rend(), [&](Byte& b) { write(b); });
	}
	template<class T>
	inline const void SizeWord<T>::read(std::istream & is)
	{
		std::vector<Byte> b(sizeof(T) / sizeof(Byte));
		auto read = [&is](Byte& byte)
		{
			char * buffer = new char;
			is.read(buffer, 1);
			byte = *buffer;
			delete buffer;
		};

		if (!is_big_endian())
			std::for_each(b.begin(), b.end(), [&](Byte& byte) {read(byte); });
		else
			std::for_each(b.rbegin(), b.rend(), [&](Byte& byte) {read(byte); });

		myValue = 0;
		if (b.size() > 2)
			std::for_each(b.rbegin(), b.rend() - 1, [this](Byte& b) {
				this->myValue = this->myValue + b;
				this->myValue = this->myValue << (b.Length * 8);
			});
		else if (b.size() == 2)
			myValue = (b[1] << 8);
		myValue = myValue + b.front();
	}
}

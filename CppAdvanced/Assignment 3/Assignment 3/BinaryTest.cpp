#include "../../CppUnitLite/TestHarness.h"
#include <iostream>
#include "Word.h"
#include "Byte.h"

using namespace std;


TEST(Word, Binary)
{
	Binary::Word w(5);

	CHECK_EQUAL(5, w);

	auto w2 = w;

	CHECK_EQUAL(w, w2);

	w2 = 10;

	CHECK_EQUAL(5, w);
	CHECK_EQUAL(10, w2);

	Binary::Word w3(w2);

	CHECK_EQUAL(10, w3);
	w3 = 0xfe;
	CHECK_EQUAL(254, w3);

	w3 = 0x100;
}

TEST(Byte, Binary)
{
	Binary::Byte b(5);
}
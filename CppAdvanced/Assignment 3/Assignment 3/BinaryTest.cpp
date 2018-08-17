#include "DoubleWord.h"
#include "Word.h"
#include "Byte.h"
#include "../../CppUnitLite/TestHarness.h"
#include <iostream>


using namespace std;


TEST(DoubleWord, Binary)
{
	Binary::DoubleWord w(5);

	CHECK_EQUAL(5, w);

	auto w2 = w;

	CHECK_EQUAL(w, w2);

	w2 = 10;

	CHECK_EQUAL(5, w);
	CHECK_EQUAL(10, w2);

	Binary::DoubleWord w3(w2);

	CHECK_EQUAL(10, w3);
	w3 = 0xfe;
	CHECK_EQUAL(254, w3);

}

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

}

TEST(Byte, Binary)
{
	Binary::Byte b(5);

	CHECK_EQUAL(5, b);

	auto b2 = b;

	CHECK_EQUAL(5, b2);

	b2 = 7;

	CHECK_EQUAL(5, b);
	CHECK_EQUAL(7, b2);

	Binary::Byte b3(b2);
	CHECK_EQUAL(7, b3);

}
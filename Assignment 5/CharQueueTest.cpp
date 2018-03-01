#include "TestHarness.h"
#include "CppIntroWeekx\CharQueue1.h"
#include "CppIntroWeekx\CharQueue2.h"

// Rename this file to match the functionality under test. E.g., StringTest.
// Add tests and CHECKs as required
TEST(memberFunctions, CharQueue1)
{
	auto c1 = CharQueue1(1);
	c1.enqueue('a');
	c1.enqueue('b');
	CHECK_EQUAL('b', c1.dequeue());
	auto c2 = c1;
	CHECK_EQUAL('a', c1.dequeue());
	CHECK_EQUAL('a', c2.dequeue());
	CHECK_EQUAL('\0', c2.dequeue());
}

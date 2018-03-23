#include "TestHarness.h"
#include "CppIntroWeekx\MyClass.h"
#include "CppIntroWeekx\Probe.h"

#include <iostream>
// Rename this file to match the functionality under test. E.g., StringTest.
// Add tests and CHECKs as required
TEST(Creation, Probe)
{
	auto mcPtr1 = new MyClass();
	CHECK_EQUAL(0, mcPtr1->getIndex());
	CHECK_EQUAL(1, mcPtr1->getMyProbe().getCurrentCount());
	CHECK_EQUAL(1, mcPtr1->getMyProbe().getTotalCount());

	auto mcPtr2 = new MyClass();
	CHECK_EQUAL(0, mcPtr1->getIndex());
	CHECK_EQUAL(1, mcPtr2->getIndex());
	CHECK_EQUAL(2, mcPtr2->getMyProbe().getCurrentCount());
	CHECK_EQUAL(2, mcPtr2->getMyProbe().getTotalCount());

	delete mcPtr1;
	mcPtr1 = nullptr;
	CHECK_EQUAL(1, mcPtr2->getIndex());
	CHECK_EQUAL(1, mcPtr2->getMyProbe().getCurrentCount());
	CHECK_EQUAL(2, mcPtr2->getMyProbe().getTotalCount());

	delete mcPtr2;
	CHECK_EQUAL(0, mcPtr2->getMyProbe().getCurrentCount());
	CHECK_EQUAL(2, mcPtr2->getMyProbe().getTotalCount());

}

TEST(overload, Probe)
{
	auto mcPtr1 = new MyClass();
	auto mcPtr2 = new MyClass();
	std::stringstream ss;

	ss << mcPtr1->getMyProbe();
	// 4 because of the 2 created in the previous test
	CHECK_EQUAL("Total Class Count: 4, Current Class Count: 2.", ss.str());
}

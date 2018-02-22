#include "TestHarness.h"
#include "CppIntroWeekx\write.h"
#include <algorithm>
struct Date
{
	int year;
	int month;
	int day;
};


/// I was wondering if you thought of setting up a function like this to be a good idea, 
/// the function returning a bool stating whether or not the operation was a success
bool AddOneDay(Date& d)
{
	try
	{
		d.day += 1;
		if (d.day > 31) // untrue in some cases, but oh well
		{
			d.day = 0;
			d.month++;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}
bool AddOneMonth(Date& d)
{
	try
	{
		d.month += 1;
		if (d.month > 12) // I know not needed but it felt right
		{
			d.month = 0;
			d.year++;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}
bool AddOneYear(Date& d)
{
	try
	{
		d.year += 1;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

/*
Write functions to add one day, another function to add one month, and yet another function to add one year to a Date struct.

struct Date
{
    int year;
    int month;
    int day;
};
Pass Dates by reference when appropriate (i.e., Date& or const Date&). For example, the following function returns by value a new Date instance with one day added to the passed in date.

Date addOneDay(const Date& date);
*/
TEST(Part1, Date)
{
	Date d;
	d.day = 11; d.month = 3; d.year = 1990;
	// in all of these I can add an else to let the user know the operation failed for some reason.
	if (AddOneDay(d))
	{
		CHECK_EQUAL(12, d.day);
	}

	if (AddOneMonth(d))
	{
		CHECK_EQUAL(4, d.month);
	}

	if (AddOneYear(d))
	{
		CHECK_EQUAL(1991, d.year);
	}
}

/*
Create a C++ header file named write.h which contains function prototypes for three functions named write. 
Write the implementations for each write function in a file named write.cpp. Each write function takes two arguments. 
The first argument is always std::ostream& os. The second arguments are an int, a float, and a std::string respectively. 
Each write function should stream its second argument to the passed in std::ostream. 
Write cppunitlite unit tests that pass a std::stringstream as the first argument to each function and verify its operation. 
Write non unit test code that calls each write function and passes std::cout as the first argument (the cout tests are written outside the unit test framework because verification can't easily be automated). 
Here's the prototype for the first write overload:
void write(std::ostream& os, int value);

Notice that both std::stringstream and std::cout may be passed as the first argument. 
Both inherit from std::ostream and thus may be used where ever a std::ostream& is used. 
This is our first use of inheritance in C++. We'll do much more with inheritance as the course progresses.
*/
TEST(Part2, write)
{
	std::stringstream ss;
	
	std::string s = "Hello World!";
	auto i = 44;
	auto f = 5.0f;

	// testing write...
	write(ss, s);
	write(std::cout, "Writing 'Hello World!' string to ss\n\r");	// I combined both parts into one, the output still shows up on the screen
	CHECK_EQUAL("Hello World!", ss.str());							// so I thought why not.
	ss.str("");

	write(ss, i);
	write(std::cout, "Writing '44' string to ss\n\r");
	CHECK_EQUAL("44", ss.str());
	ss.str("");

	write(ss, f);
	write(std::cout, "Writing '5' string to ss\n\r");
	CHECK_EQUAL("5", ss.str());
	ss.str("");
}

/*
Write a lambda function which makes the following TEST pass:
*/
TEST(lambdaTestProblem, lambdas)
{
	auto values = { 2, 4, 6, 8, 10, 12 };
	auto sum = 0;

	std::for_each(values.begin(), values.end(), [&sum](int i) {sum += i; });

	CHECK_EQUAL(42, sum);
}


/*
[Note: This assignment does not require CppUnitLite tests] Define a simple class with a default constructor, a copy constructor (i.e., a constructor that takes the single parameter: const SimpleClass& src), and destructor. 
Annotate each one so that it writes to cout each time it is invoked.
Declare four functions, f1, f2, f3, and f4 with the following prototypes:
void f1(SimpleClass aSimpleClass);
void f2(SimpleClass aSimpleClass);
void f3(SimpleClass& aSimpleClass);
void f4(SimpleClass* aSimpleClass)
Declare an instance of SimpleClass in the function main and call f1 with that instance as an argument.
Declare an instance of SimpleClass in the function f1. Pass that instance by value, to function, f2.
Declare an instance of the SimpleClass in f2 that uses the copy constructor. Pass that instance by reference to function f3.
Declare a function f4 that takes a pointer to an instance of SimpleClass. Call f4 from within f3 using a pointer to the argument passed into f3.
How many instances of your class were constructed? How many instances of your class were destructed? Why?
*/

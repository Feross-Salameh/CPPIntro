#include "SimpleClass.h"

// quick function I wrote to pause execution before ending
void end()
{
	std::cout << "Press Enter to continue...";
	int t;
	std::cin >> t;
}


/*How many instances of your class were constructed? How many instances of your class were destructed? Why?
		Using the output of the program(located below) it seems that my function created 5 seperate instances of SimpleClass
		and only 4 of those were destroyed. To me this makes sense because while my program was exiting, the last instance was removed, after the console closes.
		There were five different instances created because everytime a function that was pass by value called, it would create a new instance of the class using the copy constructor.
		This was true for only the F1 and F2 functions. F3 and F4 were passing by reference, or pointer. In either case no new data was created.
		Because the new instances were created in the scope of F1 and F2, it also means that the destructors were called once their respective scopes ended.
*/
int main()
{
	// declaring class
	SimpleClass simple;
	f1(simple);
	
	end();
	return 0;
}

void f1(SimpleClass aSimpleClass)
{
	std::cout << "Entered F1" << std::endl;
	SimpleClass simple;
	f2(simple);
	std::cout << "Exited F1" << std::endl;

}


void f2(SimpleClass aSimpleClass)
{
	std::cout << "Entered F2" << std::endl;
	SimpleClass simple(aSimpleClass);
	f3(simple);
	std::cout << "Exited F2" << std::endl;
}

void f3(SimpleClass& aSimpleClass)
{
	std::cout << "Entered F3" << std::endl;
	f4(&aSimpleClass);
	std::cout << "Exited F3" << std::endl;
}

void f4(SimpleClass* aSimpleClass)
{
	std::cout << "Entered F4" << std::endl;
	std::cout << "Exited F4" << std::endl;
}

/*	OUTPUT OF CURRENT PROGRAM:
Default constructor called
Copy constructor called
Entered F1
Default constructor called
Copy constructor called
Entered F2
Copy constructor called
Entered F3
Entered F4
Exited F4
Exited F3
Exited F2
Deconstructor called
Deconstructor called
Exited F1
Deconstructor called
Deconstructor called
Press Enter to continue...
*/
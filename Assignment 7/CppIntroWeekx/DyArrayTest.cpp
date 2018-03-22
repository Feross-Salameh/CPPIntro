#include "..\TestHarness.h"
#include "DyArray.h"



TEST(creation, DyArray)
{
	DyArray da(5);

	da[3] = 5;
	CHECK_EQUAL(5, da[3]);
	// assignemnt operator 
	auto da2 = da;
	CHECK_EQUAL(5, da2[3]);
	// copy ctor
	auto da3(da2);
	CHECK_EQUAL(5, da3[3]);

	std::cout << da;

}


/*
	5. In this case, why is it better to write our own copy constructor and assignment operator rather than rely on the compiler generated ones?

	It is better to create our own because int[] doesn't have a default constructor to initialize it. 
	The compiler synthesized copy ctor and assignment would not copy the array from the lhs to the rhs.
	
*/

/*
	6. In what situation might it be better to rely on the compiler generated copy constructor and assignment operators?

	Anything that uses STD template libraries would work well becuase they are deisgned with these types of problems in mind. 
	Usually they're ctors/dtors handle all of the set up so when using them in your class you don't need to worry about it.
	This or classes with basic member types (int stirng char bool etc.).

*/
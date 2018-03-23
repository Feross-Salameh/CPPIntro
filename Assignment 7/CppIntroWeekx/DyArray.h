#pragma once
#define _SCL_SECURE_NO_WARNINGS  
#include <algorithm>
#include <iostream>
class DyArray
{
public:
	DyArray();
	DyArray(size_t size);
	~DyArray();
	// copy ctor
	DyArray(DyArray& rhs);

	//assignment operator
	DyArray& operator=(DyArray& rhs);

	// Overwrites an existing element, or adds a new element as necessary.
	// If an element exists at index, the existing element is overwritten.
	// If an element does not exist at the index, a new element is added. If necessary, the array
	// must expand to accommodate the new element. 
	void put(int index, int value);

	// returns the element at index. If index is out of bounds, return 0.
	int get(int index) const;

	// removes the element at the specified index. The array may contract.
	void remove(int index);

	// [] overloads
	int &operator[] (int index);
	int &operator[] (int index) const;

	friend std::ostream& operator<<(std::ostream& os, DyArray& da);
private:
	int mySize;
	int myCount;
	int* myData;
	void expand(int newSize);
	void contract();
};


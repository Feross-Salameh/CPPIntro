#include <memory>
#include <iostream>
#include <string>

class CharQueue1
{
public:
	CharQueue1();
	CharQueue1(size_t size);
	CharQueue1(const CharQueue1& src); // copy constructor

	void enqueue(char ch);
	char dequeue();

	bool isEmpty() const;
	void swap(CharQueue1& src);

	int capacity() const;

	CharQueue1& operator=(CharQueue1 src);
private:
	size_t mySize;
	int myIndex;
	std::unique_ptr<char[]> myArray;

};
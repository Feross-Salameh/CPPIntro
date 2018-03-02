#pragma once
#include<deque>
class CharQueue2
{
public:
	CharQueue2();
	CharQueue2(size_t size);

	void enqueue(char ch);
	char dequeue();

	bool isEmpty() const;
	void swap(CharQueue2& src);

	int capacity() const;

	CharQueue2& operator=(CharQueue2 src);

private:
	std::deque<char> myArray;
};
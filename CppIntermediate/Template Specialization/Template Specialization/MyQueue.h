#pragma once
#define _SCL_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <deque>

/*
	using as reference:
		http://www.cplusplus.com/reference/stl/
*/

// NOTE: this class cannot handle other STL containers besides vector, list, deque.
template<typename Container>
class MyQueue
{
public:
	// Default ctor
	MyQueue() : myContainer(Container()) { }
	MyQueue(const Container & c) : myContainer(Container(c)) { } // if containter wanted to be copied
	
	// copy ctor
	MyQueue(const MyQueue & c) : myContainer(Container(c.myContainer)) {}
	// assignment operator
	MyQueue& operator=(const MyQueue& c)
	{
		Container tmp = c.myContainer;
		std::swap(myContainer, tmp);
		return *this;
	}

	typedef typename Container::value_type Element;

	Element Pop()
	{

		Element e = myContainer.front();
		myContainer.erase(myContainer.begin());
		return e;
	}
	
	void Push(const Element & e)
	{   // only works for vector, list, deque.
		myContainer.push_back(e);
	}

private:
	Container myContainer;

};

// This is a partial specialization. the value type stored in deque still can be anything
template<typename T>
class MyQueue<std::deque<T>>
{
public:
	MyQueue() : myDeque(std::deque<T>()) { }
	MyQueue(const std::deque<T>& d) : myDeque(std::deque<T>(d)) { }

	T Pop()
	{
		auto ret = myDeque.front();
		myDeque.pop_front();
		return ret;
	}

	void Push(const T & t)
	{
		myDeque.push_back(t);
	}
private:
	std::deque<T> myDeque;
};
#pragma once
#define _SCL_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

//FROM PREVIOUS HW ASSIGNMENT, just using it for a reference 
//template<typename T>
//class MyQueue
//{
//public:
//	MyQueue(size_t size) :
//		mySize(size), myCount(0), myArray(NULL)
//	{
//		if (mySize > 0)
//			myArray = new T[mySize];
//	}
//	MyQueue() : MyQueue(5) // default will make a queue with 5 spots.
//	{
//
//	}
//	~MyQueue()
//	{
//		delete[] myArray;
//	}
//
//
//	void Push(const T& item)
//	{
//		if (myCount >= mySize)
//		{
//			try
//			{
//				// instead of adding one at a time. this will add 5 at a time
//				// to help with performance.
//				int sizeIncrease = 5;
//				T* tmp = new T[mySize + sizeIncrease];
//				// copy all of the contents from myArray into tmp
//				std::copy(myArray, myArray + mySize, tmp);
//				// swap pointers for myArray and tmp. 
//				std::swap(myArray, tmp);
//				delete[] tmp;
//				mySize += sizeIncrease;
//			}
//			catch (const std::exception&)
//			{
//				throw MyInvalidArgumentException();
//			}
//		}
//		myArray[myCount++] = item;
//	}
//	T& pop()
//	{
//		if (myCount <= 0)
//			throw MyQueueEmpty();
//		T& ret = myArray[myCount--];
//		if(myCount > 1)
//			for (unsigned int i = 0; i < myCount - 1; ++i)
//			{
//				myArray[i] = myArray[i + 1];
//			}
//
//		return ret;
//	}
//
//	bool IsEmplty() const { return myCount > 0; }
//	size_t size() const { return mySize; }
//
//	MyQueue<T> operator=(const MyQueue<T> & rhs)
//	{
//		if (this == rhs)
//			return *this;
//		T * tmp = NULL;
//		if (rhs.mySize > 0)
//		{
//			try
//			{
//				tmp = new T[rhs.mySize];
//				for (int i = 0; i < rhs.myCount; ++i)
//				{
//					tmp[i] = (T)rhs.myArray[i];
//				}
//
//			}
//			catch (const std::exception&)
//			{
//				throw MyDataModifyException();
//			}
//			delete[] myArray;
//
//			myArray = tmp;
//			mySize = rhs.mySize;
//			myCount = rhs.myCount;
//		}
//		else
//			mySize = 0;
//
//		return *this;
//	}
//
//	template<typename T2>
//	MyQueue<T> operator=(const MyQueue<T2> & rhs)
//	{
//		T * tmp = NULL;
//		if (rhs.mySize > 0)
//		{
//			try
//			{
//				tmp = new T[rhs.mySize];
//				for (int i = 0; i < rhs.myCount; ++i)
//				{
//					tmp[i] = (T)rhs.myArray[i];
//				}
//
//			}
//			catch (const std::exception&)
//			{
//				throw MyDataModifyException();
//			}
//			delete[] myArray;
//
//			myArray = tmp;
//			mySize = rhs.mySize;
//			myCount = rhs.myCount;
//		}
//		else
//			mySize = 0;
//
//		return *this;
//	}
//
//	void printArray()
//	{
//		std::cout << "MyQueue, Size = " << mySize << ", Count = " << myCount << std::endl;
//		for (unsigned int i = 0; i < myCount; ++i)
//		{
//			std::cout << "T[" << i << "] = " << myArray[i] << ", ";
//		}
//		std::cout << std::endl;
//	}
//private:
//	size_t mySize;
//	unsigned int myCount;
//	T* myArray;
//};

/*
	using as reference:
		http://www.cplusplus.com/reference/stl/
*/

template<typename Container>
class MyQueueC
{
public:
	// Default ctor
	MyQueueC() : myContainer(Container()) { }
	MyQueueC(const Container & c) : myContainer(Container(c)) { } // if containter wanted to be copied
	
	// copy ctor
	MyQueueC(const MyQueueC & c) : myContainer(Container(c.myContainer)) {}
	// assignment operator
	MyQueueC& operator=(const MyQueueC& c)
	{
		Container tmp = c.myContainer;
		std::swap(myContainer, tmp);
		return *this;
	}

	typedef typename Container::value_type Element;

	Element Pop()
	{
		Element e = myContainer.front();

		return e;
	}

	void Push(const Element & e);

private:
	Container myContainer;

};
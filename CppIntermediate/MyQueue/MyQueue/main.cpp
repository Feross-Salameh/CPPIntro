#define _SCL_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <iostream>
#include "MyQueue.h"



using namespace std;

int main()
{
	auto q1 = MyQueue<int>(1);

	q1.Push(5);
	q1.printArray();
	q1.Push(6);
	q1.Push(10);
	q1.printArray();
	auto q2 = q1;
	q1.pop();
	q1.pop();
	q1.printArray();

	try
	{
		q1.pop();
		q1.pop();
	}
	catch (const MyQueueEmpty)
	{
		cout << "Queue Empty exception thrown" << endl;
	}
	catch (const MyException)
	{
		cout << "General Exception thrown" << endl;
	}

	q2.printArray();
	return 0;
}
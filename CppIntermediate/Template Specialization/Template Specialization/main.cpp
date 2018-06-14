#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
#include "MyQueue.h"


using namespace std;

int main()
{
	MyQueueC<deque<int>> q1;
	MyQueueC<vector<double>> q2;
	//q1.Push(5);
	//q1.Push(10);
	//q1.Pop();
	cout << "Press any key to continue..." << endl;
	cin;
	return 0;
}
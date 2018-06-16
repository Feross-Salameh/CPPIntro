#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include "MyQueue.h"


using namespace std;

int main()
{
	MyQueue< vector<double> > q2;
	MyQueue< deque<double> > qi;
	MyQueue< deque<string> > qs;
	MyQueue< list<int> > qli;


	qi.Push(5);
	qi.Push(10);
	qi.Pop();
	cout << "Press any key to continue..." << endl;
	cin;
	return 0;
}
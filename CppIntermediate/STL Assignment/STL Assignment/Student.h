#pragma once
#include <string>

using namespace std;

class Student
{
public:
	Student(string name, int id);

	string getName() const;
	int getID() const;

	bool operator>(const Student& rhs);

private:
	string myName;
	int myID;
};


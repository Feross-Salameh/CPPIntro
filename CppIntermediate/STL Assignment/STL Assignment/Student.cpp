#include "Student.h"



Student::Student(string name, int id) :
	myName{name}, myID{id}	
{

}

string Student::getName() const
{
	return myName;
}

int Student::getID() const
{
	return myID;
}

bool Student::operator>(const Student & rhs)
{
	return this->myName[0] > rhs.myName[0];
}

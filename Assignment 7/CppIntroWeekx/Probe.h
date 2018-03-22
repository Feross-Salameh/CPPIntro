#pragma once
#include <iostream>
class Probe
{
public:
	Probe();
	~Probe();
	// deleting copy & assigment operator
	Probe(Probe& rhs) = delete;
	Probe& operator=(Probe& rhs) = delete;
	// member data access
	unsigned int& getCurrentCount();
	unsigned int& getTotalCount();

	friend std::ostream& operator<<(std::ostream& os, Probe& p);
private:
	unsigned int myCounter = 0;
	unsigned int myTotalCounter = 0;

};


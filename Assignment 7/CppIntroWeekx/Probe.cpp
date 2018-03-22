#include "Probe.h"

Probe::Probe()
{
}


Probe::~Probe()
{
}

unsigned int& Probe::getCurrentCount()
{
	return myCounter;
}

unsigned int& Probe::getTotalCount()
{
	return myTotalCounter;
}

std::ostream & operator<<(std::ostream & os, Probe & p)
{
	os << "Total Class Count: " << p.getTotalCount() << ", Current Class Count: " << p.getCurrentCount() << ".";

	return os;
}

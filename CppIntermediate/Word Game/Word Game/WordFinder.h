#pragma once
#include "Dictionary.h"
#include <vector>
class WordFinder
{
public:
	WordFinder();
	
	std::vector<string> FindWords(string base, std::vector<char> chars);
private:
	Dictionary myDict; // default constructor will work here.
};


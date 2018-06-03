#pragma once
#include "Dictionary.h"
#include <vector>
class WordFinder
{
public:
	WordFinder();

	std::vector<pair<string, pair<int, int>>> FindWords(string base, std::vector<pair<char, pair<int, int>>> chars);
	bool IsWord(string check);
	bool IsPossibleWord(string check);
private:
	Dictionary myDict; // default constructor will work here.
};


#include "WordFinder.h"



WordFinder::WordFinder()
{
	cout << "Word finder Created" << endl;
}

std::vector<pair<string, pair<int, int>>> WordFinder::FindWords(string base, std::vector<pair<char, pair<int, int>>> chars)
{
	std::vector<pair<string, pair<int, int>>> foundWords;
	for (auto c : chars)
	{
		if (myDict.contains(base + c.first))
			foundWords.push_back(pair<string, pair<int, int>>(base + c.first, c.second));
	}
	return foundWords;
}

bool WordFinder::IsWord(string WordToCheck)
{
	return myDict.contains(WordToCheck);
}

bool WordFinder::IsPossibleWord(string check)
{
	
	return myDict.has(check);
}



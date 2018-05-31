#include "WordFinder.h"



WordFinder::WordFinder()
{
}

std::vector<string> WordFinder::FindWords(string base, std::vector<char> chars)
{
	std::vector<string> foundWords;
	for (auto c : chars)
	{
		if (myDict.contains(base + c))
			foundWords.push_back(base + c);
	}
	return foundWords;
}


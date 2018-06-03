#include "WordGame.h"
Board InitializeBoardDebug();

WordGame::WordGame(int rows, int cols, int maxWordLen) :
	myFinder(), myBoard(InitializeBoardDebug()), myMaxSize(maxWordLen)
{
	cout << "Word Game created" << endl;
}

WordGame::~WordGame()
{
	cout << "Word Game ended" << endl;
}

void WordGame::Run()
{
	// DEGUG LINE:
	//myBoard = InitializeBoardDebug();

	vector<string> words;
	myBoard.printBoard();
	cout << "Looking only for words less than size " << myMaxSize << "...";
	vector<pair<int, int>> currentWord;
	// start of main loop :
	for (int r = 0; r < myBoard.NumRows(); ++r)
	{
		for (int c = 0; c < myBoard.NumCols(); ++c)
		{
			vector<vector<pair<int, int>>> currentChar;
			currentChar.push_back(vector<pair<int, int>>());
			currentChar[0].push_back(pair<int, int>(r, c));
			while (currentChar.size() > 0)
			{
				if (currentChar.back().size() > myMaxSize)
				{
					currentChar.pop_back();
					continue;
				}
				auto total = getWord(currentChar.back());
				if (myFinder.IsWord(total))
					words.push_back(total);
				if (myFinder.IsPossibleWord(total))
				{
					currentWord.push_back(currentChar.back().back());
					auto spots = myBoard.getSpacesAroundSpot(currentChar.back());
					auto tmp = currentChar.back();
					currentChar.pop_back();
					for (auto p : spots)
					{
						tmp.push_back(p);
						currentChar.push_back(tmp);
						tmp.pop_back();
					}
						
				}
				else
					currentChar.pop_back();
			}
			
		}
	}
	cout << words.size() << " words found: " << endl;
	int c = 0;
	int maxWordPerLine = 10;
	for (auto s : words)
	{
		if (c == maxWordPerLine)
		{
			c = 0;
			cout << endl << "\t";
		}
		cout << s << " ";
		++c;
	}
	cout << endl << endl;

	cout << "Word Game run has finished.";
}

string WordGame::getWord(vector<pair<int, int>> currentChar)
{
	string ret;
	for (auto p : currentChar)
		ret += myBoard.getSpot(p);
	return ret;
}

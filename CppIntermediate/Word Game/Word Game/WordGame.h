#pragma once
#include <iostream>
#include <memory>
#include <stack>
#include "Dictionary.h"
#include "WordFinder.h"
#include "Board.h"

using namespace std;
class WordGame
{
public:
	WordGame(int rows, int cols, int maxWordLen);
	~WordGame();

	void Run();

private:
	WordFinder myFinder;
	Board myBoard;
	int myMaxSize;

	string getWord(vector<pair<int, int>> currentChar);
};


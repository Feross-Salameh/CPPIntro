#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <stdlib.h>     
#include <time.h>    
#include <vector>
#include <stack>
using namespace std;
class Board
{
public:
	// ctors
	Board(int rows, int cols); // this will create board with random letters attached to it.
	Board(int rows, int cols, const char board[]); // redefined board
	Board(); // using default board (in HW assignment)

	// methods
	int NumRows() const;
	int NumCols() const;
	char getSpot(int row, int col) const;
	char getSpot(const pair<int, int>& index) const;
	vector < pair<int, int>> getSpacesAroundSpot(const vector < pair<int, int>>& current);
	void printBoard();
	// friends
	friend Board InitializeBoardDebug();

private:
	int myRows;
	int myCols;
	unique_ptr<unique_ptr<char[]>> myBoard;
};


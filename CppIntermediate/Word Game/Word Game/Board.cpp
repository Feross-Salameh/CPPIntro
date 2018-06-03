#include "Board.h"


/// creates m x n board with randomly generating letters.
Board::Board(int rows, int cols) :
	myRows(rows), myCols(cols), myBoard(new unique_ptr<char[]>[rows])
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < myRows; i++)
	{
		try
		{
			unique_ptr<char[]> tmp(new char[myCols]);
			for (int j = 0; j < myCols; ++j)
			{
				tmp[j] = (rand() % 26) + 'a';
			}
			myBoard.get()[i] = move(tmp);
		}
		catch (const std::exception&)
		{
			// something went woring, inform user
			cout << "Error creating board." << endl;
		}

	}
}

/// creates m x n board with a pre defined set of letters
Board::Board(int rows, int cols, const char board[]) :
	myRows(rows), myCols(cols), myBoard(new unique_ptr<char[]>[rows])
{
	for (int i = 0; i < myRows; i++)
	{
		try
		{
			unique_ptr<char[]> tmp(new char[myCols]);
			for (int j = 0; j < myCols; ++j)
			{
				tmp[j] = board[i* myCols + j];
			}
			myBoard.get()[i] = move(tmp);
		}
		catch (const std::exception&)
		{
			// something went woring, inform user
			cout << "Error creating board." << endl;
		}

	}
}

// default is 4 by 4 board, randomly generated
Board::Board() : Board(4, 4) 
{

}




int Board::NumRows() const
{
	return myRows;
}

int Board::NumCols() const
{
	return myCols;
}

char Board::getSpot(int row, int col) const
{
	return myBoard.get()[row][col];
}

char Board::getSpot(const pair<int, int>& index) const
{
	return myBoard.get()[index.first][index.second];
}

// will get a list of all usable pairs around the top of current. This function will also make sure list does not 
// contain in previously used values
vector<pair<int, int>> Board::getSpacesAroundSpot(const vector<pair<int, int>>& current)
{
	vector<pair<int, int>> ret;
	if (current.size() <= 0)
		return ret;
	// in this funtion since I'm runnning low on time, I will just have to hard code and check all 8  spots 
	// around top to make sure they exist/ not used
	auto top = current.back();
	--top.first; --top.second;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			// this if statement is very awkward, might fix later.
			if (find(current.begin(), current.end(), pair<int, int>(top.first + i, top.second + j)) == current.end()) // making sure spot is not in previously used
				if (top.first + i >= 0 && top.second + j >= 0) // making sure index is actually in array.
					if (top.first + i <= myRows - 1 && top.second + j <= myCols - 1) // making sure index is actually in array.
						ret.push_back(pair<int, int>(top.first + i, top.second + j));
		}
	}
	return ret;
}

void Board::printBoard()
{
	cout << "Current board:" << endl;
	for (int r = 0; r < myRows; ++r)
	{
		cout << "\t";
		for (int c = 0; c < myCols; ++c)
		{
			cout << myBoard.get()[r][c] << "  ";
		}
		cout << endl;
	}

}

/// Initializes the board with the matrix included in the HW assignment.
Board InitializeBoardDebug()
{
	char standard[16] = { 'a', 'p', 'e', 'x', 'n', 'o', 't', 's', 'e', 't', 'i', 'n', 'r', 'y', 'e', 'g'};
	return Board(4, 4, standard);
}

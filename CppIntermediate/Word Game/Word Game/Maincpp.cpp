#include <iostream>
#include "Dictionary.h"
#include "WordFinder.h"
#include "Board.h"
#include "WordGame.h"
Board InitializeBoardDebug();
int main()
{
	WordGame game(4, 4, 3);
	game.Run();
	return 0;
}
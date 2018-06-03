#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
/*
	This class will contain the dictionary of all possible words. the dictionary will store them in a list.
	I chose this method because there will be a lot of searches that have to occur in order for the game to find all of the words, and I'm assuming this 
	will run on a computer that can handle all of the words in the txt file.
*/

class Dictionary
{
public:
	Dictionary();
	bool contains(const string& word) const;
	bool has(const string& word) const;
private:
	list<string> root; // a list has a more optimal insert than vector

};


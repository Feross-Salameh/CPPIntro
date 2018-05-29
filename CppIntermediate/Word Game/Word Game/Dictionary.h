#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stack>
#include <memory>
using namespace std;
/*
	This class will contain the dictionary of all possible words. the dictionary will store them in a non-binary tree for O(logn) time and O(n) memory.
	I chose this method because there will be a lot of searches that have to occur in order for the game to find all of the words, and I'm assuming this 
	will run on a computer that can handle all of the words in the txt file.
*/


// node data structure to contain word
class Node
{
	// making everything in class public for ease of use. This class should only hold data and not have to compute anything.
public:
	Node(Node * parent, string word) : 
		myParent(parent), myWord(word)
	{ }
	Node * myParent;
	string myWord;
	vector<Node *> myChildren;
	~Node()
	{
		myChildren.clear(); //assuming this gets called automatically but just making sure.
	}
};

class Dictionary
{
public:
	Dictionary();
	bool contains(const string word) const;
private:
	unique_ptr<Node> root; //made unique so I wouldn't have to worry about deleting tree when Dictionary gets deleted.

};


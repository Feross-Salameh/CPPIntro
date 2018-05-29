#include "Dictionary.h"


/*
	NOTE: the default constructor will try and find the file assuming it's in the correct folder. 
	If not, constructor will throw an error
*/
Dictionary::Dictionary()
	: root(new Node(nullptr, "1ROOT")) // added 1 at begnning of word to know if root node.
{

	ifstream wordFile;
	wordFile.open("WordsList.txt");
	if (!wordFile.is_open())
		throw new exception("Could Not Find WordsList.txt");
	string word;
	wordFile >> word;
	// setting up loop
	Node* parent = root.get(); // this is generally forwned upon, but will be needed in loop
	stack<Node *> nodes;
	Node* temp = new Node(parent, word);

	nodes.push(parent);
	parent->myChildren.push_back(temp);
	nodes.push(temp);
	while (wordFile >> word)
	{
		Node * temp = new Node(nodes.top(), word);
		
		if (nodes.top()->myWord == "1ROOT") // if at root in stack:
		{
			nodes.top()->myChildren.push_back(temp);
			nodes.push(temp);
			continue;
		}
		while (temp->myWord.find(nodes.top()->myWord) != string::npos)
		{
			nodes.pop();
		}

	}

	wordFile.close();
}

bool Dictionary::contains(const string word) const
{
	return false;
}

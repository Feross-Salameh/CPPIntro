#include "Dictionary.h"


/*
	NOTE: the default constructor will try and find the file assuming it's in the correct folder. 
	If not, constructor will throw an error
*/
Dictionary::Dictionary()
	: root(list<string>()) 
{

	ifstream wordFile;
	wordFile.open("WordsList.txt"); 
	if (!wordFile.is_open())
		throw new exception("Could Not Find WordsList.txt");
	string word;
	cout << "starting word extraction from txt file..";
	while (wordFile >> word)
		root.push_back(word);
	cout << "done." << endl;
	cout << "Starting sort...";
	root.sort(); // I think this is unnessessary due to list being in order, but if given an unsorted list this will solve that edge case.
	cout << "done." << endl;
	wordFile.close();
	cout << "File closed." << endl;
}

bool Dictionary::has(const string & word) const
{
	return find_if(root.begin(), root.end(), [word](string str) -> bool
	{
		return str.find(word) != string::npos;
	}) != root.end();
}

bool Dictionary::contains(const string& word) const
{	
	//auto ret = lower_bound(root.begin(), root.end(), word, [](string lhs, string rhs) -> bool // using lower bound for O(logn) time complexity
	//{
	//	return lhs > rhs;
	//}) != root.end();
	//return ret;
	return find(root.begin(), root.end(), word) != root.end();
}

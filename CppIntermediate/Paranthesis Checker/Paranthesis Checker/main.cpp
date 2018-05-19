#include <iostream>
#include <stack>
#include <map>
#include <string>


using namespace std;

/// function will make sure paranthesis are valid
/// this function will be O(n) time complexity as well as O(n) memory.
/// There might be some improvements.
bool checkParanthesis(const string& input)
{
	stack<char> parans; // data structure to hold current parans.
	map<char, char> dict; // stores and pairs opening and closing paranthesis.
	dict['{'] = '}'; // this method might be overkill for three pairs, but it has the added benifit of being extensible 
	dict['['] = ']';
	dict['('] = ')';

	// now we can iteratore through string.
	for (auto c : input)
	{
		auto pair = dict.find(c);
		if (pair == dict.end()) // we don't care if the current character is not a paranthesis 
				continue;
		if (pair->first == c) // value is key (opening paranthesis) we should just push onto the stack
			parans.push(c);
		else
		{
			// assuming value is closing paranthesis. will first check if stack is empty
			if (parans.empty())
				return false;
			// now we will check if it's matching,
			if (pair->second == parans.top()) // if true, continue with operation
				parans.pop();
			else // if not mathing, input is not setup correctly.
				return false;
		}
	}
	if(parans.empty())
		return true;
	return false;
}


int main(int argc, char **argv)
{
	// instead of reading from a text file, I will prompt the user to input a string the program to check if the 
	// paranthesis is valid
	cout << "Welcome to paranthesis checker" << endl;
	while (true) // I know it's never ending, assumeing user will just CTRL+C out of program
	{
		cout << "Please enter string to check:";
		string inp;
		cin >> inp;
 		string output = (checkParanthesis(inp)) ? "String is well formed" : "String formed incorrectly";
		cout << output << endl;
	}

	return 0;
}
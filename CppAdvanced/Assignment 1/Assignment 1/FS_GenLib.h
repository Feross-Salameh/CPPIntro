#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
// Where all my general functions I will create will go.
class FS_GenLib
{
public:


	/*
		reference:https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring 
		modified the code to handle better what I needed it to do.
	*/
	// trims the begining and end of source string of any and all characters contained in the trimmables string
	static void trim(std::string& sourceString, std::string const& trimmables)
	{
		// trim from begining
		sourceString.erase(sourceString.begin(), sourceString.erase(sourceString.begin(), std::find_if(sourceString.begin(), sourceString.end(), 
		[trimmables](int c) 
		{
			return trimmables.find(c) == std::string::npos;
		})));

		// trim from ending
		sourceString.erase(std::find_if(sourceString.rbegin(), sourceString.rend(), 
		[trimmables](int c) 
		{
			return trimmables.find(c) == std::string::npos;
		}).base(), sourceString.end());
	}

	static void eat(std::istream& sourceStream, std::string const& edibles)
	{
		char c = sourceStream.peek();

		while (c != EOF && edibles.find(c) != std::string::npos)
		{
			sourceStream.get();
			c = sourceStream.peek();
		}
	}

private:
};



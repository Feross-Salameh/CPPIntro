#include <iostream>
#include <string>

using namespace std;
//Write a program that prompts the user to enter an int, a double, and a string on the command line.
//Read the values into variables of the appropriate data type with std::cin.Write the 3 values to std::cout.
//This program does not require the use of CppUnitLite.
int main()
{
	int i = 0;
	double d = 0;
	string s = "";
	// int
	cout << "Please enter an int: ";
	cin >> i;
	cout << "You entered the int: " << to_string(i) << "." << endl;

	// double 
	cout << "Please enter a double: ";
	cin >> d;
	cout << "You entered the double: " << to_string(d) << "." << endl;

	// string 
	cout << "Please enter a string: ";
	cin >> s;
	cout << "You entered the string: " << s << "." << endl;

	return 0;
}
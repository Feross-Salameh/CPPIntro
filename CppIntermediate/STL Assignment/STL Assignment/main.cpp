#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <locale>
#include "Student.h"
using namespace std;


// trim from start (in place)
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
	trim(s);
	return s;
}

// Name basically implies what this function will do. 
vector<Student> getStudents(string filepath)
{
	// getting all of the file and putting it into one string.
	ifstream ifs(filepath);
	string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	ifs.close();

	// putting file into stringstream to use getline function.
	stringstream ss(content);

	string studentString;
	vector<Student> ret;
	// while loop for inserting student objects into the vector.
	while (getline(ss, studentString, ','))
	{
		string name = studentString.substr(0, studentString.find(";"));
		trim(name);
		int id = 0;
		// this try is incase the ID is not available will default to 0
		try
		{
			id = stoi(studentString.substr(studentString.find(";") + 1, studentString.length()));
		} catch (const std::exception&) { }
		ret.push_back(Student(name, id));
	}

	return ret;
}

/*
create a vector of vector of Student ( vector < vector< Student> >
vecVecStudents ) where vecVecStudents[ ii ] is a vector of Student objects that
start with the same letter. In other words, each vector inside the outermost vector
contains students whose name starts with the same letter ( case insensitive)
*/
vector<vector<Student>> organizeStudents(vector<Student>& students)
{
	// sorting students
	sort(students.begin(), students.end(), [](const Student& lhs, const Student& rhs) 
	{ 
		return tolower(lhs.getName()[0]) < tolower(rhs.getName()[0]); // attaching lambda less than function, also case insensitive
	}); 
	// now that our vector is sorted by first letter, inserting them into the correct vectors will be a O(n) operation with some improvements
	vector<vector<Student>> ret; // return list
	char currentChar = students[0].getName()[0]; // need starting character for algorithm
	int i = 0; // starting index of return vector
	ret.push_back(vector<Student>());
	for (auto s : students)
	{
		if (currentChar != s.getName()[0]) // if we are on new character, we need to switch vectors.
		{
			++i;
			ret.push_back(vector<Student>()); //creating new vector
			currentChar = s.getName()[0]; // assigning new current character
		}
		ret[i].push_back(s);
	}
	return ret;
}

//takes a vector of students and prints them in a single line
void printStudents(vector<Student> students)
{
	for (auto s : students)
	{
		cout << "(" << s.getName() << ":" << s.getID() << ")";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	// testing my student object...
	Student sd("Feross", 123);
	cout << sd.getName() << endl; 
	cout << sd.getID() << endl;

	auto list = getStudents("StudentInfo.txt");
	auto sortedList = organizeStudents(list);
	
	// printing students...
	cout << "All students sorted alphabetically: " << endl;
	for (auto& vs : sortedList)
	{
		cout << (char)toupper(vs[0].getName()[0]) << ": ";
		printStudents(vs);
	}
}
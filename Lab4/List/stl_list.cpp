//--------------------------------------------------------------------
// STL List Exercise
// file: main.cpp
//
// Reads a list of student names, sorts the list according to a key, and
// prints the sorted list.
//
//	Modified by: Nova Scheidt -- November 8, 2007
//      Modified by: Catherine Song -- October 27, 2010
//      Modified by: Catherine Song -- March 7, 2014
//		Modified by: Alex Clarke -- November 5, 2014
//--------------------------------------------------------------------



#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct DataType 
{
	string lastname;	// Student's Last Name
	string firstname;	// Student's First Name

	string getKey () const
	{ return lastname; }   // Returns the key field
};

//---------Need to add code to overload operator <<
ostream& operator<< (ostream& os, DataType& DT)
{
	os << DT.firstname << " " << DT.lastname;
	return os;
}

//------- Need to add code to fix error C2784: 'bool __cdecl std::operator <


bool Compar(const DataType& dt1, const DataType& dt2)
{
	if (dt1.getKey() < dt2.getKey())
		return true;
	else
		return false;
}

void main() 
{
	ifstream studentFile ("input.txt");  // Student file
	list <DataType> students;            // Students
	DataType currStudent;              // One Student (has firstname,lastname)

	// Read each line from input.txt:
	
		// Store the firstname and the lastname into 
		//   the temporary student structure "currStudent". 
	while (studentFile >> currStudent.firstname >> currStudent.lastname)
	{
		// Push the current student into the list ("students") 
		students.push_back(currStudent);
	}
	// Use an iterator to print the unsorted list of students.
		list<DataType>::iterator p = students.begin();
		while (p != students.end())
		{
			cout << *p << endl;
			p++;
		}
	// Sort the list of students.
	students.sort(Compar);

	// Use an iterator to print the sorted list of students.
	cout << "Sorted.........\n";
	p = students.begin();
	while (p != students.end())
	{
		cout << *p << endl;
		p++;
	}

	//Because return type of main function is void, we don't have to return. 
}

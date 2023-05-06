//Comparator Class in C++ with Examples

//https://www.geeksforgeeks.org/comparator-class-in-c-with-examples/

/*
class comparator_class {
public:
	// Comparator function
	bool operator()(object o1, object o2)
	{

		// There can be any condition
		// implemented as per the need
		// of the problem statement
		return (o1.data_member
				== o2.data_member);
	}
}
*/



//------------------------------------------------------------------------------
/*
Example 1: For implementing Linear Search on the array elements, searching an integer in a given array can be implemented easily. But searching any element on user defined data type can’t be implemented easily as in case of array. In this case, the comparator class is used to implement it. Below is the program for the same: 

// C++ program for the Comparator Class
// for implementing linear search
#include <bits/stdc++.h>
using namespace std;

// Generic function to search for object
template <class ForwardIterator, class T>
ForwardIterator search(
	ForwardIterator start,
	ForwardIterator end, T key)
{
	// Iterate until start equals to end
	while (start != end) {

		// If the value with given key is
		// found the return that index
		if (*start == key) {
			return start;
		}
		start++;
	}
	return end;
}

// Student Class
class student {
public:
	// To store Name and Roll Number
	string name;
	int rollnum;

	// Overloaded Constructor
	student(string name, int rollnum)
	{
		this->name = name;
		this->rollnum = rollnum;
	}
};

// Comparator Class to compare 2 objects
class studentcompare {
public:
	// Comparator function
	bool operator()(student a,
					student b)
	{
		// If values are the same then
		// return true
		if (a.name == b.name) {
			return true;
		}
		return false;
	}
};

// Driver Code
int main()
{
	// Object of class student
	student s1("Raj", 23);
	student s2("Prerna", 24);

	// List of students
	list<student> s;
	s.push_back(s1);
	s.push_back(s2);

	// Search student("Prerna", 24)
	student searchstudent("Prerna", 24);

	studentcompare cmp;

	// Print if element is found
	if (cmp(s2, searchstudent)) {
		cout << "Student found!";
	}
	else {
		cout << "Not found";
	}

	return 0;
}

*/



/*
Example 2:

Let us take another example of using Comparator class for sorting, suppose the task is to sort an array of objects based on its attributes value, then the idea is to create a custom comparator class in which the function on which the sorting has to be done can be mentioned. Then, it can be passed as an argument in sort() function.
*/

// C++ program for the Comparator Class
// implementing sorting

#include <bits/stdc++.h>
using namespace std;

// Student Class
class student {
public:
	// To store Name and Roll Number
	string name;
	int rollnum;

	// Overloaded Constructor
	student(string name, int rollnum)
	{
		this->name = name;
		this->rollnum = rollnum;
	}
};

// Comparator Class to compare 2 objects
class studentcompare {
public:
	// Comparator function
	bool operator()(const student& a,
					const student& b)
	{
		// Compare on basis of roll number
		if (a.rollnum < b.rollnum) {
			return true;
		}
		return false;
	}
};

// Driver Code
int main()
{
	// Object of class student
	student s1("Raj", 23);
	student s2("Prerna", 24);
	student s3("Harshit", 21);

	// List of students
	list<student> s;
	s.push_back(s1);
	s.push_back(s2);
	s.push_back(s3);

	// Creating object of
	// comparator class
	studentcompare cmp;

	// Passing the object of
	// comparator class to sort()
	s.sort(cmp);

	// Printing the list after sorting
	for (auto stu : s) {
		cout << stu.name << " ";
	}

	return 0;
}

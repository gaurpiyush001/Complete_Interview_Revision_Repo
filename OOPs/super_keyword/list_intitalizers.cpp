#include <bits/stdc++.h>
using namespace std;

//Initializers list is used to initialize data members

//NOTE**********
//In list intializers objects the intialized in same order in which they are declared in class OTHERWISE they will give error

//Two ways of doing this
//1. Using {}, this is uniform intialization ans should be prefferd --> this also checks the narrowing of data types and give compilation warning !!
//2. Using ()


//Konse variable constructor ke andar intialize nhi kr sktey --> const data members in a class, and reference data members in a class
//const data members in a class can only be intialized via list_intializers pattern


//----> where list_intilization is must, when we want to intialize
//1. Non static constant data member of our class from outside
//2. reference data members of our class from outside
//3. Initializing without default constructor from another class
//4. You want to intialize your base class data member from child class


// What happens if you don't call the base class constructor?
// If you don't explicitly call the base class constructor in the initializer list, the compiler will automatically call the default constructor of the base class (if it exists). However, if the base class doesn't have a default constructor or you need to pass specific arguments to the base class constructor, you'll get a compilation error.

// Key Points:
// The base class constructor is called before the derived class's member variables are initialized.
// You must use the initializer list to call a base class constructor if it requires arguments.
// The order of construction is base class first, then derived class.


class Base{
    char x;
public:
    Base(int a):x{a} {}
    void print(){
        cout << (int)x << " " << "jhv" << endl;
    }
};

int main()
{
    Base b(256);
    b.print();
    return 0;
}
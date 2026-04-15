#include <bits/stdc++.h>
using namespace std;

//Friend function and friend class in cpp

// NOTES:

//Friend keyword is mainly used to give the rights explicitly

// 1. Keyword "friend" is used to make some[function OR class] as friend of your class
// 2. Friend function OR friend class can access private/public/protected Data members or Data function of another class
// 3. Function can not become friend of another function.
// 4. Class can not become friend of function
// 5. Friedship is not mutual. if a class A is a friend of B, then B doesn't become friend of A autumoatically
// 6. Friendship is not inherited
// 7. Same friend function or class can belong to more than one class


//Why there comes a use of friend function ??
/*
Friend functions in C++ serve as a mechanism to allow functions external to a class to access its private and protected members. While encapsulation is a fundamental principle in object-oriented programming, there are situations where providing external functions or classes with direct access to private members can be beneficial. 

uses -> Access to Private Members, Non-Member Functions, Operator Overloading, Functionality Separation
*/


class Base {
    private:
    int x;
    public:
    // Base() {}
    Base(int a): x{a} {}
    //you have to make a function as friend inside our class
    friend void func(Base&, int);//in parameters we have to only define the types
    void printData(){
        cout << "mine " << this->x << endl;
    }
};

void func(Base& obj, int j){
    obj.x =  j;//here we are accessing private data member outside the class
}

int main()
{
    Base obj(10);
    obj.printData();
    func(obj, 20);
    obj.printData();
    return 0;
}

//REAL WORLD EXAMPLE OF FRIEND
//--> Suppose there are two entities Employee and Admin
//Then Although Employee will only have rights top access his username and details on portal.....BUT WE CAN ALSO make admin class as friend in Employee Class so that ADMIN has also right to access and right employee details 
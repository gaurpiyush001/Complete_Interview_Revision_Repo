#include <bits/stdc++.h>
using namespace std;

//What is a diamond problem in cpp?
// In C++, virtual inheritance is a concept used to address the "diamond problem,"(This helps prevent the "diamond problem" where ambiguities arise due to multiple paths to a common base class.) which occurs when a class inherits from two classes that have a common base class. This situation can lead to ambiguity in the inheritance hierarchy. Virtual inheritance is a mechanism that helps prevent problems associated with this ambiguity.

class A{ public: int _a; };

/*
class B:public A{ public: int _b; }; //B object's memory size will 4 + 4 = 8
class C:public A{ public: int _c; };
*/

//VIRTUAL INHERITANCE IS THE SOLUTINO
class B:virtual public A{ public: int _b; }; 
class C:virtual public A{ public: int _c; };
//By adding the virtual keyword when inheriting from A in classes B and C, you ensure that there is only one instance of the base class A in the hierarchy

class D: public B, public C{ public: int _d; };
// This creates two copies of A within the hierarchy, leading to ambiguity when accessing data through an object of class D.


int main()
{

    D d;//until this line it will NOT create any problem, happily compile hojayega
    d._a = 10;//At this line code compilation fails
    
    return 0;
}

//      A
//    /   \
//    B    C
//    \   /
//      D

// A object memory layout
// _a

// B object memory layout
// _a
// _b

// C object memory layout
// _a
// _c

// D object memory layout
// _a
// _b
// _a
// _c
// _d

//So when we access _a via class D object then ambiguity problem comes in, as which _a 
//we need to access


//HOW TO SOLVE THIS PROBLEM ??
//We need to access this _a virtually.
//WHAT IS VIRTUALLY ??
//When we write virtual, then the compiler will create Memory Layout with this D class object, then t won't create _a 2 times

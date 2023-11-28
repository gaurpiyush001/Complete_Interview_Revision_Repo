// Static Data members of classes in cpp
// Ans: They are atributes of classes OR class members or class fields

#include <iostream>
using namespace std;

class Base {
    public:
    //for x memory will be created automatically for each object creation
    int x;//there will be a distinct memory allocation of this data member for each BASE OBJECT

    //BUT for y we need to create memory outside the class 
    //below is just DECLARATION of y
    static int y;//this will be common for all the objects of class Base

    //BELOW IS A NON-STATIC method inside it we can access both static as well as non static data members
    void printX() {
        cout << x << endl;
    }

    //below static method can only access static data members ---> IMPORTANT
    //Static mamber functions are not inherited by subclasses. However, they can be accessed through the class name, even in subclasses.
    static void printY() {
        cout << y << endl;
    }
};

//memory creation outside of class
//BELOW is the Definition of Y(we have to do this for every static variable)
int Base::y;

int main()
{
    Base b1;
    b1.x = 10;
    b1.y = 30;
    //we can also access y as
    // Base::y = 30 

    Base b2;
    b2.x = 20;
    b2.y = 40;

    // cout << b1.x << endl;
    // cout << b2.x << endl;

    // //for static
    // cout << b1.y << endl;
    // cout << b2.y << endl;

    b1.printX();
    b1.printY();// also --> Base::printY();

    return 0;
}
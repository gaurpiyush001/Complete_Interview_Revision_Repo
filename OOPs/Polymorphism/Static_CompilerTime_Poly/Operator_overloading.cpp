//Operator Overloading is an Example of Compile time or Static Overloading

//NOTES-:
// 1. In cpp, it is possible to change the Behavior of operators, (+, -, *....)
// 2. But we can chnage the behaviou for User Deffined types(STRUCT, Class) only


#include <iostream>
using namespace std;

class Point{

    int x;
    int y;

    public:
    Point() {}
    Point(int x, int y): x{x}, y{y} {}
    //Operator Overloading syntax

    /*return-type*/Point operator+ (Point& rhs){
        Point p;
        p.x = this->x + rhs.x;
        p.y = this->y + rhs.y;
        return p;
    }

    void print(){
        cout << " x " << this->x << " y " << this->y << endl; 
    }

    //ALTERNATIVE FOR OPERATOR Overloading, we can define such user defined type manipulation of operations, user friendly funciton name
    Point add(Point& rhs){
        Point p;
        p.x = this->x + rhs.x;
        p.y = this->y + rhs.y;
        return p;
    }
    //There is a drawback for above function approach, let say you have a expression, now it will not look intuitive, and it won't look like
    // you are doing math operation, *******SO IN ORDER TO ACHIEVE THE INTUITIVE WAY OF SOLVING ANY EXPRESSION WE OVERLOAD THE OPERATORS*****
};


int main()
{
    //below addition operator will work only on implicit data types so compiler know how to execute addition between them
    int a = 10, b = 20;
    int c = a+b;
    cout << c << endl;

    //But, here If we add two Objects of our point class, Then Compiler will not be able to execute additino or any other amthematical operaiton, as they are USER-DEFINED-DATATYPE 
    Point P1(1,2), P2(3,4);

    Point P3 = P1 + P2;//when ever this + operation is used, thenP1 will call Overloaded "operator+" function and pass the second argument P2 in params  
    //Point P3 = P1.operator+(P2);(not actual syntax, just for explanation)
    P3.print();

    //NOW QUESTION COMES are you really supposed to do OPERATOR OVERLOADING in order to achieve addition of two user defined data-types ----> NOOO, we can also have functions like, add mul, divide etc.
    P1.add(P2).print();

    return 0;
}

//We cannot overload below operator
// 1. Dot Operator/Member access Operator ( . )
// 2. Scope Resolution Operator (::)
// 3. Ternary Operator ( ?: )
// 4. sizeof
// 5. typeid
// 6. .*

// because creator of cpp does'nt require any usage to overload these Operator  
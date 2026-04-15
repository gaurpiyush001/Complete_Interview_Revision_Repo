#include <iostream>
using namespace std;

// Overloading [] operator in C++ (Array Subscript Operator)

// POINTS:
// 1. Array Subscript Operator can be used to check out of bound cases
// 2. Array Subscript Operator can not be friend function and others too ( ->, (), = )

class Base{
    int arr[2]; // x->0, y->1
    public:
    Base(int x=0, int y=0){
        arr[0] = x;
        arr[1] = y;
    }

    void print(){
        cout << "x " << arr[0] << "y " << arr[1] <<endl;
    }

    //We will return here integer refernce, so that someone can change that using assigning it with some another value
    int& operator[] (int pos){
        if ( pos == 0 )
            return this->arr[0];
        else if(pos == 1)
            return this->arr[1];
        else{
            cout << "Out of bound case." << endl;
            exit(0);
        }
    }


};

int main()
{
    Base p1(3,4);
    p1.print();

    //We will overload  []  operator so that Base class Objects provide subscript operator to Objects
    p1[0] = 7;
    cout << p1[0] << " returned ref " << endl;
    p1[1] = 8;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//POINTS:
// 1. When we need overload << & >> ?
//  cout << (user defined type) OR cin >> (user defined type).
//istream and ostream classes have already overloaded methods for implicit data types(int, float).

//when we want to output or take input of a user-define-type 

// 2. It can't be class member function (Reason we will discuss), you have to make it friend function of your class

// cout is object od Ostream class
// cin is object of Istream class

//we are going to overload these operators, <<(Insertion) , >>(Extraction) not the objects cin and cout.

class Test{
    int x;
    int y;
    public:
    Test(int x = 0, int y = 0): x{x},y{y} {}

    //We need to make the overloaded operators as friend of class because we want to access private members of class
    friend istream& operator>>(istream&, Test&);
    friend ostream& operator<<(ostream&, Test&);

    //why did we make this overloaded functions outside the class in global scope??
    //because cout, cin are the object of Ostream,Istream class not your User-defined class and we are oveeloading the operators on cin and cout. You cannot make it as a class member function, as 
    //cin >> obj; --> is called as
    //operator>>(cin, obj)
    //while other operators oveloaded func are called as
    //obj1 = obj2 + obj3;
    //obj2.operator+(obj3)
};

istream& operator>> (istream& input, Test& t){
    input >> t.x >> t.y;
    //return input because to allow the same functionality of >>, as this return the LHS operand
    return input;
}
ostream& operator<< (ostream& output, Test& t){
    output << t.x << " " << t.y << " ";
    //return output because to allow the same functionality of <<, as this return the LHS operand  
    return output;
}


int main()
{
    Test t;

    // In below cin and cout objects we are giving operands as User-Defined-Datatype

    //For below lines to compile we need to Overload >>(Extraction) and  <<(Insertion) operators.
    cin >> t;
    cout << t << 5;  



    return 0;
}
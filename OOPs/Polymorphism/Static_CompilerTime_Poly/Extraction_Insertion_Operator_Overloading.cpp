#include <bits/stdc++.h>
using namespace std;

//POINTS:
// 1. When we need overload << & >> ?
//  cout << (user defined type) OR cin >> (user defined type).

//when we want to output or take input of a user-define-type 

// 2. It can't be class member function (Reason we will discuss), you have to make it friend function of your class

// cout is object od Ostream class
// cin is object of Istream class

//we are going to overload these operators, <<(Insertion) , >>(Extraction) not the objects cin and cout.

class Test{
    int x;
    public:
    Test(int x = 0): x{x} {}
};


int main()
{
    Test t;
    cin >> t;
    cout << t << endl;  
    return 0;
}
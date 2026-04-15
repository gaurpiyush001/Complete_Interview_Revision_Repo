#include <bits/stdc++.h>
using namespace std;

class Base{
    int _x;
    public:
    Base () { cout << "base default" << endl; }
    Base (int x) { _x = x; cout << "base param" << endl; }
    Base (const Base & obj) {
        this->_x = obj._x;
        cout << "base copy" << endl;
    }
    Base& operator = (const Base& obj) { cout << "base assign" << endl; }
};
class MyClass {
    Base _b;
    public: 
    MyClass() {
        cout << "myclass default" << endl;
    }
    MyClass(Base b) { _b = b; cout << "my class parameter" << endl; }
    //we can write above line as, to do op[timization with initializers]
    //MyClass(Base b): _b(b) { cout << "my class parameter" << endl; }
};
int main()
{
    Base b(10);
    MyClass mc(b);  
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


//OPERATOR OVERLOADING WORKS WITH (class/struct / Objects) MEANS USER-DEFINED DATA TYPE

//WE CANNOT CHANGE THE WORKING OF ANY OPERATOR WITH IMPLICIT DATA TYPE, LIKE INT , FLOATS

class Point {
    int x;
    int y;

    public:
    // Point() {}
    Point (int a=0, int b=0): x(a), y(b) {}

    void print() {
        cout << " x: " << x << " y: " << y << endl;
    }

    //Unary Operator Overloading
    Point operator- () {
        return Point(-this->x, -this->y);
    }

};

int main()
{
    Point p1(1, 2), P2;

    //assignment with negative value
    Point p3 = -p1;//this line is only working  beacause of operator overloading of "-"
    //can be seen as
    //p1.operator-()
    p3.print();
    return 0;
}
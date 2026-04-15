#include <bits/stdc++.h>
//importing classes declared in another cpp file
#include "exportingClasses.cpp"
using namespace std;

// Empty Class
class Hero
{

};

int
main()
{
    Hero h1;                    // Object Instantiated from Empty class

    Human ram;//exported class Human from exportingClasses.cpp file

    cout << sizeof(h1) << endl; //----> this will still have 1Byte of memory even if class is not having any property, for its identifation of the class

    return 0;
}
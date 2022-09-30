#include <bits/stdc++.h>
using namespace std;

//INHERITANCE -: Capability of a class to derive properties and behavior form anotehr class

//-------Objective -: here we will show how to inherit a class from another class, So female class will be INHERITED BY Human Class 

//Base class OR Super class OR Parent class
class Human { //-----------------WITHIN CLASS---------

    public:
    int age;
    char gender;
    string name;

};

//Female class is Child class or DERIVED class, It will be inhereted by specifying a MODE before Parent Class ---> total 9 combinations
class Female : public/*mode*/ Human{
//---------->DERIVED Class
};

int main(){
    //------------------------->OUTSIDE Class------
    // Human a;
    Female firstFemale;

    //All below properties or data members are inherited from the Human class, By below Garbage values will be printed as we have not intialised 
    cout << firstFemale.age << endl;
    cout << firstFemale.gender << endl;
    cout << firstFemale.name << endl;

    return 0;
}


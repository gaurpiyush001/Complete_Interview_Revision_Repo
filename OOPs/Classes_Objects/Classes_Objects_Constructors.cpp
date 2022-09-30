#include <iostream>
using namespace std;

// class creation -: Its is user-defined datatype, OR blueprint of object
// has properties(Data memebers/fields) and methods(Behaviour)
class Human
{
    // properties -> Data Members
public: // access modifier/specifier, private(by default), public, protected
//Public ke neechey jitney bhi Data memeber ya data Function hongey toh vo class ke ander bhi acces ho sktey hai aur class ke bahar kahi bhi

    char gender;
    int age;

    // behaviour

    /*
    1.) In C++, We can have more than one constructor in a class with same name, as long as each has a different list of arguments.This concept is known as Constructor Overloading
    2.) Overloaded constructors essentially have the same name (exact name of the class) and differ by number and type of arguments.
    */

    // constructor
    //NOTE++++IMP --> IF WE WRITE ANY ONE TYPE OF CUSTOM CONSTRUCTOR, then "Default-Constructor" provided by Compiler is automatically destroyed, (toh default constructor hume khud likhna pdega vrna ERROR ajayega) 
    Human()
    {
        cout << " I m in constructor " << endl;
        age = 1;
        gender = 'f';
    }

    // parameterised constructor
    Human(int age, char gender)
    {
        cout << "I m in P Constructor" << endl;
        this->age = age;
        this->gender = gender;
    }

    // copy constructor, reference nhi lgayengey toh infinite loop mein chlega copy constructor, pass by value mein toh copy bnti hai

    // Default Copy Constructor always do shallow copy --> IMP
    // SHALLOW COPY --> same hi memory ko aap access kr rahe ho 2 variable names se
    // DEEP COPY -> agar custom copy constructor mein krna hai toh vaha new array dynamically bnalo 

    Human(Human &temp)
    {
        cout << "I m in COPY COnstructor" << endl;
        this->age = temp.age;
        this->gender = temp.gender;
    }

    char getGender()
    {
        return gender;
    }

    void setGender(char ch)
    {
        gender = ch;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int a)
    {
        age = a;
    }

    ~Human()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{

    // object creation
    //  Human obj;
    //  cout << sizeof(obj) << endl ; --------------------------------->*IMP* Iska size 5 byte nhi hoga ---> 8 Byte hoga, bcz of padding and alignation

    // obj.age = 23;
    // //access
    // cout << obj.age << endl;

    // static way of creation of Object, In static, desctructor is automatically called after its scope ends
    Human ramesh;
    ramesh.age = 123;
    cout << ramesh.age << endl;

    // dynamic
    Human *suresh = new Human();
    cout << suresh->age << endl;

    // parameterised constructor
    Human *mukeshika = new Human(12, 'f');
    cout << mukeshika->gender << endl;

    // copy constructorr
    Human jignesh(ramesh);
    cout << jignesh.age << endl;

    delete suresh; // calling destructor manually for dynamic objects
    delete mukeshika;

    return 0;
};
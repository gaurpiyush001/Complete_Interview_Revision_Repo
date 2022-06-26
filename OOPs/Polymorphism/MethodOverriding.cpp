//Method Overriding, When we change or alter the implementation of any Inhereted Method in the child class, then its Method Overriding and this is Decided at RUNTIME, which function to call
//ex-: shape class(Parent class), having area method
//circle class, (child) hence can override area method with its formulae
// so with the rectangle and parallelogram classes


#include<iostream>
using namespace std;

class Animal
{

public:
    int age;

public:
    void speak()
    {
        cout << "Animal is Speaking" << endl;
    }
};

class Dog : public Animal
{
    //Method OVERRIDING
    public:
    void speak(){
        cout<< " Dog is Barking" << endl;
    }
};

int main() {

    Dog dog;
    dog.speak();

    return 0;
}


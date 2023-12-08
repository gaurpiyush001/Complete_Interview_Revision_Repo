//Abstraction ---> It is simply Implementation hiding, (hiding underlining details)
//---> Only showing Essentials Stuff
//ex-: ATM Machine, house wiring, email
//Advatage--: Security

//Access Modifiers are used to achieve ABSTRACTION

//Difference between Abstraction and Encapsulation??
//Diamond Problem??

// https://stackoverflow.com/questions/15176356/difference-between-encapsulation-and-abstraction


// How do we implement interface in cpp ?

// -> In cpp, there isn't a direct "Interface" keyword. However you can achieve a similar concept of interface using Abstract Classes which is having only PURE VIRTUAL METHODS, and it cannot be instantiated on its own. Instead, you must derive a concrete class from the abstract class and implement the pure virtual functions to create an instance.

//What is virtual function ?
// A Virtual Function is a function where we only declare the function but not the function definition. The implementation for pure virtual methods is done at the derived class by method/function overriding. 

// Rules While Using Interfaces
// - Declare only pure virtual functions. (No definition)
// - For pure virtual functions assign only 0.
// - Cannot create an instance of the class.
// - We can create a pointer to the instance of the derived class with a reference of a base abstract class.


/*
Abstract Class - Sometimes implementation of all functions cannot be provided in a base class because we don’t know the implementation. Such a class is called an abstract class
An abstract class is a class that is specially designed to be used as a base class. Abstract class must have at least one pure virtual function. It may have variables and normal functions. The derived classes of an abstract class must implement all the pure virtual functions of their base class or else they too become abstract.
*/

/*
Function overriding is a redefinition of the base class function in its derived class with the same signature i.e. return type and parameters.
But there may be situations when a programmer makes a mistake while overriding that function. So, to keep track of such an error, C++11 has come up with the override identifier.
Override identifier serves the following functions. It helps to check if: 
- There is a method with the same name in the parent class.
- The method in the parent class is declared as “virtual” which means it was intended to be rewritten.
- The method in the parent class has the same signature as the method in the subclass.
And if any of the above point violates, the compiler will show an error. 
*/

#include <iostream>

// Abstract class serving as an interface
class Interface {
public:
    // Pure virtual function
    virtual void doSomething() = 0;

    // Another pure virtual function
    virtual void doAnotherThing() = 0;

    // Virtual destructor (important for proper cleanup)
    virtual ~Interface() {}
};

// Concrete class implementing the interface
class ConcreteClass : public Interface {
public:
    // Implementation of the pure virtual function
    void doSomething() override {
        std::cout << "ConcreteClass is doing something." << std::endl;
    }

    // Implementation of another pure virtual function
    void doAnotherThing() override {
        std::cout << "ConcreteClass is doing another thing." << std::endl;
    }
};

int main() {
    // Create an instance of the concrete class
    Interface* obj = new ConcreteClass();
    ConcreteClass concreteObject;

    // Use the interface methods
    concreteObject.doSomething();
    concreteObject.doAnotherThing();

    obj->doSomething();

    return 0;
}


//https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/










// Why can't abstract class be instantiated?
// Lets assume you are tasked to build houses in a housing community. You have been given a fixed plot size and interior layout are meant to be same for all the houses. Hence you come up with an "abstract" or basic blueprint map which contains all the basic requirements, but it leaves some design elements for each specialize house (based on buyer's preferences), lets say one of then is the choice of roof. If you "instantiate" a house based on abstract blueprint, it will be missing an important functionality - the roof. Hence you need to "inherit" the abstract blueprint and provide missing "roof" design and come up with a new "concrete" map. Only then you will be able to instantiate a complete house based on a complete blueprint of that house.
// In C++, the virtual keyword is used in the context of object-oriented programming to declare a member function as "virtual." The virtual keyword is essential for achieving polymorphism, specifically runtime polymorphism

//When you declare a member funcino as 'virtual' in a base class, you're indicating that this function can be overidden in derived classes. This concept is fundamental to achieve dynamic dispatch, allowing the correct function to be called at runtime based on actual type of object being referenced.

//VIRTUAL keyword, enables polymorphic behaviour in cpp through inheritance and overriding

//---------------------IMPORTANT QUESTION--------------/
//CAN WE DO FUNCTION OVERRIDING in cpp WITHOUT VIRTUAL KEYWORD ???

// Without the virtual keyword, the function in the derived class does not actually override the function in the base class; instead, it hides it. This is known as function hiding or name hiding. When you have a function in a derived class with the same name as a function in the base class but without the virtual keyword, it doesn’t participate in dynamic dispatch or polymorphic behavior.

#include <iostream>

//In C++, when you use a pointer or reference to an abstract base class, you can only access members and functions that are declared in the base class itself or are declared as pure virtual functions in the base class and overridden in the derived class.

// When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the method.

// Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call.
// They are mainly used to achieve Runtime polymorphism.
// Functions are declared with a virtual keyword in a base class.
// The resolving of a function call is done at runtime.

// Rules for Virtual Functions
// The rules for the virtual functions in C++ are as follows ------ :
// Virtual functions cannot be static.
// A virtual function can be a friend function of another class.
// Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
// The prototype of virtual functions should be the same in the base as well as the derived class.
// They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
// A class may have a virtual destructor but it cannot have a virtual constructor.

// The idea is that virtual functions are called according to the type of the object instance pointed to or referenced, not according to the type of the pointer or reference.


// Base class
class Base {
public:
    // void show() {
    //     std::cout << "Inside Base::show()" << std::endl;
    // }
    void put() {
        std::cout << "Inside Base::put()" << std::endl;
    }
    virtual void show() = 0;
};

// Derived class
class Derived : public Base {
public:
    void show() {
        std::cout << "Inside Derived::show()" << std::endl;
    }
    void smack() {
        std::cout << "Inside Derived::smack()" << std::endl;
    }
};

int main() {
    // Base baseObj;
    Derived derivedObj;

    // baseObj.show();    // Output: Inside Base::show()
    derivedObj.show(); // Output: Inside Derived::show()

    // When using Base pointer to Derived object
    Base* ptr = &derivedObj;
    ptr->show(); // Output: Inside Base::show() - doesn't call Derived::show()

    Base* obj = new Derived();
    // obj->put();
    obj->show();
    obj->smack();

    return 0;
}

//Can Static Functions Be Virtual in C++?
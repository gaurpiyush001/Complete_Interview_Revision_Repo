// In C++, the virtual keyword is used in the context of object-oriented programming to declare a member function as "virtual." The virtual keyword is essential for achieving polymorphism, specifically runtime polymorphism

//When you declare a member funcino as 'virtual' in a base class, you're indicating that this function can be overidden in derived classes. This concept is fundamental to achieve dynamic dispatch, allowing the correct function to be called at runtime based on actual type of object being referenced.

//VIRTUAL keyword, enables polymorphic behaviour in cpp through inheritance and overriding

//---------------------IMPORTANT QUESTION--------------/
//CAN WE DO FUNCTION OVERRIDING in cpp WITHOUT VIRTUAL KEYWORD ???

// Without the virtual keyword, the function in the derived class does not actually override the function in the base class; instead, it hides it. This is known as function hiding or name hiding. When you have a function in a derived class with the same name as a function in the base class but without the virtual keyword, it doesn’t participate in dynamic dispatch or polymorphic behavior.

#include <iostream>

// Base class
class Base {
public:
    void show() {
        std::cout << "Inside Base::show()" << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    void show() {
        std::cout << "Inside Derived::show()" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    baseObj.show();    // Output: Inside Base::show()
    derivedObj.show(); // Output: Inside Derived::show()

    // When using Base pointer to Derived object
    Base* ptr = &derivedObj;
    ptr->show(); // Output: Inside Base::show() - doesn't call Derived::show()

    return 0;
}

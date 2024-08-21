// When you declare a member funcino as 'virtual' in a base class, you're indicating that this function can be overidden in derived classes. This concept is fundamental to achieve dynamic dispatch, allowing the correct function to be called at runtime based on actual type of object being referenced.

// meaning of this in cpp, explain with various unique examples and edge cases


// Base* basePtr = new Derived();, 
// here what is type of object, refernce to object  ?
// IMPORTANT
/*
In the statement Base* basePtr = new Derived();, we are dealing with pointers and polymorphism in C++. Here’s the breakdown:

Type of Object:

The actual object being created is of type Derived. This is the type of the object that exists in memory.
Reference to Object:

The pointer basePtr is of type Base*. This means that basePtr is a pointer to a Base object.
Despite basePtr being a Base* pointer, the object it points to is a Derived object. This is a classic example of polymorphism in C++, where a base class pointer (or reference) can point to a derived class object. Due to the virtual function mechanism, calls to virtual functions through basePtr will invoke the overridden functions in the Derived class, not the base class versions.
*/


//ANSWER - 
//In C++, declaring a member function as virtual in a base class allows derived classes to override this function. This is essential for dynamic dispatch, where the function that gets called is determined at runtime based on the actual type of the object, rather than the type of the reference or pointer to the object.

#include <iostream>

class Base {
public:
    virtual void display() const {
        std::cout << "Display from Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Display from Derived class" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->display(); // Output: Display from Derived class

    delete basePtr;
    return 0;
}


//-=------------------------------------------------------------------------------
#include <iostream>

class Base {
public:
    void display() const {
        std::cout << "Display from Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const {
        std::cout << "Display from Derived class" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->display(); // Output: Display from Base class

    delete basePtr;
    return 0;
}


//------------------------------------------
#include <iostream>

class Base {
public:
    virtual void display() const {
        std::cout << "Display from Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Display from Derived class" << std::endl;
    }
};

int main() {
    Derived derived;
    Base base = derived;
    base.display(); // Output: Display from Base class

    return 0;
}
// Explanation: This example demonstrates object slicing. When a Derived object is assigned to a Base object, the Derived part is "sliced off", and only the Base part remains. Thus, calling display() on the sliced object calls Base's version.
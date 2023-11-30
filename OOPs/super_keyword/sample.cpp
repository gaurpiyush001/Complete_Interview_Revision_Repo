#include <iostream>

class Base {
private:
    int basePrivateField;

protected:
    void setBasePrivateField(int value) {
        basePrivateField = value;
    }

public:
    Base(int value)  {
        setBasePrivateField(value);
    }

    void displayBasePrivateField() {
        std::cout << "Base private field: " << basePrivateField << std::endl;
    }
};

class Subclass : public Base {
private:
    int subclassPrivateField;

public:
    Subclass(int baseVal, int subclassVal)
        : Base(baseVal), subclassPrivateField(subclassVal) {
        setBasePrivateField(baseVal); // Indirectly set base class private field, ye line likhe bina bhi intialize hojayegi private value
    }

    void displayValues() {
        displayBasePrivateField(); // Accessing base class member function
        std::cout << "Subclass private field: " << subclassPrivateField << std::endl;
    }
};

//////////////another example
class Base1{
    int _x;
    public:
    Base1(int x): _x{x}{}
};
class Child: public Base1{
    int _y;
    public:
    /*
    Child(int x, int y) { //error: no matching function for call to 'Base1::Base1()'
        _x = x;
        _y = y;
    }
    */

   //we need to write Base(x) as a mark to super() reference
    Child(int x, int y): Base1(x) { 
        _y = y;
    }
};

class Base2{
    int x;
    public:
    Base2(int x){
       this->x = x; 
    }
};

int main() {
    // Subclass obj(42, 100);

    // obj.displayValues();
    // Child c(1,2);
    Base2 b2(1);

    return 0;
}

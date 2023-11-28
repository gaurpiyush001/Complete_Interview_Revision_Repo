#include <iostream>

class MyClass {
private:
    int myValue;

public:
    MyClass(int value) : myValue(value) {}

    void printUsingThis() {
        std::cout << "Using this->: " << this->myValue << std::endl;
    }

    void printUsingDot() {
        std::cout << "Using this.: " << this.myValue << std::endl;  // This line will not compile
    }
};

int main() {
    MyClass obj(42);
    obj.printUsingThis();  // Outputs: Using this->: 42

    return 0;
}

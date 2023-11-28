//Operator_overloading_with_friend_function
#include <iostream>

class MyClass {
private:
    int data;

public:
    MyClass(int value) : data(value) {}

    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
};

// Friend function for overloading the stream insertion operator
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << "MyClass data: " << obj.data;
    return os;
}

int main() {
    MyClass obj(42);
    std::cout << obj << std::endl;  // Uses the friend function

    return 0;
}

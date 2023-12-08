#include <iostream>
#include <vector>
#include <algorithm>

// Writing Custom Comparators by overloading comparison operators
//Let's consider a scenario where you have a custom object `CustomObject`, and you want to define a custom comparison logic for sorting instances of this class based on a specific criterion, such as the `value` member variable.

class CustomObject {
public:
    int value;

    // Constructor to initialize value
    CustomObject(int val) : value(val) {}

    // Overloading less than operator
    bool operator<(const CustomObject& other) const {
        return value < other.value; // Custom comparison logic
    }
};


int main() {
    std::vector<CustomObject> customObjects = { CustomObject(5), CustomObject(2), CustomObject(7), CustomObject(1), CustomObject(9) };

    // Sorting using the overloaded less than operator
    std::sort(customObjects.begin(), customObjects.end());

//When you use std::sort with a container of custom objects where the less-than (<) operator is overloaded, the sorting algorithm internally calls this overloaded operator to compare the objects and determine their order.

    // Displaying sorted customObjects
    for (const auto& obj : customObjects) {
        std::cout << obj.value << " ";
    }
    std::cout << std::endl;

    return 0;
}

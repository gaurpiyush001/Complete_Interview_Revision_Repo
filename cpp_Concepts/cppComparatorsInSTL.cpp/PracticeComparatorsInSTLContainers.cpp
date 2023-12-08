// How to pass the custom comparator along with class contructor call for custom object in conatiner
#include <iostream>
#include <set>

////////////////////////////NOTE***********////////////////////////////
//When ever in cpp we are using Userdefined data-type then the operatos while using on your user-defined datatype won't work,i.e they will not overloaded automatically. You have to define on your own overloaded operators iwth user user-defined datatypes.

// Define the CustomObject class
class CustomObject {
public:
    int value;

    // Constructor to initialize value
    CustomObject(int val) : value(val) {}

    // Overloading less than operator for sorting in descending order
    bool operator<(const CustomObject& other) const {
        return value > other.value; // Compare in descending order
    }
};

// Custom Comparator
struct CustomComparator {
    bool operator()(const CustomObject& a, const CustomObject& b) const {
        return a.value > b.value; // Compare in ascending order
    }
};

int main() {

    // Now here are 2 ways to do customcomparison logic
    //1. We have overloaded the comparison operator in our class which will result us in descending order
    //2. Other alternative is that we can pass CustomComparator Functor in tempate arguments while createing a set<T> variable

    //If we follow first way
    std::set<CustomObject> customSet;

    // I f we follow second way of using custom comparison logic with Our functor then,
    std::set<CustomObject, CustomComparator> customSet;

    // Inserting elements into the set using custom constructor and comparator
    customSet.emplace(5);
    customSet.emplace(2);
    customSet.emplace(7);
    customSet.emplace(1);
    customSet.emplace(9);

    // Displaying sorted customSet
    for (const auto& obj : customSet) {
        std::cout << obj.value << " ";
    }
    std::cout << std::endl;

    return 0;
}
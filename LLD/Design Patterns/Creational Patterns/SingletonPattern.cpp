//Singleton Pattern is a design pattern used to ensure that a class has only one instance and provides a global point of access to that instance.It invloves creating a class with a method that controls access to its sole instance and ensures that no other instance can be created

//Here's an example of a thread-safe Singleton pattern in C++ using the Double-Checked Locking:
#include <iostream>
using namespace std;


#include <iostream>
#include <mutex>

class Singleton {
private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Private copy constructor and assignment operator to prevent cloning
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    // Static instance of the Singleton class
    static Singleton* instance;
    
    // Mutex for thread safety
    static std::mutex mutex;

public:
    // Public method to access the Singleton instance
    static Singleton* getInstance() {
        // Check if the instance is null before acquiring the lock
        if (!instance) {
            std::lock_guard<std::mutex> lock(mutex); // Lock to ensure thread safety

            // Double-check if another thread has created the instance while waiting for the lock
            if (!instance) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    // Public method to perform some action
    void performAction() {
        std::cout << "Singleton is performing an action." << std::endl;
    }

    // Destructor to clean up resources
    ~Singleton() {
        delete instance;
    }
};

//The definition of the static member variable needs to be provided outside the class in the global scope. This is because the static member is shared among all instances of the class, and its memory needs to be allocated once and only once.
// Initializing the static instance to nullptr
Singleton* Singleton::instance = nullptr;

// Initializing the static mutex
std::mutex Singleton::mutex;

int main() {
    // Access the Singleton instance from multiple threads
    // ...

    return 0;
}












//Below is thread-Unsafe implementation
class Singleton {
private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Private copy constructor and assignment operator to prevent cloning
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    // Static instance of the Singleton class
    static Singleton* instance;

public:
    // Public method to access the Singleton instance
    static Singleton* getInstance() {
        if (!instance) {
            // If instance is not created, create one
            instance = new Singleton();
        }
        return instance;
    }

    // Public method to perform some action
    void performAction() {
        std::cout << "Singleton is performing an action." << std::endl;
    }

    // Destructor to clean up resources
    ~Singleton() {
        delete instance;
    }
};

// Initializing the static instance to nullptr
Singleton* Singleton::instance = nullptr;

int main() {
    // Access the Singleton instance
    Singleton* singletonInstance = Singleton::getInstance();

    // Perform some action using the Singleton instance
    singletonInstance->performAction();

    // Note: The instance will be automatically cleaned up when the program exits
    return 0;
}

int main()
{
    
    return 0;
}
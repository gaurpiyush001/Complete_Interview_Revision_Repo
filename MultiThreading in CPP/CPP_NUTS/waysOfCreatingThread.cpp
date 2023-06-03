// In this video we will learn about "Different Types Of Thread Creation And Calling" in this video i have explained 5 different types of creating threads and calling callable in threads.

//NOTE--: If we create ,multiple threads at the same time it does'nt guarantee which one will start first

// Five different types for creating threads.
// 1. Function Pointer -- this is the very basic form of creating threads.
// 2. Lambda Function
// 3. Functor (Function Object)
// 4. Non-static member function
// 5. Static member function

#include <iostream>
#include <thread>
using namespace std;

// 1. Function Pointer 
/*
void func(int x){
    while( x-- > 0) {
        cout << x << endl;
    }
}

int main(){
    std::thread t1(func, 11);
    t1.join();
    return 0;
}
*/


//2. Lambda Expression
/*
int main(){
    //We can directly inject lambda at thread creation time
    auto fun = [](int x){
         while(x-- > 0){
            cout << x <<endl;
         }
    };

    thread t(fun, 10);

    //we can also write, written lambda itself at thread creation time
    thread t4([](int x){
         while(x-- > 0){
            cout << x <<endl;
         }
    }, 10);


    t.join();
    t4.join();
    return 0;
}
*/


//2. Functors(fUNCTION oBJECT)
/*
class Base {
    public:
    //overloading this operator
    void operator ()(int x) {
        while(x-- > 0) {
            cout << x << endl;
        }
    }
};

int main() {
    std::thread t((Base()), 10);
    t.join();
    return 0;
}
*/


//4. Non-Static Member Function
/*
class Base{
    public:
        void run(int x){
            while(x-- > 0) {
                cout << x << endl;
            }
        }
};

int main(){
    Base b;
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
}
*/


//5. Static Member Function
class Base{
    public:
    static void run(int x){
        while(x-- > 0){
            cout << x <<endl;
        }
    }
};

int main(){
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}

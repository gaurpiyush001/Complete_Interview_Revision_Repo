// In this video we will learn about Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

// Mutex: Mutual Exclusion

// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.

#include<iostream>
#include<thread>
#include <mutex>
using namespace std;

int myAmount = 0;
std::mutex m;//there should be a mutex variable and that should be common for both the threads

void addMoney() {
    m.lock();//before accessing the critical region, we must lock the mutex 
    ++myAmount;
    m.unlock();//after completing , we should unlock it, so that if any thread is waiting(Busy Waiting) for this lock then it carry on its execution
}

int main() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    cout << "myAmount " << myAmount <<endl;
}
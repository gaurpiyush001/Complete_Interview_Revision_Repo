#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m1;
std::mutex m2;

// Solution for deadlock is that, You should'nt change the order of locking of common mutex in different threads

void thread1(){

    m1.lock();
    //this_thread::sleep_for(chrono::seconds(1)); -->just for illustration of deadlock
    m2.lock();//In this this thread is asking for another thread's locked mutex
    cout << "Critical Section Of Thread Thread One" <<endl;
    m1.unlock();
    m2.unlock();

}

void thread2(){

    m2.lock();
    // this_thread::sleep_for(chrono::seconds(1)); -->just for illustration of deadlock
    m1.lock();//In this this thread is asking for another thread's locked mutex
    cout << "Critical Section Of Thread Thread Two" <<endl;
    m2.unlock();
    m1.unlock();

}

int main(){
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}


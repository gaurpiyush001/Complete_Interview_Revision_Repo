// TOPIC: Condition Variable In C++ Threading(If we want to Synchronize our threads on some condition)

//Condition Variable allows running threads to wait on some conditions and once those conditions are met the waiting thread is notified

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition


//If some thread want to wait on some condition then it has to do these things -:
//	a. Acquire the mutex lock using 				std::unique_lock<mutex> lock(m)
//	b. Execute wait, wait_for, or wait_until. The wait operation automatically releases the mutex and suspend the execution of the thread
//	c. When the condition variable is notified, the thread is awakened and the mutex is automatically re-acquired(locked). The thread should then check the condition and resume waiting if the wake up was spurious(false wake)

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
	std::lock_guard<mutex> lg(m);
	balance += money;
	cout << "Available Balance " << balance << endl;
	cv.notify_one();//because there is only one distinct thread
}

void withdrawMoney(int money){

	std::unique_lock<mutex> ul(m);//It will wait here until mutex m is free from other thread
	cv.wait(ul, /*predicate or condition */[] { return (balance!=0) ? true : false; });//at this line, first lock is released then it gone for waiting
	//at on other condition, it will try to acquire the lock "m" if succeed then check the condition 
	if(balance >= money){
		balance -= money;
		cout << "Amount Deduced " << money << endl;
	}
	else{
		cout << "Below limit" << endl;
	}
	cout << "Cuurent Balance " << balance << endl;
}

int main() {
	std::thread t1(withdrawMoney, 100);
	std::thread t2(addMoney, 200);

	t1.join();
	t2.join();

	cout << balance << endl;
	return 0;
}


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int myAmount = 0;
std::mutex m;

void addMoney() {
	std::lock_gaurd<std::mutex> lock(m);
	++myAmount;
}

int main() {
	std::thread t1(addMoney);
	std::thread t2(addMoney);

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0;
}
// Few things to remember about the try_lock is as follows:
//SYNTAX : std::try+lock(m1, m2, m3, m4...., mn);

//Note-: actual use of this function is, it can "try to lock"(means If it is not able to lock then It won't wait there it will go ahead further)multiple Mutex Objects at the same time

// 0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.
// 1. On success(idf all mutex objects are locked) this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
// 3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int X = 0, Y = 0;
std::mutex m1, m2;

void doSomeWorkForSeconds(int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void incrementXY(int& XorY, std::mutex& m, const char* desc){
    for(int i = 0 ; i < 5; i++){
        m.lock();
            ++XorY;
        cout << desc << XorY < endl;
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY () {
	int useCount = 5;
	int XplusY = 0;
	while(1){
		int lockResult = std::try_lock(m1,m2);
		if(lockResult == -1){
			if(X!=0 && Y!=0){
				--useCount;
				XplusY+=X+Y;
				X = 0;
				Y = 0;
				cout << "XplusY " << XplusY << '\n';
			}
			m1.unlock();
			m2.unlock();
			if(useCount == 0) break;
		}
	}
}



int main() {
	std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
	std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");
	std::thread t3(consumeXY);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}
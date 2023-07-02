#include <iostream>
#include <thread>

using namespace std;

// void test(int x){
//     cout << "Hello from thread!!" << endl;
//     cout << "Argument passed in: " << x << endl;
// } 

// -----Converting above test function to lambda function

int main(){

    /*return type*/auto /*Any name*/lambda=[](int x){
        cout << "Hello from thread!!" << endl;
        cout << "Argument passed in: " << x << endl;
    };

    thread myThread(lambda, 100);

    //this join synchronizes two threads -> main and myThread
    myThread.join();//By joining a thread we fix a core dump

    cout << "Thread finished and joined" << endl;

    return 0;

}
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

//--->Iss code ko execute krke --> 3 thread bn jayengey(Main Thread, t1 thread, t2 thread)

//thread1 ---> Independent Task
void taskA()
{
    for(int i = 0 ; i < 10; i++){
        sleep(1);
        printf("TaskA: %d\n", i);
        fflush(stdout);
    }
}

//thread2 ---> Independent Task
void taskB()
{
    for(int i = 0 ; i < 10; i++){
        sleep(1);
        printf("TaskB: %d\n", i);
        fflush(stdout);
    }    
}

int main()
{
    //iss thread se konsa task krana hai
    thread t1(taskA);
    //another sub-process
    thread t2(taskB);

    //main thread hi exit kr jayegi --> termnated
    t1.join();//-->Main thread will ait till t1 is executed
    t2.join();//-->Main thread will ait till t1 is executed

    return 0;
}
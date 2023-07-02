#include <bits/stdc++.h>
using namespace std;

class ZeroEvenOdd {
private:
    
    int n;
    condition_variable cv;
    mutex m;
    int count;
    bool ev;
    int chance;

public:

    ZeroEvenOdd(int n) {
        this->n = n;
        count = 0;
        chance = 0;
    }


    // printNumber(x) outputs "x", where x is an integer.
    void zero() {

        for(int i = 0 ; i < n ; i++){

            unique_lock<mutex> ug(m);
            cv.wait( ug, [this]  { return chance==0?true:false; } );
            if(count!=0){
                if(ev){
                    chance = 1;
                }
                else{
                    chance = 2;
                }
                count++;
            }
            else{
                chance = 1;
                count++;
            }
            cout << 0 << endl;
            cv.notify_all();
            // ug.unlock();

        }

    }

    void even() {

        for(int i = 0 ; i < n/2 ; i++ ){

            unique_lock<mutex> ug(m);
            cv.wait( ug, [this] { return chance==2?true:false; } );
            // printNumber(count);
            cout << count << endl;
            chance = 0;
            // count++;
            ev = true;
            cv.notify_all();
            // ug.unlock();

        }

        
    }

    void odd() {
        
        //n is even
        if( (n&1)==0 ){
            for(int i = 0; i < n/2; i++){
                unique_lock<mutex> ug(m);
                cv.wait( ug, [this] { return  chance==1?true:false; } );
                // printNumber(count);
                cout << count << endl;
                chance = 0;
                // count++;
                ev = false;
                cv.notify_all();
                // ug.unlock();
            }
        }
        //n is odd
        else{
            for(int i = 0 ;  i < n/2+1; i++){
                unique_lock<mutex> ug(m);
                cv.wait( ug, [this] { return chance==1?true:false; } );
                // printNumber(count);
                cout << count << endl;
                chance = 0;
                // count++;
                ev = false;
                cv.notify_all();
                // ug.unlock();
            }
        }

    }
};

int main(){

    ZeroEvenOdd obj(5);

    thread t1(&ZeroEvenOdd::zero, &obj);
    thread t2(&ZeroEvenOdd::even, &obj);
    thread t3(&ZeroEvenOdd::odd, &obj);

    t1.join();
    t2.join();
    t3.join();

    return 0;

}
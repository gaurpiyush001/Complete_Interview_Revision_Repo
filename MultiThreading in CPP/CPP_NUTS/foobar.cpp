#include <bits/stdc++.h>
using namespace std;

class FooBar {
private:
    int n;
    mutex m1,m2;

public:
    FooBar(int n) {
        this->n = n;
    }


    void foo() {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            //thread A
        	lock(m1, m2);
            cout << "Foo";
            m2.unlock();
            m1.unlock();
        }
    }

    void bar() {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            //thread B
            lock(m2,m1);
        	cout << "bar" ;
            m1.unlock();
            m2.unlock();
        }
    }
};



int main()
{

    FooBar f(3);

    thread t1(&FooBar::foo, &f);
    thread t2(&FooBar::bar, &f);

    t1.join();
    t2.join();
    
    return 0;
}
//Multithreading is a feature that allows concurrent execution of two or more parts of a program for maximum utilization of the CPU.
//Each part of such a program is called a thread. So, threads are lightweight processes within a process.


/*
What is a Thread? 

A thread is a single sequence stream within a process. Because threads have some of the properties of processes, they are sometimes called lightweight processes. 

What are the differences between process and thread? 

Threads are not independent from each other unlike processes. As a result, threads shares with other threads their code section, data section and OS resources like open files and signals. But, like processes, a thread has its own program counter (PC), a register set, and a stack space. 


Why Multithreading? Threads are popular way to improve application through parallelism. For example, in a browser, multiple tabs can be different threads. MS word uses multiple threads, one thread to format the text, other thread to process inputs, etc. 

Threads operate faster than processes due to following reasons: 

1) Thread creation is much faster. 

2) Context switching between threads is much faster. 

3) Threads can be terminated easily 

4) Communication between threads is faster.
*/



/*
Multithreading support was introduced in C++11. Prior to C++11, we had to use POSIX threads or <pthreads> library. While this library did the job the lack of any standard language-provided feature set caused serious portability issues. C++ 11 did away with all that and gave us std::thread. The thread classes and related functions are defined in the <thread> header file.
*/

/*
std::thread is the thread class that represents a single thread in C++. To start a thread we simply need to create a new thread object and pass the executing code to be called (i.e, a callable object) into the constructor of the object. Once the object is created a new thread is launched which will execute the code specified in callable. A callable can be either of the three

--> A Function Pointer

void foo(param)
{
  Statements;
}
// The parameters to the function are put after the comma
std::thread thread_obj(foo, params);

--------------------------------------------------------------------------------------------------------------------------

--> A Function Object

// Define the class of function object
class fn_object_class {
	// Overload () operator
	void operator()(params)
	{
	Statements;
	}
}

// Create thread object
std::thread thread_object(fn_object_class(), params)

--------------------------------------------------------------------------------------------------------------------------

--> A Lambda Expression

// Define a lambda expression
auto f = [](params)
{
	Statements;
};

// Pass f and its parameters to thread
// object constructor as
std::thread thread_object(f, params);


*/


// C++ program to demonstrate
// multithreading using three
// different callables.
#include <iostream>
#include <thread>
using namespace std;

// A dummy function
void foo(int Z)
{
for (int i = 0; i < Z; i++)
{
	cout << "Thread using function"
			" pointer as callable\n";
}
}

// A callable object
class thread_obj {
public:
	void operator()(int x)
	{
	for (int i = 0; i < x; i++)
		cout << "Thread using function"
				" object as callable\n";
	}
};

// Driver code
int main()
{
cout << "Threads 1 and 2 and 3 "
		"operating independently" << endl;

// This thread is launched by using
// function pointer as callable
thread th1(foo, 3);

// This thread is launched by using
// function object as callable
thread th2(thread_obj(), 3);

// Define a Lambda Expression
auto f = [](int x)
{
	for (int i = 0; i < x; i++)
	cout << "Thread using lambda"
			" expression as callable\n";
};

// This thread is launched by using
// lambda expression as callable
thread th3(f, 3);

// Wait for the threads to finish
// Wait for thread t1 to finish
th1.join();

// Wait for thread t2 to finish
th2.join();

// Wait for thread t3 to finish
th3.join();

return 0;
}

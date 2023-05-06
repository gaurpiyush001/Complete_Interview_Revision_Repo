// https://www.geeksforgeeks.org/generics-in-c/

/*
Generics is the idea to allow type (Integer, String, … etc and user-defined types) to be a parameter to methods, classes and interfaces. For example, classes like an array, map, etc, which can be used using generics very efficiently. We can use them for any type.

The method of Generic Programming is implemented to increase the efficiency of the code. Generic Programming enables the programmer to write a general algorithm which will work with all data types. It eliminates the need to create different algorithms if the data type is an integer, string or a character.

The advantages of Generic Programming are

Code Reusability
Avoid Function Overloading
Once written it can be used for multiple times and cases.
Generics can be implemented in C++ using Templates.
*/

//https://www.geeksforgeeks.org/templates-in-c-vs-generics-in-java/

/* Writing Generic programs in C++ is called Templates.

One of the major features of the template in C++ is the usage of metaprogramming. It Let the template signature of the provided code be different, were C++ provides the ability to implement them.
Template arguments can be both classes and in functions.
C++ requires template sources to be added in their headers.
Template specialization could be achieved i.e, Specific type and method of template can be implemented.
*/

/*
Generics in Java

One of the major features of Java Generics is that It handles type checking during instantiation and generates byte-code equivalent to non-generic code.
The compiler of Java checks type before instantiation, that in turn makes the implementation of Generic type-safe. Meanwhile, in C++, templates know nothing about types.
If Generics is applied in a class, then it gets Applied to classes and methods within classes.
Another major factor that leads to the use of generics in Java is because it allows you to eliminate downcasts.
Instantiating a generic class has no runtime overhead over using an equivalent class that uses as specific object rather than a generic type of T.
*/



//Generic Functions using Template:
/*
#include <iostream>
using namespace std;
  
// One function works for all data types.
// This would work even for user defined types
// if operator '>' is overloaded
template <typename T>
  
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
  
int main()
{
  
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
  
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
  
    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;
  
    return 0;
}
*/



//Generic Classes using Templates
/*
#include <iostream>
using namespace std;
  
template <typename T>
class Array {
private:
    T* ptr;
    int size;
  
public:
    Array(T arr[], int s);
    void print();
};
  
template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
  
template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}
  
int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}
*/





//Working with Multi-type Generics
/*
#include <iostream>
using namespace std;
  
template <class T, class U>
class A {
    T x;
    U y;
  
public:
    A()
    {
        cout << "Constructor Called" << endl;
    }
};
  
int main()
{
    A<char, char> a;
    A<int, double> b;
    return 0;
}
*/
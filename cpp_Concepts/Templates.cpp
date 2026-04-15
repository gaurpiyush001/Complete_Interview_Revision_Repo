//https://www.geeksforgeeks.org/templates-cpp/

//A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter. 

//C++ adds two new keywords to support templates: ‘template’ and ‘type name’. The second keyword can always be replaced by the keyword ‘class’.

//How do Templates Work?
//Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type-checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class.



/*
What is the difference between function overloading and templates? 
Both function overloading and templates are examples of polymorphism features of OOP. Function overloading is used when multiple functions do quite similar (not identical) operations, templates are used when multiple functions do identical operations.
*/

/*
What happens when there is a static member in a template class/function? 
https://www.geeksforgeeks.org/templates-and-static-variables-in-c/
Each instance of a template contains its own static variable. See Templates and Static variables for more details.

What is template specialization? 
Template specialization allows us to have different codes for a particular data type. See Template Specialization for more details.
*/

/*
Can we pass non-type parameters to templates? 
We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. The important thing to note about non-type parameters is, that they must be const.


#include <iostream>
using namespace std;
 
template <class T, int max> int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
        if (arr[i] < m)
            m = arr[i];
 
    return m;
}
 
int main()
{
    int arr1[] = { 10, 20, 15, 12 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    char arr2[] = { 1, 2, 3 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    // Second template parameter
    // to arrMin must be a
    // constant
    cout << arrMin<int, 10000>(arr1, n1) << endl;
    cout << arrMin<char, 256>(arr2, n2);
   
    return 0;
}
*/




//--------------------------------------------------------------------------------------
//Template Specialization --> It is possible in C++ to get a special behavior for a particular data type. This is called template specialization. 


// A generic sort function
template <class T>
void sort(T arr[], int size)
{
    // code to implement Quick Sort
}
 
// Template Specialization: A function
// specialized for char data type
template <>
void sort<char>(char arr[], int size)
{
    // code to implement counting sort
}

//Note:  Apart from built-in data types like int, double, char etc, the template parameter ‘T’ can also be replaced by user defined data type.
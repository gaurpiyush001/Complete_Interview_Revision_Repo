#include <bits/stdc++.h>
using namespace std;

//Stack Class Implementation, Without STL

//Stack 2 tareeko se implemebt hoo jata hai -: Array and LinkedList

//Here we will Array Implementaion
class Stack{

    public:
    //Properties
        int top;//This will detect whether there is space left in stack or NOT
        int size;
        int *arr;

    
    //Constructor, intializing the size
    Stack(int size){
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
    }


    //functions or behavior

    //Push Operation, this will need an index so as to where to push
    //First we will check Is space availale in stack??? if yes then increase the top and place the element
    void push(int ele){
        if(top == size-1){
            cout<< "No space Availabel" << endl;
            return;
        }
        top++;
        arr[top] = ele;
    }


    //Pop Operation, 
    //iS ANY element present in stack
    //if false, print following error
    //if yes, then first remove element at current top , and decrease the top
    void pop(){
        if(top==-1){
            cout << "Stack Underflow" <<endl;
            return;
        }
        top--;
    }


    //EMPTY OPERATION, can be checkede by Top cariable value
    bool isEmpty(){
        if(top == -1)
        return true;
        else return false;
    }


    //Top operation
    int peak(){
        if(top == -1){
            cout<< " No element present " << endl;
            return -1;
        }
        return arr[top];
    }

};


int main()
{

    Stack st(5);

    st.push(5);
    st.push(10);
    st.push(15);

    cout << st.isEmpty() << endl;
    cout << st.peak() <<endl;/*
    st->pop();

    cout << st->peak() << endl;
    st->pop();
    */
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//Stack Class Implementation, Without STL

//Stack 2 tareeko se implemebt hoo jata hai -: Array and LinkedList

//Here we will LinkedList Implementaion
class Node{//for LinkedList

    public:
        int data;
        Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;  
    }

};


class Stack{

    public:
    //Properties
        //This will detect whether there is space left in stack or NOT
        // int size;
        Node *top;
        Node *start;


    
    //Constructor, intializing the size
    Stack(int data){

        top = new Node(data);
        start = top;
    }


    //functions or behavior
    void push(int ele){
        Node* curr = new Node(ele);
        top->next = curr;
        top = curr;

    }



    void pop(){
        //O(N);
        Node* temp = start;
        
        while(temp->next != top && temp!=top){
            temp = temp->next;
        }

        temp->next = NULL;
        delete top;
        top = temp;

    }


    //EMPTY OPERATION, can be checkede by Top cariable value
    bool isEmpty(){
        if(top == NULL)
        return true;
        else return false;
    }


    //Top operation
    int peak(){
        if(top == NULL){
            cout<< " No element present " << endl;
            return -1;
        }
        return top->data;
    }

};


int main()
{

    Stack *st = new Stack(50); 

    st->push(20);
    st->push(40);
    st->push(60);

    cout << st->peak() <<endl;
    st->pop();
    cout << st->isEmpty() <<endl;
    st->pop();
 cout << st->isEmpty() <<endl;
    cout << st->peak() <<endl;

    return 0;
}
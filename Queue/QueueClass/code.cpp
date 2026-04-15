#include<bits/stdc++.h>
using namespace std;

class Queue{

    public:
    int size;
    int front,rear;
    int *arr;

    Queue(int size){
        this->size = size;
        this->arr = new int[size];
        this->front = this->rear = -1;
    }

    void push(int data){

        if(this->rear == size-1){
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = data;
        if(front==-1)
            front++;
        // cout << "front " << front << "rear " << rear << endl;
    }

    void pop(){

        if(front>rear || front==-1){
            cout<<"Queue Underflow"<<endl;
            front=rear=-1;
            return;
        }
        // cout << "popped element " << arr[front] << " " << "front " << front << "||";
        front++;
        // cout << "after popped front " << front << endl;  
    }

    int peak(){

        if(front==-1){
            cout << "No data available" << endl;
            return -1;
        }

        return arr[front];

    }


};

int main(){

    int size;
    cin>>size;
    Queue q(size);


    while(1){
        int temp;
        cin>>temp;

        //temp=1 -> push
        if(temp==1){
            int data;
            cin>>data;
            q.push(data);
        }
        if(temp==2){
            q.pop();
        }
        if(temp==3){
            cout << q.peak() << endl;
        }
        if(temp==4)
            break;

    }


    return 0;

}

//LinkedList mein all operation of queue can be implemented in O(1) as well 
//but i Stack LinkedList POP operation of stack takes O(N) time



/*
Applications of Queue: 
Queue is used when things don’t have to be processed immediately, but have to be processed in First In First Out order like Breadth First Search. This property of Queue makes it also useful in following kind of scenarios.

When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling. 
When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.
*/
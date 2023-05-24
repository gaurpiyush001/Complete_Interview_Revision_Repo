class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        this->n = N;
        this->s = S;
        this->freespot = 0;
        
        this->arr = new int[s];
        this->top = new int[n];
        this->next = new int[s];
        
//         memset(top, -1, top+n);
    for(int i = 0; i < n;i++)
        top[i] = -1;
        
        for(int i = 0 ; i<s-1; i++)
        next[i] = i+1;
        
        next[s-1] = -1;
        
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        
        //checkOverflow
        if(freespot == -1){
            return false;
        }
        
        //find index, where to insert
        int index = freespot;

        //update freespot
        freespot = next[index];
        
        //insert element
        arr[index] = x;
        
        //now as array index is filled update next_array
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        
        //check underFlow
        if(top[m-1] == -1)
            return -1;
        
        //iski algo reverse chlegi push ke bilkul
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
            
    }
};
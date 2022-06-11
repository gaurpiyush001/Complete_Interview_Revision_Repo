// Initial template for C++

#include<bits/stdc++.h>
using namespace std;

//Similar problems --> Painters partition, Aggressive cows


bool isPossibleSolution(int A[], int N, int M, long long int low, long long int high, int mid){
    
    int part = 0;
    long long int sum = 0;
    for(int i = 0 ; i < N;i++){
        
        if(part < M){
        
        if( sum+A[i] <= mid ){
            sum += A[i];
        } else {
            sum = A[i];
            part++;
            if(part==M ||sum>mid){
                return false;
            }
        }
        
        } else {
            return false;
        }
        
    }
    
    return true;
    
}


int Solutionn(int A[], int N, int M, long long int low, long long int high){
    
    int answer = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(isPossibleSolution(A, N, M, low, high, mid)){
            answer = mid;
            high = mid - 1;
        } else {
            low = mid+1;
        }
    }
    // cout<<low<<" "<<high<<endl;
    return answer; 
    
}


class Solution 
{
    
    public:
    //Function to find minimum number of pages.
    

    int findPages(int A[], int N, int M) 
    {
        //code here
        
        long long int high = 0;
        high = accumulate(A, A+N, high);
        // cout<<high<<endl;
        long long int low = 0;
        return Solutionn(A, N, M, low, high);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
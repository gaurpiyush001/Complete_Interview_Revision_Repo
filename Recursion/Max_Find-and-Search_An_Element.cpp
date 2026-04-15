#include <bits/stdc++.h>
using namespace std;

//To find maximum elment in array by RECURSION
/*
int Solution(int arr[], int n){

    if(n == 0){
        return arr[n];
    }

    return max(arr[n],Solution(arr, n-1));
}*/

int Solution(int arr[], int k, int n){

    if(n<0){
        return -1;
    }
    if(arr[n]==k){
        return n;
    }

    return Solution(arr, k, n-1);

}

int main()
{
    int n , k;
    cin>>n>>k;

    int arr[n];
    for(int i = 0 ; i < n; i++)	{
        cin>>arr[i];
    }
    cout<<Solution(arr, k, --n)<<endl;
    return 0;
}
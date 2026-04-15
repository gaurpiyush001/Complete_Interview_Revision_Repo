#include <bits/stdc++.h>
using namespace std;

//link to question -: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
//chaar cases bn sktey hai
/*
smallest -> +k, largest -> +k -->largest-smallest
smallest -> -k, largest -> -k -->largest-smallest
smallest -> -k, largest -> +k -->largest-smallest+2k
smallest -> +k, largest -> -k (This approach will be the BEST TO DO and have minimum difference between smallest and laregst) i.e largest-smallest-2*k
*/


int MinDifference(int arr[], int n , int k){
    
    sort(arr, arr+n);
    int smallest, largest;

    int answer = arr[n-1]-arr[0];
    // cout<<"Prcomputed Answer"<<answer<<endl;
    for(int i = 1; i <n;i++){//i=1.. se start krna hai because a[0]-k kabhi nhi krna hai
        //if(arr[i]-k >= 0)//As given in Question, After modification height can't be NON-NEGATIVE
        if(arr[i] >= k) {
        smallest = min(arr[0]+k, arr[i]-k);//IMPORTANT
        largest = max(arr[n-1]-k, arr[i-1]+k);//IMPORTANT

        // cout<<"largest "<<largest<<" smallest "<<smallest<<"----->"<<largest-smallest<<"||"<<answer<<endl;

        answer = min(largest-smallest, answer);

        }
        // else{
            // cout<<"negative "<<arr[i]-k<<endl;
        // }
    }
    // cout<<maxii<<" "<<minii<<endl;
    // cout<<largest-smallest<<endl;
    return answer;

}

int main()
{
    int n, k;
    cin>>k>>n;

    int a[n];
    
    for(int i = 0 ; i < n; i++)	{
        cin>>a[i];
    }

    cout<<MinDifference(a, n, k)<<endl;

    return 0;
}
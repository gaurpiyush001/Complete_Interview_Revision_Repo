//------------------------important---------------------------

// https://practice.geeksforgeeks.org/problems/coin-piles5152/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Binary%20Search&sortBy=submissions#

// Abhi dry run krna hai

#include <bits/stdc++.h>
using namespace std;

//test CASE -> [2, 11, 13] & k = 3

//test case -> [1, 1, 1, 2, 5, 5] & k = 3
//explanation, a[0]+k = 4(find its upperBound by binary Search) ---> index = 4th index -> a[4] = 5
//find summation after index 4 till end and subtract with the expected summation, can be found by prefix Sum
//expected summation -> (no. of elements * A[i] + k)
//So number of coins to remove ->  ( prefix[N-1] - prefix[i-1] ) - ( no. of elements * (A[i] + k) )
//but there can be case when this above expresson results in     

int minCoinsFromPiles(int A[], int N, int K)
{
    // code here
    vector<int> p(N, 0); //----for Prefix Sum
    sort(A, A + N);

    p[0] = A[0];

    ///////////////////////calcculating prefix sum
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] + A[i];

    int ans = INT_MAX;
    int prev = 0;//this is important when we want to 
    for (int i = 0; i < N; i++)
    {
        int index = upper_bound(A + i, A + N, A[i] + K) - A;
        if (i > 0 && A[i] != A[i - 1])
        {
            prev = p[i - 1];
        }
        ans = min(ans, prev + p[N - 1] - p[index - 1] - (N - index) * (A[i] + K));
    }

    return ans;
}

int main()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0 ; i < n; i++)	{
        cin>>a[i];
    }
    cout<<minCoinsFromPiles( a,  n, k)<<endl;
    return 0;
}
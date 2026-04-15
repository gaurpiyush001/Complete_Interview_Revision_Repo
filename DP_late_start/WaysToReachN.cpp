// https://practice.geeksforgeeks.org/problems/ways-to-sum-to-n5759/1#
#include <bits/stdc++.h>
using namespace std;

// recursion
int solveRec(int arr[], int m, int N, int currentCoin)
{

    if (N == 0) // Zero Amount bnaney ke liye ek tareeka hai ki m koi select hi na kru coin
        return 1;

    if (N < 0) // Negative amaount toh bann hi nhi sakta, No Chance(no way)
        return 0;

    int final = 0;

    for (int i = currentCoin; i < m; i++)
    {

        final += solveRec(arr, m, N - arr[i], i);

        // int ans = 0;
        // ans = solveRec(arr, m, N - arr[i]);

        // if (final != 0 && ans != 0)
        //     final++;
        // else if (ans > 0)
        //     final = ans;
    }

    return final;
}

// By DP_Bottom_Up_Approach
int solveByDP(int arr[], int m, int N, vector<int> &dp)
{

    if (N == 0) // Zero Amount bnaney ke liye ek tareeka hai ki m koi select hi na kru coin
        return 1;

    if (N < 0) // Negative amaount toh bann hi nhi sakta, No Chance(no way)
        return 0;

    // DP RESERVED SOLUTION
    if (dp[N] != -1)
    {
        return dp[N];
    }

    long final = 0;

    for (int i = 0; i < m; i++)
    {

        final += solveByDP(arr, m, N - arr[i], dp);
        final = final % 1000000007;
    }

    dp[N] = (int) final;
    return dp[N];
}


int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    vector<int> dp(n+1, -1);
    cout<< solveRec(arr, m, n, 0) <<endl;
    cout << solveByDP(arr, m, n, dp) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/// Note Greedy aur Dynamic Programming mein difference clear krna ho toh refer to this question -->https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1# (Greedy Approach se Hora hai )

// But ye Question Greedy se nhi ho paayega !!!😑😑  -> https://practice.geeksforgeeks.org/problems/number-of-coins1824/1# (So below is the solution)

// 1.) Recursion Approach
int minNumberOfCoins(vector<int> coins, int V)
{

    if (V == 0)
        return 1;
    if (V < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {

        int ans = minNumberOfCoins(coins, V - coins[i]);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}


///////////////////////////////////Recursion+Memoization////////////////////////////////////////
int solveMem(vector<int> &coins, int n, vector<int> &dp)
{

    if (n == 0)
    {
        return 0;
    }

    else if (n < 0)
    {
        return INT_MAX;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {

        int ans = solveMem(coins, n - coins[i], dp);

        if (ans != INT_MAX)
        {
            mini = min(1 + ans, mini);
        }
    }

    dp[n] = mini;

    return mini;
}

int main()
{
    int n;
    cin >> n;

    vector<int> coins;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        coins.push_back(k);
    }
    vector<int> dp(n + 1, -1);
    // cout<<minNumberOfCoins(coins, n)<<endl;
    cout << solveMem(coins, n, dp) << endl;

    return 0;
}
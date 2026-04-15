#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861
// https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

// By recursion
int solveRec(int n)
{

    // Base case
    if (n == 1) // jb ek hi element 0 bacha hai , uske toh koi ways hi nhi derangement ki
        return 0;
    if (n == 2) //--> [0,1] can only be deranged as [1,0]
        return 1;

    // here n-1 is possible places to derange a single element, --> then (n-1) and (n-2) are subproblems
    int ans = (n - 1) * (solveRec(n - 2) + solveRec(n - 1));

    return ans;
}

// By Top-Down(rec+Memo)
long long int solveMem(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2) //--> [0,1] can only be deranged as [1,0]
        return 1;

    if (dp[n] != -1)
        return dp[n];

    long long int ans = (n - 1) % MOD * ((solveMem(n - 1, dp) % MOD) + (solveMem(n - 2, dp) % MOD));

    dp[n] = ans % MOD;
    return dp[n] % MOD;
}

// Tabulation, Bottom Up
int solveTab(int n)
{

    vector<long long int> v(n + 1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

// space Efiicient bhi hojayega --> prev1 aur prev2 leke
int spaceEff(int n)
{

    int prev1 = 0;
    int prev2 = 1;

    for (int i = 3; i <= n; i++)
    {

        int ans = (i - 1) + (prev1 + prev2);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solveRec(n) << endl;
    return 0;
}
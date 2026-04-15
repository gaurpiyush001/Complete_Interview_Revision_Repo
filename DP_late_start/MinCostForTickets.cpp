// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;

// Question kehta hai --> There is given an array which represents list of days, 1<=a[i]<=365

// Now this array contains days(a[i]) on which the traveller wants to travel, for travelling there are various PASSES(1DayPass, 7DayPass, 30DayPass) available for cost given in array of size 3

// Toh kya nikalluu??? --> Return the minimum number of Rupees you need to travel every day in the given list of days.

// Observation --> For Each coming day, I have three choices to consider the pass for it for travelling

// Recursive Approach
int solveRec(vector<int> &days, vector<int> &costs, int index, int n)
{

    // Base Case
    if (index >= n)
    {
        return 0;
    }

    // 1 dayPass
    int option1 = cosst[0] + solveRec(days, costs, index + 1, n);

    int i;
    // 7 dAY pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = costs[1] + solveRec(days, costs, i, n);

    // 30 dAY pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = costs[2] + solveRec(days, costs, i, n);

    return min(option1, min(option2, option3));
}
// cout << "mini inside for loop " << mini << endl;
// cout << "costindex inside for loop with index i" << costIndex << " " << i << endl;

//--------Recursion + Memoization
int solveMem(vector<int> &days, vector<int> &costs, int index, int n, vector<int> &dp)
{

    // Base Case
    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    // 1 dayPass
    int option1 = costs[0] + solveMem(days, costs, index + 1, n, dp);

    int i;
    // 7 dAY pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = costs[1] + solveMem(days, costs, i, n, dp);

    // 30 dAY pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = costs[2] + solveMem(days, costs, i, n, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

//---------------------Tabulation(Bottom Up Aprroach)-----------------------------------------
int solveTab(vector<int> &days, vector<int> &costs, int n)
{

    // Base Case
    //  if(index>=n){
    //      return 0;
    //  }

    // if(dp[index] != -1)
    // return dp[index];
    vector<int> dp(n + 1, INT_MAX);

    // by analyzing Base case
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int option1 = costs[0] + dp[k+1];

        int i;
        // 7 dAY pass
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int option2 = costs[1] + dp[i];

        // 30 dAY pass
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{

    int n = days.size();
    // return solveRec(days, costs, 0 /*days index*/, n);

    // Memoization
    //  vector<int> dp(n+1, -1);
    //  return solveMem(days, costs, 0 /*days index*/, n, dp);

    // Tabulation
    return solveTab(days, costs/*days index*/, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cost(3);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> cost[i];
    }

    cout << mincostTickets(v, cost) << endl;
    return 0;
}
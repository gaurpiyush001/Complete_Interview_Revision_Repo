#include <bits/stdc++.h>
using namespace std;

// koi bhi number select krney ki 2 choice hongi --: "Include" or "Exclude"

// if going for left to right
// for Include --> i+2, and current sum + current ele
// for Exclude --> i+1, and current sum + 0(we are excluding so sum remains as it is)

// If going for right to left
// for Include --> i-2, and current sum + current ele
// for Exclude --> i-1, and current sum + 0(we are excluding so sum remains as it is)

// ---------------------------------------------------right to left APPROACH--------------------------------------

// through simple recursion
int solveRec(vector<int> v, int n)
{

    if (n < 0)
        return 0;
    if (n == 0)
        return v[0];

    int inc = solveRec(v, n - 2) + v[n];
    int exc = solveRec(v, n - 1);

    return max(inc, exc);
}

//dp[n] is here showing---> maximum sum that we can obtain when we are at index n

// through recursion + memoization(Top down Approach) ---> step1)DP creation , step2)store Intermediate results, step3)return result if already memoized----------------top-down approach, TC->O(N)+O(N), SC->O(N)
int solveMem(vector<int> v, int n, vector<int> &dp)
{

    if (n < 0)
        return 0;
    if (n == 0)
        return v[0];

    // step3.
    if (dp[n] != -1)
        return dp[n];

    int inc = solveMem(v, n - 2, dp) + v[n];
    int exc = solveMem(v, n - 1, dp);

    dp[n] = max(inc, exc);
    return dp[n];
}

//through tabulation Approach(bottom up) ----> step1)create dp array,  Step2)Analyze the base case and accordingly intialize the array, step3)find relation between subproblem, TC->O(N), SC->O(N)
int solveTab(vector<int> v, int n){
    vector<int> dp(n, 0);
    dp[0] =  v[0];

    for(n = 1; n<v.size(); n++){
        int a;
        if((n-2) < 0)
            a = 0;
        else
            a = dp[n-2];
        int b;
        if((n-1) < 0)
            b = 0;
        else
            b = dp[n-1];
        int inc = a + v[n];
        int exc = b + 0;

        dp[n] = max(inc, exc);
    }

    return dp[n-1];

}

//by space optimization and TC->O(N), SC->O(1), ------->dp[i] is dependent on i-2 and i-1 toh normal variables leke prev1 aur prev2 leke kr sktey hai
int spaceEff(vector<int> v, int n){

    int prev1 = v[0];
    int prev2 = 0;//kynki base case mein less than zero index ke liye ans 0 hai

    for(int i = 1; i<n; i++){
        int inc = prev2 + v[i];
        int exc = prev1 + 0;

        prev2 = prev1;
        prev1 = max(inc, exc);        

    }

    return prev1;

}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // cout << solveRec(v, n - 1) << endl;

    /* vector<int> dp(n, -1);
     cout << solveMem(v, n - 1, dp) << endl; */

    // cout<< solveTab(v, n) <<endl;

    cout<< spaceEff(v, n) <<endl;
    return 0;
}
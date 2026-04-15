// https://practice.geeksforgeeks.org/problems/dice-throw5349/1

// for explanation refer register

long long solve(int dice, int faces, int target)
{

    if (target < 0)
    {             // jb target hi less than zero hojayega toh NO WAYS
        return 0; // 0 ways
    }
    if (target != 0 && dice == 0)
    {             // dice merepe bacha nhi but target bnana hai, NO WAYS
        return 0; // 0 ways
    }
    if (target == 0 && dice != 0)
    {             // target 0 hi bna huya hai, but dice mere pe pdey hai, NO WAYS bcz face zero tyope ka hota hi nhi
        return 0; // 0 ways
    }
    if (dice == 0 && target == 0)
    {             // mujhe bnana bhi zero hai aur mere pe dice bhi nhi hai
        return 1; // One possible way, bs
    }

    // On the current Dice utilize all its faces
    long long ans = 0;
    for (int faceDig = 1; faceDig <= faces; faceDig++)
    {
        ans = ans + solve(dice - 1, faces, target - faceDig);
    }

    return ans;
}

// By memoization ---> dice aur target 2 things are changing so its 2-D DP
long long solveMem(int dice, int faces, int target, vector<vector<long long>> &dp)
{

    if (target < 0)
    {             // jb target hi less than zero hojayega toh NO WAYS
        return 0; // 0 ways
    }
    if (target != 0 && dice == 0)
    {             // dice merepe bacha nhi but target bnana hai, NO WAYS
        return 0; // 0 ways
    }
    if (target == 0 && dice != 0)
    {             // target 0 hi bna huya hai, but dice mere pe pdey hai, NO WAYS bcz face zero tyope ka hota hi nhi
        return 0; // 0 ways
    }
    if (dice == 0 && target == 0)
    {             // mujhe bnana bhi zero hai aur mere pe dice bhi nhi hai
        return 1; // One possible way, bs
    }

    if (dp[dice][target] != -1)
    {
        return dp[dice][target];
    }

    // On the current Dice utilize all its faces
    long long ans = 0;
    for (int faceDig = 1; faceDig <= faces; faceDig++)
    {
        ans = ans + solveMem(dice - 1, faces, target - faceDig, dp);
    }

    return dp[dice][target] = ans;
}

// solveTab ----------------------> IMPORTANT IMPORTANT   ---> T.C -> O(N*M*X)
long long solveTab(int d, int faces, int t)
{
    vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));
    // analyzing Base Case
    dp[0][0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {

            long long ans = 0;
            for (int faceDig = 1; faceDig <= faces; faceDig++)
            {
                if (target - faceDig >= 0)
                    ans = ans + dp[dice - 1][target - faceDig];
            }

            dp[dice][target] = ans;
        }
    }

    return dp[d][t]; // kyunki starting meikn humney call kri thi M aur N ke liye
}

//Space Optimized ----> O(X) and T.C--> O(M*N*X)
long long solveSO(int d, int faces, int t)
{
    // vector<vector<long long>> dp(d+1, vector<long long>(t+1, 0) );
    vector<long long> prev(t + 1, 0);
    vector<long long> curr(t + 1, 0);
    // analyzing Base Case
    //  dp[0][0] = 1;

    prev[0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {

        for (int target = 1; target <= t; target++)
        {

            long long ans = 0;
            for (int faceDig = 1; faceDig <= faces; faceDig++)
            {
                if (target - faceDig >= 0)
                    ans = ans + prev[target - faceDig];
            }

            curr[target] = ans;
        }

        prev = curr;
    }

    return prev[t]; // kyunki starting meikn humney call kri thi M aur N ke liye
}

long long noOfWays(int M, int N, int X)
{
    // by Reciursion
    return solve(N, M, X);

    // solveByMem
    //  dice aur target 2 things are changing so its 2-D DP
    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
    return solveMem(N, M, X, dp);

    // by Tabulation
    return solveTab(N, M, X);
}

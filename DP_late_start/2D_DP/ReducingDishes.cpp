// https://leetcode.com/problems/reducing-dishes/

// intuition ke liye Register dekho

int solveByRec(vector<int> satisfaction, int index, int time, int n)
{

    if (index >= n)
    { // array se bahar aagye return 0, no more thing to add in result
        return 0;
    }

    int include = satisfaction[index] * time + solveByRec(satisfaction, index + 1, time + 1, n);

    int exclude = 0 + solveByRec(satisfaction, index + 1, time, n);

    return max(include, exclude);
}

//----> Memoization ---> Top Down
int solveMem(vector<int> &satisfaction, int index, int time, int n, vector<vector<int>> &dp)
{

    if (index >= n)
    { // array se bahar aagye return 0, no more thing to add in result
        return 0;
    }

    if (dp[index][time] != -1)
    {
        return dp[index][time];
    }

    int include = satisfaction[index] * time + solveMem(satisfaction, index + 1, time + 1, n, dp);

    int exclude = 0 + solveMem(satisfaction, index + 1, time, n, dp);

    return dp[index][time] = max(include, exclude);
}

// Tabulation ---> Bottom Approach
int solveTab(vector<int> &satisfaction)
{

    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; i++)//time maximum us index se hi toh start hoga
        {
            //jaha bhi recursive cal hai usse replace krdo DP se
            int include = satisfaction[index] * (time+1) + dp[index+1][time+1];

            int exclude = 0 + dp[index+1][time];

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}

//space optimization ---> O(N)
int solveSO(vector<int> &satisfaction)
{

    int n = satisfaction.size();
    // vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
    vector<int> curr(n+1);
    vector<int> next(n+1,0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)//time maximum us index se hi toh start hoga
        {
            //jaha bhi recursive cal hai usse replace krdo DP se
            int include = satisfaction[index] * (time+1) + next[time+1];

            int exclude = 0 + next[time];

            curr[time] = max(include, exclude);
        }

        next = curr;

    }

    return next[0];
}


int maxSatisfaction(vector<int> &satisfaction)
{

    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    // return solveByRec(satisfaction, 0, 1, n);

    // for memoization
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return solveMem(satisfaction, 0, 1, n, dp);

    //for Tabulation
    return solveTab(satisfaction);
}

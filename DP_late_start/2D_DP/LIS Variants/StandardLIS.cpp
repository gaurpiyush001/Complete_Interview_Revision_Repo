// https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// https://leetcode.com/problems/russian-doll-envelopes/

// Intuition

// 1.) Brute Force by recursion just pick a number(Only when arr[prev] < arr[curr]) and the other time leave it, The case in which we are getting Longest Increasing Subsequence save it into a variable

// exponential time complexity
int solveByRec(vector<int> nums, int currIndex, int lastIndex)
{

    // base case
    if (currIndex == nums.size())
    {
        return 0;
    }

    int include = 0;
    if (lastIndex == -1 || nums[currIndex] > nums[lastIndex])
    {
        include = 1 + solveByRec(nums, currIndex + 1, currIndex); // just add 1 to the length of increasing subsequence and call recursion
    }

    int exclude = 0 + solveByRec(nums, currIndex + 1, lastIndex);

    // jo maximum hai vo return krdo
    return max(include, exclude);
}

// it has overlapping subproblems and optimal subproblems
int solveMem(vector<int> &nums, int currIndex, int lastIndex, vector<vector<int>> &dp)
{

    // base case
    if (currIndex == nums.size())
    {
        return 0;
    }

    if (dp[currIndex][lastIndex + 1] != -1)
    {
        return dp[currIndex][lastIndex + 1];
    }

    int include = 0;
    if (lastIndex == -1 || nums[currIndex] > nums[lastIndex])
    {
        include = 1 + solveByRec(nums, currIndex + 1, currIndex); // just add 1 to the length of increasing subsequence and call recursion
    }

    int exclude = 0 + solveByRec(nums, currIndex + 1, lastIndex);

    // jo maximum hai vo return krdo
    return dp[currIndex][lastIndex + 1] = max(include, exclude);
}

// Tabulation
int solveTab(vector<int> &nums)
{

    // base case & intializing dp
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int currIndex = n - 1; currIndex >= 0; currIndex--)
    {
        for (int lastIndex = currIndex-1; lastIndex >= -1; lastIndex--)
        {

            int include = 0;
            if (lastIndex == -1 || nums[currIndex] > nums[lastIndex])
            {
                include = 1 + dp[currIndex + 1][currIndex + 1]; // kyunki definition yehi kehti hai ki prevIndex is 1 less than currIndex,  just add 1 to the length of increasing subsequence 
            }

            int exclude = 0 + dp[currIndex + 1][lastIndex+1];

            dp[currIndex][lastIndex+1] = include > exclude ? include : exclude;
        }
    }

    // jo maximum hai vo return krdo
    return dp[0][-1+1];
}

//Space Optimization possible hai yaha...Becasue current row sirf Next Row pr hi depend kr rhi hai!!!
//T.C --> O(N^2)
//S.C --> O(N)
int solveSO(vector<int> &nums)
{

    // base case & intializing dp
    int n = nums.size();
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for (int currIndex = n - 1; currIndex >= 0; currIndex--)
    {
        for (int lastIndex = currIndex-1; lastIndex >= -1; lastIndex--)
        {

            long long int include = 0;
            if (lastIndex == -1 || nums[currIndex] > nums[lastIndex])
            {
                include = 1 + next[currIndex + 1]; // kyunki definition yehi kehti hai ki prevIndex is 1 less than currIndex,  just add 1 to the length of increasing subsequence 
            }

            int exclude = 0 + next[lastIndex+1];

            curr[lastIndex+1] = include > exclude ? include : exclude;
        }

        next = curr;

    }

    // jo maximum hai vo return krdo
    return next[0];
}

// -------------------------------------------Aaj ki Duniya yehi hai || So Upgrade Yourself ------------------------------------------
//most efficient Approach -------------------DP + bINARY sEARCH
int solveOptimal(vector<int>& nums){

    int n = nums.size();
    if(n==0)//length zero toh LIS bhi Zero hoga
        return 0;
    
    vector<int> ans;//answer ka array ---> yaha asnwer store bhi kr raha hai na tu ---> this is DP(overlapping subproblems)

    //Humesha pehle wala element toh hoga hi hoga "ans" mein
    ans.push_back(nums[0]);

    for(int i = 1 ; i < n; i++){
        if(nums[i] > ans.back()){//last element se bada hai curretn element
            ans.push_back(nums[i]);
        }
        else{
            // Find Index of Jusstt bada element
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

            //jusst bdey se replace krdo
            ans[index] = nums[i];

        }
    }

    return ans.size();

}


int lengthOfLIS(vector<int> &nums)
{
    // return solveByRec(nums, 0, -1);

    //by Memoization
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveMem(nums, 0, -1, dp);

    //solveTab(nums)
}
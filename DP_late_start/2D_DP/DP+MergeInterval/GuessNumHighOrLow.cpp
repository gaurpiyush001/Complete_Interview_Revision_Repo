// -- >originl question
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/submissions/

 //This is not an optimization proble, Actually It is a planning problem such that I have to take minimum among the worst cases that are possible
    //line14 -->  i+max(solve(start, i-1), solve(i+1, end)) ---->  this expression is giving me worst scenario money given for guessing each number     
    
    int solve(int start, int end){
        
        if(start >= end)
            return 0;
        
        int maxi = INT_MAX;
        for(int i = start; i <= end; i++){
            maxi = min(maxi, i+max(solve(start, i-1), solve(i+1, end)));
        }
        
        return maxi;
        
    }
    
    int solveMem(int start, int end, vector<vector<int>>& dp){
        
        if(start >= end)
            return 0;
        
        if(dp[start][end] != -1)
                return dp[start][end];
        
        int maxi = INT_MAX;
        for(int i = start; i <= end; i++){
            maxi = min(maxi, i+max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
        }
        
        return dp[start][end] = maxi;
        
    }

    //Just ulta krna hai Topdown ka
    int solveTab(int n){

        vector<vector<int,int>> dp(n+1, vector<int> (n+2, 0));

//Note ab start n se 1 tk jayega 
        for(int start = n; start >= 1; start--){

            for(int end = start; end<=n; end++) {

                if(start == end)//base case
                continue;
                else{
                    
                    int maxi = INT_MAX;
                    for(int i = start; i <= end; i++){
                        maxi = min(maxi, i+max(dp[start][i-1], dp[i+1][end]));
                    }
        
                    dp[start][end] = maxi;

                }

            }

        }

        return dp[1][n];


    }
    
    int getMoneyAmount(int n) {
        // return solve(1, n);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(1, n, dp);

        return solveTab(n);
    }
};


//Follow Up question

//https://leetcode.com/problems/can-i-win/
//https://leetcode.com/problems/find-k-closest-elements/
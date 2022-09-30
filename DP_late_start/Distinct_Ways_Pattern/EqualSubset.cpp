//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
    bool solve(int n, int index, int arr[], int target){
        
        //base case mjaa ayega
        if( index == n || target < 0 ){
            return false;
        }
        if( target == 0 ){
            return true;
        }
        
        bool incl = false;
        incl = solve(n, index+1, arr, target - arr[index]);
        bool excl = incl || solve(n, index+1, arr, target);
        
        return (incl || excl);
        
    }
    
    bool solveMem(int n, int index, int arr[], int target, vector<vector<int>>& dp){
        
        if( index == n || target < 0 ){
            return false;
        }
        if( target == 0 ){
            return true;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        bool incl = false;
        incl = solveMem(n, index+1, arr, target - arr[index], dp);
        bool excl = incl || solveMem(n, index+1, arr, target, dp);
        
        return dp[index][target] = (incl || excl);        
        
    }
    
    bool solveTab(int n, int arr[], int target){
        
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false) );
        
        //here I will go from 0th index to N
        //and 0 to target value
        for(int i = 0 ; i <= n; i++){
            dp[i][0] = true;
        }
        
        for(int i = n-1; i >= 0; i--){
            
            for(int t = 0; t <= target; t++){
 
                bool incl = false;
                if(t-arr[i] >= 0)
                incl = dp[i+1][t - arr[i]];
                bool excl = dp[i+1][t];
        
                dp[i][t] = incl || excl;                   
                
            }
            
        }
        
        return dp[0][target];
        
        
    }


    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum = 0;
        for(int i = 0 ; i < N; i++){
            totalSum += arr[i];
        }
        
        if( (totalSum&1) == 1 ){//If totalSum is Odd, then We can't make subset
            return 0;
        }
        
        int target = totalSum >> 1;
        
        // return solve(N, 0, arr, target);
        // vector<vector<int>> dp(N, vector<int>(target+1, -1) );
        // return solveMem(N, 0, arr, target, dp);
        
        return solveTab(N, arr, target);
        
    }
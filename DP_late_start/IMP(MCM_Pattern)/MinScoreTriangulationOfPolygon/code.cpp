//SMaller version of question -> Ways of Polygon Triangulation Dynamic Programming | Explained with Code
//link -> 


// jaao question padho -: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

// Bhai question kya kehta haii??? --> Notes mein sb smjahdiya hai

    //Recursion
    int solveRec(vector<int>& values, int i, int j){
        
        //Base Case
        if(i+1==j){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int k = i+1; k<=j-1; k++){
            ans = min(ans, values[i]*values[j]*values[k] + solveRec(values,i,k) + solveRec(values, k, j));
        }
        
        return ans;
    }
    
    //By Memoization
    int solveMemo(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        //Base Case
        if(i+1==j){
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i+1; k<=j-1; k++){
            ans = min(ans, values[i]*values[j]*values[k] + solveMemo(values,i,k,dp) + solveMemo(values, k, j, dp));
        }//Two recursive calls in loop, so T.C would be O(N^3) 
        
        dp[i][j] = ans;
        return dp[i][j]; 
    }

//Tabulation is your home work

// Home Work


//Space Optimization bhi Home work
    
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();
        
        //by Recursion
        // return solveRec(values, 0, values.size()-1);
        
        //By Memoization
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solveMemo(values, 0, n-1, dp);
        
        
    }
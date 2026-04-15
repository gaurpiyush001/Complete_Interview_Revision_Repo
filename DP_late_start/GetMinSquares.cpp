#include <bits/stdc++.h>
using namespace std;

int solveRec(int n){

    if(n==0){
        return 0;
    }

    int ans = n;//kisi max answer se intialize krdiya, poora sum 1 se bna hai
    for(int i = 1; i*i <= n; i++){
        
        int temp = i*i;
        
        ans = min(ans, 1+solveRec(n-temp));

    }
    return ans;

}


int solveMem(int n, vector<int> &memo)
{
    if (n == 0)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int ans = n;
    for (int i = 1; i <= sqrt(n); i++)//ye loop hr target value ke liye chll raha h
    {
        int tempAns = 1 + solve(n - (i * i), memo);

        ans = min(ans, tempAns);
    }

    memo[n] = ans;
    return memo[n];
}


//Tabulation
int solveTab(int n){

    //intialize dp
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    // ans[1] = 1;

//aisa kyun kra 
    for(int i = 1; i <= n; i++ ){//ye "i" mujhe target value represent krta hai, jiske liye mujhe minimum solution nikalna hai
        for(int j = 1 ; j*j <= n; j++){///ye loop hr target value ke liye chll raha h
            int temp = j*j;
            if(i-temp>=0)
            dp[i] = min(dp[i], 1+dp[i-temp]);
        }
    }
    
    return dp[n];

}

//Space Optimization, nhi hopayega (NOT POSSIBLE)
//exact pattern nazar nhi aara, yaha aisa nhi hai koi ek elmeent pheechey ke kuch FIX "n" elements pr depend nhi kr raha vary hori hai dependabilities


int MinSquares(int n)
{   
    //recursive sol
    // return solverec(n, memo);

    //Memoization Approach
    // vector<int> memo(n + 1, -1);
    // return solveMem(n, memo);

    return solveTab(n);
}

int main()
{

    int n;
    cin >> n;
    Solution ob;
    int ans = MinSquares(n);
    cout << ans << "\n";

    return 0;
} // } Driver Code Ends
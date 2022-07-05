//DP kyun lgi isme ---> iSS VAJAH SE kyunki, for ex-:  agar mere pe 3 item bache hai aur mere lets say k capacity backi hai toh mein unn 3 items mein se EXCLUDE aur INCLUDE krke kya MAXIMUM PROPFIT unki values se kma skta hun

//SOLUTION 1.
//-------------------------------Recursion + Memoization (TOP-DOWN)---------------------------------------
#include <bits/stdc++.h>
using namespace std;


int solveMem(vector<vector<int>> &dp, int wieght[], int value[], int index, int W)
{
    //base condition if only one element is left in the bag, 
    //Top down mein base case as it is rhega jaise recursion mein hota hai
    if (index == 0)
    {

        if (wieght[index] <= W)
        {
            return value[index];
        }
        else
            return 0;
    }

    //we will check in our DP table if we already solved the problem where we have ith items available and jth Capacity left in our bag
    if (dp[index][W] != -1)
    {
        return dp[index][W];
    }

    int include = 0;
    if (wieght[index] <= W)
        include = value[index] + solveMem(dp, wieght, value, index - 1, W - wieght[index]);

    int exclude = solveMem(dp, wieght, value, index - 1, W);

    dp[index][W] = max(exclude, include);
    return dp[index][W];
}



//SOLTUION 2.
//---------------------------(Tabulation) BOTTOM-UP------------------------------------------

int solveTab(int wieght[], int value[], int n, int W){

    //step1. Intialize and declrae the DP array/Table
    // int n = index+1;
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    
    //Fill the intial values in dp by analyzing BASE CASES
    
    //ye konsa base case--: Agar, capacity hi zero hojaaye 
    for(int i = 0; i < n; i++){
       dp[i][0] = 0;
    }

    //hum yaha first item ke wieght se shuru kr rahe hai loop upto total capacity, BUT BHAI COLOUMN TOH HUMARE ZERO SE START HOJAYENGEY , toh zero se kyun nhi liya
    // mujhe yaha pehla item dekhna tha (i.e first row) aur uske hi wieght pe focus hai mera, utni hi knapsack capacity ke bag se start krna hai fill krna 
    for(int j = wieght[0]; j <= W; j++){

        /*if( wieght[0] <= j ){
            dp[0][j] = value[0];
        }
        else dp[0][j] = 0;*/
        //above if condition ka koi fayeda thodi hai, it can be written as below
        dp[0][j] = value[0];

    }


    for(int i = 1; i < n; i++){
        for(int j = 0; j <= W; j++){
            
            int include = 0;

            if (wieght[i] <= j)
                include = value[i] + dp[i - 1][j - wieght[i]];

            int exclude = dp[i - 1][j];
            dp[i][j] = max(include,exclude);
        
        }
    }

    return dp[n-1][W];

}



//----------Solution3...........(SPACE OPTIMIZATION)

//isme mujhe dependency check krni hoti hai mera dp kispr depend krra hai

//Toh mein dhyaan se dekho toh mera particular row uske phichhli row pe hi sirf depend krri hai, So 2 array bnakey(previous aur current) kaam hojayega
int spaceOptimized(int wieght[], int value[], int n, int W){

    vector<int> prev(W+1, 0);
    vector<int> curr(W+1, 0);

    for(int j = wieght[0]; j <= W; j++){
        prev[j] = value[0]; 
    }

    

    for(int i = 1 ; i< n ;i++){//ye loop ayega kyunki matrix ki hr 2 row mein jaakey update krni hai value
    for(int j = 0; j <= W ; j++){
            
            int include = 0;
            // int val = value[i];

            if (wieght[i] <= j)
                include = value[i] + prev[j - wieght[i]];

            int exclude = prev[j];
            curr[j] = max(include,exclude);

            //swap to krlo
            // prev = curr;
            // curr.assign(curr.size(), 0);
            // i++;

        }
    prev = curr;
    }

    return prev[W];

}


//Solution 4.. more Space Optimized with --> O(N)
//mera curr[j] previous solution mein 2 cheezo pr dependent tha prev[w] and prev[w -weight[index]]....So there is a scope that i can make it SC--:O(N)

//Trick ye thi ki after intialization of array firstly, I can see if curr[w] on exclusion results in curr[w]
// and on inclusion it results in curr[w-weight[i]], so my dependency is lying in left part of array, So dont construct the array from Left to right as thier might be data overriding issues, Construct iut from right to left
int spaceOptimizedN(int wieght[], int value[], int n, int W){

    // vector<int> prev(W+1, 0);
    vector<int> curr(W+1, 0);

    for(int j = wieght[0]; j <= W; j++){
     curr[j] = value[0]; 
    }

    

    for(int i = 1 ; i< n ;i++){//ye loop ayega kyunki matrix ki hr 2 row mein jaakey update krni hai value
    for(int j = W; j >= 0 ; j--){
            
            int include = 0;
            // int val = value[i];

            if (wieght[i] <= j){
                include = value[i] + curr[j - wieght[i]];
            // cout<<curr[j - wieght[i]]<<endl;
            }

            int exclude = curr[j];
            curr[j] = max(include,exclude);

            //swap to krlo
            // prev = curr;
            // curr.assign(curr.size(), 0);
            // i++;

        }
    // prev = curr;
    }

    return curr[W];

}




int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here

    // each block "dp[i][j]" (with value!=-1) in this below DP matrix will depict, the optimal solution of picking among i items with j capacity left int the knapsack

    //why "N" and why "W+1" ???
    //from 0 to n-1 there are total n items which can be easily stored in matrix with n rows
    //from 0 to W capactiy, we need to have W+1 coloumns, otherwise we will miss the processing of data for "W" wieght  

    // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // return solveMem(dp, wt, val, n - 1, W);
    // return solveTab(wt, val, n, W);
    // return spaceOptimized(wt, val, n, W);
    return spaceOptimizedN(wt, val, n, W);

}



// { Driver Code Starts.

int main()
{

    int n, w; // items and capacity
    cin >> n >> w;

    int val[n];
    int wt[n];

    // inserting the values
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // inserting the weights
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    // calling method knapSack()
    cout << knapSack(w, wt, val, n) << endl;

    return 0;
}
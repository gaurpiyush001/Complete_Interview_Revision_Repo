#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

// By simple recursive approach
int solveRec(int n, int x, int y, int z)
{

    if (n == 0)
    { // agar already rod ki length zero hai, to usse kittey segment mein divide kr skta hun ---> zeroooooo
        return 0;
    }
    if (n < 0)
        return INT_MIN;

    // if choosing X
    int first = solveRec(n - x, x, y, z); // dekho recursive calls mein ek hi variable change hora hai, hence 1-D DP se kaam hojayega
    // if choosing Y
    int second = solveRec(n - y, x, y, z);
    // if choosing Z
    int third = solveRec(n - z, x, y, z);

    // Ye kyun likhha ->>> iss tesat case ke 8 3 3 3, jab koi segment mein hum divide hi nhi kr payengey
    if (first == INT_MIN && second == first && third == first)
        return INT_MIN;

    int ans = max(first, second);

    return max(ans, third) + 1; //"+1" isliye kr raha hun so as to count the current segment, into which rod is broken
}


//------------------------------------- By recursion + memoization (TOP-DOWN APPROACH) ---------------------------------
int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    { // agar already rod ki length zero hai, to usse kittey segment mein divide kr skta hun ---> zeroooooo
        return 0;
    }
    if (n < 0)
        return INT_MIN;

    // step 3, return reserved solution of subproblems
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int first = solveMem(n - x, x, y, z, dp); // dekho recursive calls mein ek hi variable change hora hai, hence 1-D DP se kaam hojayega
    int second = solveMem(n - y, x, y, z, dp);
    int third = solveMem(n - z, x, y, z, dp);

    if (first == INT_MIN && second == first && third == first)
    {
        dp[n] = INT_MIN;
        return INT_MIN;
    }

    // step4), storing overlapping subproblems result
    dp[n] = max(first, max(second, third)) + 1;
    return dp[n];
}


//----------------------------------------------------Bottom Up(Tabulation)----------------------------
int solveTab(int n, int x, int y, int z)
{

    vector<int> dp(n+1, INT_MIN);//this dp[n] array tells maximum segment possible each which X,Y,Z length to break a rod of length "n" 
    int i;
    dp[0] = 0;//intialize dp array by intializing base cases

    for(i = 1; i<=n; i++){
        if(i-x >= 0){
            dp[i] = max(dp[i],dp[i-x]+1);
        }
        if(i-y >= 0){
            dp[i] = max(dp[i],dp[i-y]+1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i],dp[i-z]+1);
        }
    }

    return dp[n];
}


///Space optimization----------nhi ho skta because humey isme x, y ,z ki value nhi pta hai...toh isko prev1 prev2, prev3 ki form m nhi laa sktey


int main()
{
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    // int ans = solveRec(n, x, y, z);

    vector<int> dp(n + 1, -1); // step 1)
    // int ans = solveMem(n, x, y, z, dp);

    int ans = solveTab(n, x ,y, z);
    ans <= INT_MIN ? cout << 0 << endl : cout << ans << endl;
    // cout<<solveRec(n, x, y, z)<<endl;
    return 0;
}
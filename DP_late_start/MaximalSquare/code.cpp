// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
#include <bits/stdc++.h>
using namespace std;

//Kaise hogya ye recursion ??? ---> I know isme hum (i,j) cell ke liye nikaal ke laarey hai recursion se uske diagonal , right, aur down cells ek square form kr rhey hai ya nhi --->Aur Isme overlapping subproblems Bhaarr bharrr ke hai , because for a particular cell we might be evaulating some other cell which has been evaluated prior

int solveRec(vector<vector<int>>& mat, int i , int j, int& maxi)
{

    //Base case
    if( i >= mat.size() || j >= mat[0].size() )//Boundaries se bahar na chla jaaye
    return 0;

    //If we start from (0,0)  ---> it can go for expansion RIGHT, DOWN, DIAGONAL
    //so, for a particular cell to expand, to larger square

    int right = solveRec(mat, i, j+1, maxi);

    int down = solveRec(mat, i+1, j, maxi);
    int diagonal = solveRec(mat, i+1, j+1, maxi);


    if(mat[i][j] == 1){//Mein jispe khada hun uspe toh dekhlo, If that is ZERO then mein aagey kyun hi processing kru!!

        //ek cell ke liye hume kayi(mtlb 3 different values milengi , usse humme minimum hi mikalna hoga vo hi perfect square hoga which contains all ones)
        int ans = 1 + min(right, min(diagonal, down));//1+ isliye kyunki mein jiss cell pe khada hun(and that conatins value 1) uske liye  toh mujhe +1 krna pdega 

        maxi = max(maxi, ans);//because now I have to tell maximum size square that i met

        return ans;

    }
    else{
        return 0;
    }

}


//---> Memoization
int solveMemo(vector<vector<int>>& mat, int i , int j, int& maxi, vector<vector<int>>& dp){

    //Base case
    if( i >= mat.size() || j >= mat[0].size() )//Boundaries se bahar na chla jaaye
    return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //If we start from (0,0)  ---> it can go for expansion RIGHT, DOWN, DIAGONAL
    //so, for a particular cell to expand, to larger square

    int right = solveMemo(mat, i, j+1, maxi, dp);

    int down = solveMemo(mat, i+1, j, maxi, dp);

    int diagonal = solveMemo(mat, i+1, j+1, maxi, dp);


    if(mat[i][j] == 1){//Mein jispe khada hun uspe toh dekhlo, If that is ZERO then mein aagey kyun hi processing kru!!

        //ek cell ke liye hume kayi(mtlb 3 different values milengi , usse humme minimum hi mikalna hoga vo hi perfect square hoga which contains all ones)
        int ans = 1 + min(right, min(diagonal, down));//1+ isliye kyunki mein jiss cell pe khada hun(and that conatins value 1) uske liye  toh mujhe +1 krna pdega 

        maxi = max(maxi, ans);//because now I have to tell maximum size square that i met

        dp[i][j] = ans;

    }
    else{
        dp[i][j] = 0;
    }

    return dp[i][j];

}


//-----------Tabulation
int solveTab(vector<vector<int>>& mat, int &maxi){

    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

    //base conditions se intialize krdo dp matricx ko

    for(int i = row-1; i >= 0; i--){

        for(int j = col-1; j>=0 ; j--){

 int right =  dp[i][j+1];

    int down = dp[i+1][j];

    int diagonal = dp[i+1][j+1];// maxi, dp);


    if(mat[i][j] == 1){


        dp[i][j] = 1 + min(right, min(diagonal, down));

        maxi = max(maxi, dp[i][j]);

    }
    else{
        dp[i][j] = 0;
    }

        }

    }

        return dp[0][0];// kuch bhi return kro fark nhi padta kyunki answer toh maxi mein hai 

}


//Space Optimization is Possible, space complexity will be -: O(no.Of.Coloumns)
//T.C-: O(n*m)
int solveSO(vector<vector<int>>& mat, int &maxi){

    int row = mat.size();
    int col = mat[0].size();

    vector<int> next(col+1, 0);

    //base conditions se intialize krdo dp matricx ko

    for(int i = row-1; i >= 0; i--){

    vector<int> curr(col+1, 0);
        for(int j = col-1; j>=0 ; j--){

 int right =  curr[j+1];

    int down = next[j];

    int diagonal = next[j+1];// maxi, dp);


    if(mat[i][j] == 1){


        curr[j] = 1 + min(right, min(diagonal, down));

        maxi = max(maxi, curr[j]);

    }
    else{
        curr[j] = 0;
    }

        }

        next = curr;
        // curr = {0};

    }

        return next[0];// kuch bhi return kro fark nhi padta kyunki answer toh maxi mein hai 

}


//----------------NOTE-------------------
//Isko O(m) ki jagah isko O(1) ke ander bhi solve kr skta hun


int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // code here
    /*
    int maxi = 0;
    solveRec(mat, 0, 0, maxi);
    return maxi;
    */

    //Memoization
    /*
    int maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m,-1));
    solveMemo(mat, 0 ,0 , maxi, dp);
    return maxi;
    */

   int maxi = 0;
   solveTab(mat, maxi);

   return maxi;

}

//

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n * m; i++)
        cin >> mat[i / m][i % m];

    // Solution ob;
    cout << maxSquare(n, m, mat) << "\n";
    return 0;
}
// } Driver Code Ends
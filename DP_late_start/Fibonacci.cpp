#include <bits/stdc++.h>
using namespace std;

//------------------------------------------SOLUTION I-----------------------------------------
//By Top Down Approach  ---> Recursion + Memoization ---> T.C --> O(k) and SC ---> O(k)
/*
int top_Down_Approach(vector<int>& v, int k){

    if(k==1 || k==0){
        return k;
    }

    if(v[k]!=-1)//Checking If we already solved this Overlapping Subproblem, If yes then return its Answer
        return v[k];

    v[k] = top_Down_Approach(v, k-1) + top_Down_Approach(v, k-2);//store subproblem result in DP array

    return v[k];

}
*/


//------------------------------------------------------SOLUTION II ---------------------------------------------------------
//By Bootom Up ---> Tabulation   -> TC --> O(k) ---> SC --> O(K)
/*
int bottom_Up_Approach(vector<int> &v, int k){

    // step1) Create a DP Array
    //-> Already created

    // step2) Analyze Base Case and Store initial values that we get from base case into DP array
    v[0] = 0;
    v[1] = 1;

    //step3) Run a loop till nth term and process Further results by DP stored values
    for(int i = 2; i <= k; i++){
        //Relation which we have to analyze from the given question to get result from Overlapping Subproblems 
        v[i] = v[i-1] + v[i-2];
    }

    return v[k];
}
*/


//------------------------------------------------SOLUTION III------------------------------------------------------------
//By Space Optimization, naam se hi pta chlra hai jo DP mein space lere hai vo bhi Optimize krni hai
//TC --> O(k), SC --> O(1) 
int space_Optimization(int k){

    //step 1) Analyze the problem find relation to find solution by smaller subproblem
    //isme current number pheechey ke 2 number ke sum se bnta hai
    int prev1 = 1;//v[i-1]
    int prev2 = 0;//v[i-2]
    int curr;//v[i]

    if(k==0){
        return prev2;
    }

    for(int i = 2; i<=k; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;

}



int main()
{
    int k;
    cin>>k;

    // this below space is only used in First two Solutions
    // vector<int> v(k+1,-1);  
    
    // cout<<top_Down_Approach(v, k)<<endl;
    // cout<<bottom_Up_Approach(v, k)<<endl;
    cout<<space_Optimization(k)<<endl;

    return 0;
}
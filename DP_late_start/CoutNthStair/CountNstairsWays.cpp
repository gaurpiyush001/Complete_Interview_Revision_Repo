#define MOD 1000000007;
#include <bits/stdc++.h>
using namespace std;

//Pending Question ----------------------------->> https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1#
//Similar Question ----------------------------->> min Cost Climbing Stairs

/*
recursive code -----> T.C -> O(2^N), S.C -> O(N)
int solve(int n, int i){

    if(n==i)    return 1;

    if(i > n)   return 0;

    return (solve(n, i+1) + solve(n, i+2))%MOD;

}
*/

///////////////////////////////////DP Solution////////////////////////////
//1.) Top Down Approach, recursion + Memoization...........T.C->O(N), as overlapping subproblems solution will be stored , SC->O(N)
int solve2(int n, vector<int>& v){

	if(n==1)
	return 2;
	if(n==0)
	return 1;
	if(n<0)
	return 0;

	//return if already solved
	if(v[n]!=-1)
		return v[n];

	v[n] = solve2(n-1, v) + solve2(n-2, v);

	return v[n];

}




//2.) Bottom-up Approach, by step1. creating dp array, step2. analyzing base case and accordingly intializing values, step3. rum a loop till last
    int solve3(int n){    
		vector<int> v(n, -1);
        v[0] = 1;//pehli seedhi pr toh ek hi tareeka hai aaney ka
        //But doosri seedhi ke 2 tareekey hai
        v[1] = 2;
        for(int i = 2; i<n; i++){
            // int x = v[i-1];
            // int y = 0;
            
            // if(i-2 >= 0)
            // y = v[i-2];
            
            // v[i] = (x+y)%1000000007;
            v[i] = (v[i-1]+v[i-2])%1000000007;
        }
        
        return v[n-1];
	}



//3.) Space Optimized approach......o(N) ->T.c and O(1) -> S.C
///////note--> mera answer harr iteration mein last ke previous 2 hi variables pe depend krr raha hai
	int solve4(int n){
	    int prev2 = 1;
	    int prev1 = 2;
	    int curr;
	    if(n==1)
	    return prev2;
	    for(int i = 3; i <= n; i++){
	        curr = (prev1+prev2)%1000000007;
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    
	    return prev1%1000000007;
	    
	}




int main()
{
    int n;
    cin>>n;
	vector<int> v(n, -1);

    // cout<<solve(n)<<endl;//recursion
	//Top-Down
	cout<<solve2(n-1, v)<<endl;
    return 0;
}

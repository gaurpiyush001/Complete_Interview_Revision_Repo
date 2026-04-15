#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/count-even-length1907/1/#

	#define MOD 1000000007 
	int solveRec(int total, int i, int sum){
	    
	    if(i>=total){
	        if(sum==0)
	        return 1;
	        else
	        return 0;
	    }
	    
	    int res;
	    if(i<total/2)
	    res = sum+1;
	    else
	    res = sum-1;
	    int ans1 = (solveRec(total, i+1, sum+0)%MOD + solveRec(total, i+1, res)%MOD)%MOD;

	    return ans1;
	    
	    
	}

int main()
{
    int n;
    cin>>n;
    cout << solveRec(2*n, 0, 0) << endl;
    return 0;
}
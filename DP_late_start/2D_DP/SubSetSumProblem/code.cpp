#include <bits/stdc++.h>
using namespace std;

// recursion Approach
bool solveRec(vector<int> &arr, int sum, int index, vector<int>& subset)
{

    // base case -:     
    // 1.) jb sum zero aagay ho kisi intermediate recursive call
    if (sum == 0)
    {
        return true;
    }
    // 2.)jb ek hi element bach ho,
    if (index == 0)
    {
        if ((abs(sum - arr[index])) == 0){
            subset.push_back(arr[index]);
            return true;
        }
        else
            return false;
    }

    bool include = false;
    if (arr[index] <= sum)
    {
        subset.push_back(arr[index]);//pushing the selected element in subset vector
        include = solveRec(arr, sum - arr[index], index - 1, subset);

        if(!include)//if solution does'nt exist, then popping the elements which were previously inserted
        subset.pop_back();
    }

    // excluding case, sum change nhi hoga it will remain same
    // below we will only make the call to excluding case, If from above inclusion we get False answer
    bool exclude = include || solveRec(arr, sum, index - 1, subset);

    return exclude;
}

    //DP lgaoo ab isme
    //Subproblem Dikhrii hai kya???
    //mere pe agar n elements bachey ho aur Sum mera K ho toh vo possible hoga solve krna ya nhi,
    //this will Overlapping Subproblem, Mujhe isse hi solve krna hai
    
    //2D hogi ya fir 1D??? -> Over the recursive calls ek sum ka variable change hora hia aur index ka 
    //variable bhi change hora hai
    //So 2-D hi hogii DP
    
int solveMem(vector<int>& arr, int sum, int index, vector<vector<int>>& dp){
        
        //Memoization mein base case ko mt hila
        //base case
        if( sum == 0 ){
            // dp[index][sum] = 1;
            return 1;
        }
        
        //base case
        //2.) jb ek hi element bacha ho,
        if(index==0){
            if(abs(sum-arr[index])==0){
                // dp[index][sum] = 1;
            return 1;
            }
            else {
                // dp[index][sum] = 0;
                return 0;}
        }
        
        //step2.) check if anser is present
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        bool include = false;
        if( arr[index] <= sum ){
            include = solveMem(arr, sum-arr[index], index-1, dp);
        }

        //excluding, sum change nhi hoga it will remain same
        bool exclude = include || solveMem(arr, sum, index-1, dp);
        
        // bool ans = (include || exclude);
        //step3.) Store the value
        dp[index][sum] = exclude;
        return dp[index][sum];
        
    }


bool isSubsetSum(vector<int> arr, int sum, vector<int>& subset)
{
    // code here
        int n = arr.size();
        
        //Recursion + Memoization---> TOP-DOWN Approach
        //Step1.) Declare the 2D-DPvector
        vector<vector<int>> dp(n/*elements*/, vector<int>(sum+1, -1));
        // return solveRec(arr, sum, n);
        return solveMem(arr, sum, n-1, dp)==1?true:false;
}


int main()
{

    int N, sum;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    vector<int> subset;
    cout << isSubsetSum(arr, sum, subset) << endl;

    //printing the desired Subset
    for(int i = 0 ; i < subset.size(); i++)	{
        cout<<subset[i]<<" ";
    }

    return 0;
}
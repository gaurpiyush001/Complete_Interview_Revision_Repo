//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/


class Solution {
public:
    
    int solve(vector<int>& nums1,  vector<int>& nums2, int index, bool swapped){
        
        if( index == nums1.size() ){
            return 0;
        }
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //if we have to swap previous element
        if(swapped)
            swap(prev1, prev2);
        
        //No Swap --> if sequence is alreadyb in strictly increasing
        if( nums1[index] > prev1 && nums2[index] > prev2 )
            ans = solve(nums1, nums2, index+1, 0);
        
        //swap, If they are not in strictly incrreasing order
        if( nums1[index] > prev2 && nums2[index] > prev1 ){ // ---> Important Catch
            ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));
        }
        
        return ans;
        
    }
    
    
    int solveMem(vector<int>& nums1,  vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp){
        
        if( index == nums1.size() ){
            return 0;
        }
        
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //if we have to swap previous element
        if(swapped)
            swap(prev1, prev2);
        
        //No Swap --> if sequence is alreadyb in strictly increasing
        if( nums1[index] > prev1 && nums2[index] > prev2 )
            ans = solveMem(nums1, nums2, index+1, 0, dp);
        
        //swap, If they are not in strictly incrreasing order
        if( nums1[index] > prev2 && nums2[index] > prev1 ){ // ---> Important Catch
            ans = min(ans, 1 + solveMem(nums1, nums2, index+1, 1, dp));
        }
        
        return dp[index][swapped] = ans;
        
    }
    
    // ---> This is Wrong Tabulsation code 
    int solveTab(vector<int>& nums1,  vector<int>& nums2){
        
        int n = nums1.size();
        vector<vector<int>> dp( n+1, vector<int>(2, 0) );
        
        //base case
        dp[n][0] = 0;
        dp[n][1] = 0;
        int swapped = 0;
        
        for(int index = n-1; index >=0; index--){
            
            for(int swapped = 1; swapped >= 0; swapped--){
            
                // int swapped = 0;
                int ans = INT_MAX;

                int next1 = nums1[index+1];
                int next2 = nums2[index+1];

                //if we have to swap previous element
                if(swapped)
                    swap(next1, next2);

                //No Swap --> if sequence is alreadyb in strictly increasing
                if( nums1[index] < next1 && nums2[index] < next2 )
                    ans = dp[index+1][0];

                //swap, If they are not in strictly incrreasing order
                if( nums1[index] < next2 && nums2[index] < next1 ){ // ---> Important Catch
                    ans = min(ans, 1 + dp[index+1][1]);
                }
            
                dp[index][swapped] = ans;
            
            }
            
            
        }
        
        return dp[0][0];
        
    }
    
    
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        // nums1.insert(nums1.begin(), -1);
        // nums2.insert(nums2.begin(), -1);
        
        //it means current previous element has been swapped
        bool swapped = 0;
        // return solve(nums1, nums2, 1, swapped);
        
        //by memoization
        // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        // return solveMem(nums1, nums2, 1, swapped, dp);
        
        //By tAB
        nums1.insert(nums1.end(), INT_MAX);
        nums2.insert(nums2.end(), INT_MAX);
        
        return solveTab(nums1, nums2);
        
    }
};
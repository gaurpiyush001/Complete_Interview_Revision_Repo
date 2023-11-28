#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums){

    int n = nums.size();
    int subset_ct = (1<<n) - 1;
    vector<vector<int>> subsets;

    for(int mask = 0; mask <= subset_ct; mask++){

        vector<int> subset;
        for(int i = 0 ; i < n; i++) {
            if( ( mask & (1<<i) ) ){
                subset.push_back(nums[i]);
            }
        }

        subsets.push_back(subset);

    }

    //T.C -> n * 2^n
    //but recursion se krey toh --> 2^n hai sirf

    return subsets;

}


int main()
{
    


    return 0;
}
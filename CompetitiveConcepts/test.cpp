#include<bits/stdc++.h>
using namespace std;

// long long int Solution(vector<int> arr, int n, int k, int i , int j) {

// 	if(k==0){
// 		long long int sum = 0;
// 		while(i<=j){
// 			sum += arr[i];
// 			i++;
// 		}
// 		return sum;
// 	}

// 	//2 cases

// 	//take first two elements
// 	long long int ans1 = Solution(arr, n, k-1, i+2, j);

// 	//delete max
// 	long long int ans2 = Solution(arr, n, k-1, i, j-1);

// 	return max(ans1, ans2);	


// }

long long int SolutionMemo(vector<int>& arr, int n, int k, int i , int j, vector<vector<vector<long long int>>>& dp, long long int sum){

	if(k==0){
		return sum;
	}
	if(dp[k][i][j]!=-1){
		return dp[k][i][j];
	}

	//2 cases

	//take first two elements
	long long int ans1 = SolutionMemo(arr, n, k-1, i+2, j, dp+);

	//delete max
	long long int ans2 = SolutionMemo(arr, n, k-1, i, j-1, dp);

	return dp[k][i][j] = max(ans1, ans2);	


}



int main(){

	int t;
	cin>>t;

	while(t--){

		int n, k;

		cin>>n>>k;

		vector<int> arr(n);

		for(int i = 0 ; i < n; i++){
			cin>>arr[i];
		}

		sort(arr.begin(),arr.end());
		int i = 0, j = n-1;

		// cout << Solution(arr, n, k, i, j) << endl;
        long long int sum = 0; 
		vector<vector<vector<long long int>>> dp(k, vector<vector<long long int>>(n, vector<long long int>(n, -1)));
		// vector<vector<vector<int>>> v(n, vector<vector<int>>(m,vector<int>(m,-1)));
		cout << SolutionMemo(arr, n, k, i, j, dp, sum) << endl;

	}

}
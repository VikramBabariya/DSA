#include <bits/stdc++.h>

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int k = 0;
	for(auto i : arr) k += i; // total sum
	
	vector<vector<bool>> dp(n, vector<bool>(k+1, false));
	for(int i = 0; i < n; i++){
		dp[i][0] = true;
	}
	if(arr[0] <= k) dp[0][arr[0]] = true;
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= k; j++){
			bool notTake = dp[i-1][j];
			bool take = false;
			if(arr[i] <= j){
				take = dp[i-1][j-arr[i]];
			}
			
			dp[i][j] = take || notTake;
		}
	}
    int mini = INT_MAX;
	for(int s1 = 0; s1 <= k/2; s1++){
		if(dp[n-1][s1]){
			int s2 = k - s1;
			mini = min(mini, abs(s2 - s1));
		}
	}
	return mini;
}

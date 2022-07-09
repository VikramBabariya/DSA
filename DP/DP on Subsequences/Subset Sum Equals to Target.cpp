#include <bits/stdc++.h>

bool isPos(int ind, int t, vector<vector<int>> &dp, vector<int> &arr, int n){
	if(t == 0) return true;
	if(ind<0) return false;
	
	if(dp[ind][t] != -1) return dp[ind][t];
	dp[ind][t] = false;
	if(arr[ind] <= t){
		dp[ind][t] = isPos(ind-1, t - arr[ind], dp, arr, n);
	}
	if(dp[ind][t]) return true;
	return dp[ind][t] = isPos(ind-1, t , dp, arr, n);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
   return isPos(n-1, k, dp, arr, n);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]];
			}
			if(!dp[i][j])
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][k];
}

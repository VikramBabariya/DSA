#include<bits/stdc++.h>

bool solve(vector<int> &arr, vector<vector<int>> &dp, int ind, int target){
	if(target == 0) return true;
	if(ind == 0) return (arr[0] == target);
	
	if(dp[ind][target] != -1) return dp[ind][target];
	
	bool notTake = solve(arr, dp, ind-1, target);
	bool take = false;
	if(target >= arr[ind])
		take = solve(arr, dp, ind-1, target-arr[ind]);
	
	return dp[ind][target] = take || notTake;
}

bool canPartition(vector<int> &arr, int n)
{
	int total = 0;
	for(auto e : arr) total += e;
	if(total % 2 == 1) return false;
	
	int target = total/2;
	vector<vector<int>> dp(n, vector<int>(target+1, -1));
	return solve(arr, dp, n-1, target);
}

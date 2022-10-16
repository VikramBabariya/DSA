// we can also have 3d dp approach - i, buy, cap
#include<bits/stdc++.h>

int maxProfit(int i, int tran, vector<int>& prices, int n, int k, vector<vector<int>> &dp){
	if(i == n || tran == 2*k) return 0;
	
	if(dp[i][tran] != -1) return dp[i][tran];
	
	if(tran%2==0){
		int buying = -prices[i] + maxProfit(i+1, tran+1, prices, n, k, dp);
		int notBuying = maxProfit(i+1, tran, prices, n, k, dp);
		return dp[i][tran] = max(buying, notBuying);
	}else{
		int selling = prices[i] + maxProfit(i+1, tran+1, prices, n, k, dp);
		int notSelling = maxProfit(i+1, tran, prices, n, k, dp);
		return dp[i][tran] = max(selling, notSelling);
	}
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
	return maxProfit(0, 0, prices, n, k, dp);
}

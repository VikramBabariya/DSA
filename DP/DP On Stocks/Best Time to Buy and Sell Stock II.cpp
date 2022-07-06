#include<bits/stdc++.h>

long maxProfit(int i, bool buy, long *prices, int n, vector<vector<long>> &dp){
	if(i == n) return 0;
	
	if(dp[i][buy] != -1) return dp[i][buy];
	
	if(buy){
		long buying = -prices[i] + maxProfit(i+1, 0, prices, n, dp);
		long notBuying = maxProfit(i+1, 1, prices, n, dp);
		return dp[i][buy] = max(buying, notBuying);
	}else{
		long selling = prices[i] + maxProfit(i+1, 1, prices, n, dp);
		long notSelling = maxProfit(i+1, 0, prices, n, dp);
		return dp[i][buy] = max(selling, notSelling);
	}
}

long getMaximumProfit(long *prices, int n)
{
	vector<vector<long>> dp(n+1, vector<long>(2, 0));
	
	for(int i = n-1; i >= 0; i--){
		for(int buy = 0 ; buy <= 1; buy++){
			if(buy){
				long buying = -prices[i] + dp[i+1][0]; 
				long notBuying = dp[i+1][1];  
				dp[i][buy] = max(buying, notBuying);
			}else{
				long selling = prices[i] + dp[i+1][1];  
				long notSelling = dp[i+1][0];  
				dp[i][buy] = max(selling, notSelling);
			}
		}
	}
	return dp[0][1];
//     return maxProfit(0, 1, prices, n, dp);
}

#include<bits/stdc++.h>

int maxProfit(int i, bool buy, vector<int> &prices, int n, vector<vector<int>> &dp){
  if(i >= n) return 0;

  if(dp[i][buy] != -1) return dp[i][buy];

  if(buy){
    int buying = -prices[i] + maxProfit(i+1, 0, prices, n, dp);
    int notBuying = maxProfit(i+1, 1, prices, n, dp);
    return dp[i][buy] = max(buying, notBuying);
  }else{
    int selling = prices[i] + maxProfit(i+2, 1, prices, n, dp);
    int notSelling = maxProfit(i+1, 0, prices, n, dp);
    return dp[i][buy] = max(selling, notSelling);
  }
}

int stockProfit(vector<int> &prices){
	int n = prices.size();
	vector<vector<int>> dp(n+2, vector<int>(2, 0));
	
	for(int i = n-1; i >= 0; i--){
		for(int buy = 0 ; buy <= 1; buy++){
			if(buy){
				int buying = -prices[i] + dp[i+1][0]; 
				int notBuying = dp[i+1][1];  
				dp[i][buy] = max(buying, notBuying);
			}else{
				int selling = prices[i] + dp[i+2][1];  
				int notSelling = dp[i+1][0];  
				dp[i][buy] = max(selling, notSelling);
			}
		}
	}
	return dp[0][1];
}

int maxHelp(int i, int j, vector<int>& a, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        int coins = a[i-1] * a[ind] * a[j+1] + maxHelp(i, ind-1, a, dp)
                    + maxHelp(ind+1, j, a, dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int>& a)
{
    int n = a.size();
	  a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return maxHelp(1, n, a, dp);
}

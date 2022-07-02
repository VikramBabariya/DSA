
int count(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
	if(j < 0) return 1;
	if(i < 0) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(s1[i] == s2[j]){
		return dp[i][j] = count(i-1, j-1, s1, s2, dp) + count(i-1, j, s1, s2, dp);
	}else{
		return dp[i][j] = count(i-1, j, s1, s2, dp);
	}
}

int subsequenceCounting(string &s1, string &s2, int n1, int n2) {
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	for(int i = 0; i < n1; i++) dp[i][0] = 1;
	
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n1][n2];
//     return count(n1-1, n2-1, s1, s2, dp);
} 

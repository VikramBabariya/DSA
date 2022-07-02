#include<bits/stdc++.h>

bool isMatch(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
	if(i < 0 && j < 0) return true;
	if(i < 0 && j >= 0) return false;
	if(j < 0 && i >= 0){
		for(int it = i; it >= 0; it--)
			if(s1[it] != '*') return false;
		return true;
	}
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(s1[i] == s2[j] || s1[i] == '?')
		return dp[i][j] = isMatch(i-1, j-1, s1, s2, dp);
	if(s1[i] == '*')
		return dp[i][j] = isMatch(i-1, j, s1, s2, dp) || isMatch(i, j-1, s1, s2, dp);
	return dp[i][j] = false;
}

bool wildcardMatching(string s1, string s2)
{
   	int n1 = s1.size(), n2 = s2.size();
	vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
	
	dp[0][0] = true;
	for(int i = 1; i <= n1; i++){
		if(s1[i-1] != '*') break;
		dp[i][0] = true;
	}
	
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
				dp[i][j] = dp[i-1][j-1]; 
			else if(s1[i-1] == '*')
				dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
			else dp[i][j] = false;
		}
	}
	return dp[n1][n2];

// 	return isMatch(n1-1, n2-1, s1, s2, dp);
}

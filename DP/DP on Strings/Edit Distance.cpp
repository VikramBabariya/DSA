#include<bits/stdc++.h>

int minOp(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
	if(i < 0) return j+1;
	if(j < 0) return i+1;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(s1[i] == s2[j]) return dp[i][j] = minOp(i-1, j-1, s1, s2, dp);
	
	int in = 1 + minOp(i, j-1, s1, s2, dp);
	int del = 1 + minOp(i-1, j, s1, s2, dp);
	int rep = 1 + minOp(i-1, j-1, s1, s2, dp);
	int min1 = min(in, del);
	return dp[i][j] = min(min1, rep);
}


int editDistance(string s1, string s2)
{
	int n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	for(int i = 0; i <= n1; i++) dp[i][0] = i;
	for(int j = 0; j <= n2; j++) dp[0][j] = j;
	
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]; 
			else{
				int in = 1 + dp[i][j-1]; 
				int del = 1 + dp[i-1][j]; 
				int rep = 1 + dp[i-1][j-1]; 
				int min1 = min(in, del);
				dp[i][j] = min(min1, rep);
			}
		}
	}
	return dp[n1][n2];

//     return minOp(n1-1, n2-1, s1, s2, dp);
}

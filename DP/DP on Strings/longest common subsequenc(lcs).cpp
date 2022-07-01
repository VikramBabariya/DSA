#include<bits/stdc++.h>

int lcsHelp(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
	if(ind1 < 0 || ind2 < 0) return 0;
	
	if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	
	if(s1[ind1] == s2[ind2]){
		return dp[ind1][ind2] = 1 + lcsHelp(ind1-1, ind2-1, s1, s2, dp);
	}
	
	int pos1 = lcsHelp(ind1-1, ind2, s1, s2, dp);
	int pos2 = lcsHelp(ind1, ind2-1, s1, s2, dp);
	
	return dp[ind1][ind2] = max(pos1, pos2);
}

int lcs(string s1, string s2)
{
	int n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	for(int ind1 = 1; ind1 <= n1; ind1++){
		for(int ind2 = 1; ind2 <= n2; ind2++){
			if(s1[ind1-1] == s2[ind2-1]){  // bug : dp - 1 base | sring - 0 base
				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1]; 
			}else{
				int pos1 = dp[ind1-1][ind2]; 
				int pos2 = dp[ind1][ind2-1];
				dp[ind1][ind2] = max(pos1, pos2);
			}
		}
	}
// ------------- printing lcs ---------	
// 	string ans;
// 	for(int i = n1, j = n2; i > 0 && j > 0; ){
// 		if(dp[i][j] == dp[i][j-1]) j--;
// 		else if(dp[i][j] == dp[i-1][j]) i--;
// 		else{
// 			ans.push_back(s1[i-1]);
// 			i--;
// 			j--;
// 		}
// 	}
// 	reverse(ans.begin(), ans.end());
// 	cout<<ans<<endl;
	return dp[n1][n2];
// 	return lcsHelp(n1-1, n2-1, s1, s2, dp);
}

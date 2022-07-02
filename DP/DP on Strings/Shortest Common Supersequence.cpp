#include<bits/stdc++.h>
string shortestSupersequence(string s1, string s2)
{
	int n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	// finding lcs
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
// ------------- printing scs ---------	
	string ans;
	int i, j;
	for(i = n1, j = n2; i > 0 && j > 0; ){
		if(dp[i][j] == dp[i][j-1]){ 
			ans.push_back(s2[j-1]);
			j--;
		}else if(dp[i][j] == dp[i-1][j]){
			ans.push_back(s1[i-1]);
			i--;
		}else{
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
	}
	while(i > 0){
		ans.push_back(s1[i-1]);
		i--;
	}
	while(j > 0){
		ans.push_back(s2[j-1]);
		j--;
	}
	reverse(ans.begin(), ans.end());
// 	cout<<ans<<endl;
	return ans;
}

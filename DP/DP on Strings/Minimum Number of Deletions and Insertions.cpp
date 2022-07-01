#include<bits/stdc++.h>
int canYouMake(string &s1, string &s2)
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
	
	int lcs = dp[n1][n2];
	int ins = n2 - lcs, del = n1 - lcs;
	return (ins + del);
}

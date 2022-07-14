#include<bits/stdc++.h>

bool comp(string s1, string s2){
	return s1.size() < s2.size();
}

bool compare(string s1, string s2){
	if(s1.size() != s2.size() + 1) return false;
	int i = 0, j = 0;
	while(i < s1.size()){
		if(s1[i] == s2[j]){
			i++;
			j++;
		}else{
			i++;
		}
	}
	return i == s1.size() && j == s2.size(); 
}

int longestStrChain(vector<string> &arr)
{
	int n = arr.size();
	sort(arr.begin(), arr.end(), comp);
	
    vector<int> dp(n, 1);
	int maxi = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(compare(arr[i], arr[j]) && (1 + dp[j] > dp[i])){
				dp[i] = 1 + dp[j];
			}
		}
		if(dp[i] > dp[maxi])
			maxi = i;
	}
	
	return dp[maxi];
}

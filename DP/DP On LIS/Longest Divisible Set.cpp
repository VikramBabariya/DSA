#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	
    vector<int> dp(n, 1);
	vector<int> prev(n);
	int maxi = 0;
	for(int i = 0; i < n; i++){
		prev[i] = i;
		for(int j = 0; j < i; j++){
			if(arr[i] % arr[j] == 0 && (1 + dp[j] > dp[i])){
				prev[i] = j;
				dp[i] = 1 + dp[j];
			}
		}
		if(dp[i] > dp[maxi])
			maxi = i;
	}
	vector<int> lds;
	int it = maxi;
	while(1){
		lds.push_back(arr[it]);
		if(prev[it] == it) break;
		it = prev[it];
	}
	reverse(lds.begin(), lds.end());
	return lds;
}

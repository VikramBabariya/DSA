// tabulation approach

int longestIncreasingSubsequence(int arr[], int n)
{
	vector<int> dp(n, 1);
	vector<int> prev(n);
	int maxi = 0;
	for(int i = 0; i < n; i++){
		prev[i] = i;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && (1 + dp[j] > dp[i])){
				prev[i] = j;
				dp[i] = 1 + dp[j];
			}
		}
		if(dp[i] > dp[maxi])
			maxi = i;
	}
	
	//printing lis
	vector<int> lis;
	int it = maxi;
	while(1){
		lis.push_back(arr[it]);
		if(prev[it] == it) break;
		it = prev[it];
	}
	reverse(lis.begin(), lis.end());
	for(auto e : lis) cout<<e<<" ";
	cout<<endl<<lis.size()<<endl;
	return dp[maxi];
}

// binary search(lower bound)
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
	temp.push_back(arr[0]);
	for(int i = 1; i < n; i++){
		if(arr[i] > temp.back()){
			temp.push_back(arr[i]);
		}else{
			int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			temp[ind] = arr[i];
		}
	}
	return temp.size();
}


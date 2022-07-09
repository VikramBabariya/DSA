#include <bits/stdc++.h>

int maxPoints(int day, int lastActivity, vector<vector<int>> &dp, vector<vector<int>> &points, int n){
	if(day == 0){
		int maxi = INT_MIN;
		for(int i = 0; i <= 2; i++){
			if(i != lastActivity) maxi = max(points[0][i], maxi);
		}
		return maxi;	
	}
	
	if(dp[day][lastActivity] != -1) return dp[day][lastActivity];
	
	int maxi = INT_MIN;
	for(int i = 0; i <= 2; i++){
		if(i != lastActivity){
			int point = points[day][i] + maxPoints(day-1, i, dp, points, n);
			maxi = max(maxi, point);
		}
	}
	return dp[day][lastActivity] = maxi;
	
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(n, vector<int>(4, -1));
   return maxPoints(n-1, 3, dp, points, n);
}
